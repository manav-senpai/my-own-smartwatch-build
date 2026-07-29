#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

// I2C pins for ESP32-C3 Super Mini
#define I2C_SDA 4
#define I2C_SCL 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize I2C with ESP32-C3 Super Mini pins
  Wire.begin(I2C_SDA, I2C_SCL);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.display();
}

void drawStar(int x, int y, int size, bool glow) {
  if (!glow) return;
  if (size == 1) {
    display.drawPixel(x, y, SSD1306_WHITE);
  } else {
    display.drawPixel(x, y, SSD1306_WHITE);
    display.drawPixel(x - 1, y, SSD1306_WHITE);
    display.drawPixel(x + 1, y, SSD1306_WHITE);
    display.drawPixel(x, y - 1, SSD1306_WHITE);
    display.drawPixel(x, y + 1, SSD1306_WHITE);
  }
}

void loop() {
  display.clearDisplay();

  unsigned long ms = millis();

  // 1. Draw Twinkling Stars in the Background
  bool starGlow1 = (ms / 300) % 2 == 0;
  bool starGlow2 = (ms / 450) % 2 == 0;
  bool starGlow3 = (ms / 600) % 2 == 0;
  bool starGlow4 = (ms / 200) % 3 != 0;

  drawStar(15, 12, 3, starGlow1);   // Top left star
  drawStar(112, 18, 3, starGlow2);  // Top right star
  drawStar(25, 45, 1, starGlow3);   // Mid left star
  drawStar(105, 48, 1, starGlow4);  // Mid right star

  // 2. Calculations for Cat Animation
  // Breathing offset (moves body/head up and down slowly)
  float breathing = sin(ms * 0.003) * 0.8;
  
  // Blinking eyes logic (blink for 150ms every 3.5 seconds)
  bool isBlinking = (ms % 3500) < 150;
  
  // Tail wagging angles (smooth sine wave progression)
  float tailAngle1 = 0.2 + sin(ms * 0.005) * 0.4;
  float tailAngle2 = tailAngle1 + sin(ms * 0.01 + 0.5) * 0.5;

  // Whiskers twitching offset
  float whiskerTwitch = sin(ms * 0.015) * 0.8;

  // 3. Draw Cat Tail
  int tailBaseX = 76;
  int tailBaseY = 48 + breathing;
  int len1 = 12;
  int len2 = 10;

  int x1 = tailBaseX + cos(tailAngle1) * len1;
  int y1 = tailBaseY - sin(tailAngle1) * len1;
  int x2 = x1 + cos(tailAngle2) * len2;
  int y2 = y1 - sin(tailAngle2) * len2;

  // Draw tail segments
  display.drawLine(tailBaseX, tailBaseY, x1, y1, SSD1306_WHITE);
  display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
  display.fillCircle(x1, y1, 1, SSD1306_WHITE); // Tail joint
  display.fillCircle(x2, y2, 2, SSD1306_WHITE); // Fluffy tail tip

  // 4. Draw Cat Body
  // Body center base Y = 38
  display.fillRoundRect(46, 36 + breathing, 32, 24, 8, SSD1306_WHITE);
  // Negative space to separate legs/shoulders slightly
  display.drawRoundRect(46, 36 + breathing, 32, 24, 8, SSD1306_BLACK);

  // 5. Draw Paws
  display.fillRoundRect(50, 58 + breathing, 6, 4, 2, SSD1306_WHITE);
  display.fillRoundRect(68, 58 + breathing, 6, 4, 2, SSD1306_WHITE);

  // 6. Draw Cat Head
  int headX = 62;
  int headY = 24 + breathing;
  int headRad = 13;

  // Clear head area so body doesn't overlap details
  display.fillCircle(headX, headY, headRad, SSD1306_BLACK);
  display.drawCircle(headX, headY, headRad, SSD1306_WHITE);

  // 7. Draw Cat Ears
  // Left Ear
  int leX1 = headX - 10;
  int leY1 = headY - 8;
  int leX2 = headX - 14;
  int leY2 = headY - 20;
  int leX3 = headX - 3;
  int leY3 = headY - 12;
  display.fillTriangle(leX1, leY1, leX2, leY2, leX3, leY3, SSD1306_BLACK);
  display.drawTriangle(leX1, leY1, leX2, leY2, leX3, leY3, SSD1306_WHITE);

  // Right Ear
  int reX1 = headX + 10;
  int reY1 = headY - 8;
  int reX2 = headX + 14;
  int reY2 = headY - 20;
  int reX3 = headX + 3;
  int reY3 = headY - 12;
  display.fillTriangle(reX1, reY1, reX2, reY2, reX3, reY3, SSD1306_BLACK);
  display.drawTriangle(reX1, reY1, reX2, reY2, reX3, reY3, SSD1306_WHITE);

  // 8. Draw Eyes
  int eyeLY = headY - 2;
  int eyeRY = headY - 2;
  int eyeLX = headX - 5;
  int eyeRX = headX + 5;

  if (isBlinking) {
    // Draw flat blinking lines
    display.drawLine(eyeLX - 2, eyeLY, eyeLX + 2, eyeLY, SSD1306_WHITE);
    display.drawLine(eyeRX - 2, eyeRY, eyeRX + 2, eyeRY, SSD1306_WHITE);
  } else {
    // Draw open cute eyes (filled circles with highlight if possible)
    display.fillCircle(eyeLX, eyeLY, 2, SSD1306_WHITE);
    display.fillCircle(eyeRX, eyeRY, 2, SSD1306_WHITE);
    display.drawPixel(eyeLX, eyeLY - 1, SSD1306_BLACK); // Tiny reflection
    display.drawPixel(eyeRX, eyeRY - 1, SSD1306_BLACK); // Tiny reflection
  }

  // 9. Draw Nose & Mouth
  display.fillTriangle(headX, headY + 2, headX - 1, headY + 1, headX + 1, headY + 1, SSD1306_WHITE); // Nose
  display.drawLine(headX, headY + 2, headX - 1, headY + 3, SSD1306_WHITE); // Mouth Left
  display.drawLine(headX, headY + 2, headX + 1, headY + 3, SSD1306_WHITE); // Mouth Right

  // 10. Draw Whiskers
  // Left Whiskers
  display.drawLine(headX - 11, headY + 2, headX - 22, headY + 1 + whiskerTwitch, SSD1306_WHITE);
  display.drawLine(headX - 11, headY + 4, headX - 21, headY + 6 - whiskerTwitch, SSD1306_WHITE);
  // Right Whiskers
  display.drawLine(headX + 11, headY + 2, headX + 22, headY + 1 - whiskerTwitch, SSD1306_WHITE);
  display.drawLine(headX + 11, headY + 4, headX + 21, headY + 6 + whiskerTwitch, SSD1306_WHITE);

  // 11. Optional Caption
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(3, 54);
  display.print(F("NEKO OS"));

  display.display();
  delay(30); // ~30 FPS animation speed
}
