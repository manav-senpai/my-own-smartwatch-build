# ESP32-C3 Super Mini to 0.96" OLED Display Connection Guide

This guide details the physical connections, power requirements, software setup, and flashing procedures to connect your ESP32-C3 Super Mini to a 0.96-inch OLED display.

---

## 1. Hardware Connections (Pinout)

The 0.96-inch OLED display is most commonly based on the **SSD1306** driver chip and uses the **I2C** interface (4 pins). Since the ESP32-C3 Super Mini has a compact form factor and does not break out GPIO 18 and GPIO 19, we use alternative pins.

### Recommended I2C Connections (4 Pins)

| OLED Pin | ESP32-C3 Super Mini Pin | Description |
| :--- | :--- | :--- |
| **GND** | **GND** | Ground reference |
| **VCC** | **3V3** | Power supply (3.3V logic safe) |
| **SDA** (or **SDI**) | **GPIO 4** | Serial Data Line |
| **SCK** (or **SCL**) | **GPIO 5** | Serial Clock Line |

> [!IMPORTANT]
> * **SCK is SCL:** On many OLED modules, the clock pin is labeled **SCK** (Serial Clock) instead of **SCL**. Similarly, the data pin may be labeled **SDI** instead of **SDA**. Connect **SCK** to **GPIO 5** and **SDA/SDI** to **GPIO 4**.
> * **Avoid GPIO 8 and 9:** Although GPIO 8 and 9 are default I2C pins for some ESP32-C3 modules, on the Super Mini, **GPIO 8** is connected to the onboard blue status LED and **GPIO 9** is the Boot Mode strapping pin. Using them for I2C can cause boot issues or conflict with the LED.
> * **GPIO 4 & 5:** These are safe, adjacent, and commonly used for I2C on the Super Mini.

---

### Option: SPI Display (7 Pins)

If your OLED has 7 pins (SPI), use the following mapping:

| OLED Pin | ESP32-C3 Pin | Description | Arduino Code Define |
| :--- | :--- | :--- | :--- |
| **GND** | **GND** | Ground reference | |
| **VCC** | **3V3** | Power supply | |
| **D0 (CLK)** | **GPIO 4** | SPI Clock | `OLED_CLK` |
| **D1 (MOSI)** | **GPIO 6** | SPI Data Out | `OLED_MOSI` |
| **RES (Reset)**| **GPIO 2** | Hardware Reset | `OLED_RESET` |
| **DC** | **GPIO 3** | Data / Command Selection | `OLED_DC` |
| **CS** | **GPIO 7** | Chip Select | `OLED_CS` |

---

## 2. Display Power Requirements

* **Operating Voltage:** **3.3V to 5V DC**.
  * The SSD1306 controller operates natively at **3.3V**.
  * Connecting to the **3.3V (3V3)** pin on the ESP32-C3 Super Mini is highly recommended to match the 3.3V logic level of the IO pins.
* **Current Consumption:**
  * **15mA to 25mA** depending on how many pixels are turned on.
  * Because it is highly efficient (each pixel is an individual LED and does not require a backlight), it can be powered directly from the ESP32-C3 module's 3V3 output pin.

---

## 3. Programming the ESP32-C3 Super Mini

To compile and flash the code to your board, you will need to set up the Arduino IDE.

### Step 1: Install ESP32 Board Support
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Open the IDE and navigate to **File > Preferences** (or **Arduino IDE > Settings** on macOS).
3. In **Additional boards manager URLs**, paste the following URL:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
4. Click **OK**.
5. Navigate to **Tools > Board > Boards Manager...**, search for `esp32`, and install the library by **Espressif Systems**.

### Step 2: Install OLED Libraries
1. In the Arduino IDE, navigate to **Sketch > Include Library > Manage Libraries...** (or click the Library Manager icon on the left sidebar).
2. Search for `Adafruit SSD1306` and install it (choose "Install All" when prompted to install dependencies like the `Adafruit GFX Library` and `Adafruit BusIO`).

### Step 3: Select Board & Port
1. Connect your ESP32-C3 Super Mini to your computer via USB.
2. Under **Tools > Board**, select **ESP32C3 Dev Module** (or your specific ESP32-C3 Dev Kit).
3. Under **Tools > Port**, select the COM port corresponding to your connected ESP32-C3.
4. **Flashing Issues:** If your board has trouble uploading, hold down the physical **BOOT (IO9)** button on the board, click the **Reset (EN)** button once, and release **BOOT** to force it into serial bootloader mode.

---

## 4. Test Code

The test sketch is located in [test.ino](file:///d:/DESKTOP/watch/test/test.ino). Flash it to display **"Mundane Mann"** on your screen.
