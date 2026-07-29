#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins can be custom-defined for ESP32-C3
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D or 0x3C

// Define custom I2C pins for ESP32-C3 Super Mini.
// We recommend GPIO 4 (SDA) and GPIO 5 (SCL) because GPIO 18/19 are not
// broken out, and using GPIO 8/9 conflicts with the onboard LED and Boot pin.
#define I2C_SDA 4
#define I2C_SCL 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  delay(1000); // Give serial monitor time to connect
  Serial.println("ESP32-C3 OLED Test Started");

  // Initialize I2C with our custom pins
  Wire.begin(I2C_SDA, I2C_SCL);

  // Initialize the OLED display. SSD1306_SWITCHCAPVCC generates 3.3V internally.
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed. Check wiring and I2C address!"));
    // Loop forever if display initialization fails
    for(;;); 
  }

  Serial.println("SSD1306 display initialized successfully.");

  // Clear the buffer
  display.clearDisplay();

  // Set text size, color, and cursor position
  display.setTextSize(2);             // Text scale factor (2x size is easy to read)
  display.setTextColor(SSD1306_WHITE); // Draw white text
  
  // Center alignment calculation helper
  // "Mundane" is 7 chars. At size 2, each char is 12px wide (6px base * 2). Total width = 84px.
  // X offset for centering: (128 - 84) / 2 = 22
  display.setCursor(22, 16);
  display.println(F("Mundane"));
  
  // "Mann" is 4 chars. At size 2, total width = 48px.
  // X offset for centering: (128 - 48) / 2 = 40
  display.setCursor(40, 36);
  display.println(F("Mann"));

  // Send the buffer to the physical display
  display.display();
  Serial.println("Name displayed on OLED.");
}

void loop() {
  // Nothing to do in the main loop for this simple test
  delay(1000);
}
