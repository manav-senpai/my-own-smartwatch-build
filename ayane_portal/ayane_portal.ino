#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include "index_html.h"

// Captive Portal configurations
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
DNSServer dnsServer;
WebServer server(80);

const char* ssid = "ayane";

// Serve the index/portfolio page
void handleRoot() {
  server.send(200, "text/html", portfolio_html);
}

// Redirect client to portal IP if requesting any other URL
void handleNotFound() {
  String host = server.hostHeader();
  if (host != "192.168.4.1" && host != "ayane.local") {
    Serial.printf("Captive redirect: client requested %s%s, redirecting to captive portal.\n", host.c_str(), server.uri().c_str());
    server.sendHeader("Location", "http://192.168.4.1/", true);
    server.send(302, "text/plain", "");
  } else {
    // If client requested a non-existent route on our IP directly, just serve the portfolio page
    handleRoot();
  }
}

void setup() {
  // Start serial console for diagnostic info
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n--- Ayane Resume Captive Portal Setup ---");

  // Configure ESP32 as an Access Point (AP)
  Serial.println("Configuring Access Point...");
  WiFi.mode(WIFI_AP);
  
  // Set up local IP range
  if (WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0))) {
    Serial.println("AP Configuration IP Success.");
  } else {
    Serial.println("AP Configuration IP Failed.");
  }
  
  // Start the AP with the name "ayane" and no password
  if (WiFi.softAP(ssid)) {
    Serial.printf("Access Point '%s' initialized successfully.\n", ssid);
    Serial.print("Local IP Address: ");
    Serial.println(WiFi.softAPIP());
  } else {
    Serial.println("Access Point initialization failed.");
  }

  // Start the DNS Server redirecting all domains to the AP IP
  Serial.println("Initializing DNS Server redirection (* -> 192.168.4.1)...");
  if (dnsServer.start(DNS_PORT, "*", apIP)) {
    Serial.println("DNS Server started successfully on port 53.");
  } else {
    Serial.println("DNS Server failed to start.");
  }

  // Define HTTP URL handlers
  server.on("/", handleRoot);
  server.on("/index.html", handleRoot);
  
  // Common endpoints requested by smartphones during captive portal connectivity checks:
  server.on("/generate_204", handleRoot);            // Android
  server.on("/hotspot-detect.html", handleRoot);     // iOS/macOS
  
  // Catch-all route to handle redirection
  server.onNotFound(handleNotFound);

  // Start the HTTP web server
  server.begin();
  Serial.println("HTTP Web Server running on port 80.");
  Serial.println("Waiting for devices to connect...");
}

void loop() {
  // Process DNS queries to redirect clients
  dnsServer.processNextRequest();
  
  // Process incoming web server HTTP requests
  server.handleClient();
  
  // Yield to allow background WiFi/TCP tasks to execute smoothly on the ESP32
  yield();
}
