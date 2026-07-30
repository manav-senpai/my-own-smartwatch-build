# ESP32-C3 Watch & Animation Ecosystem

Welcome to the **ESP32-C3 Watch** project suite! This repository houses a collection of ESP32-C3 based firmware sketches designed to drive a compact 0.96" SSD1306 OLED display, host web servers, and animate interactive assets. 

---

## 📂 Repository Structure

The project is structured into modular sketch folders, each highlighting a distinct capability of the ESP32-C3 platform:

*   **[ayane_portal](file:///d:/DESKTOP/watch/ayane_portal)**: A Captive Portal implementation. When powered, the board broadcasts an open Wi-Fi network named **"ayane"**. Connecting to it redirects any device to a custom, beautifully formatted portfolio/resume landing page hosted locally on the ESP32-C3 (`http://192.168.4.1/`).
*   **[robotic_eyes](file:///d:/DESKTOP/watch/robotic_eyes)**: A sophisticated, state-driven animated eyes expression engine. It renders two responsive robotic eyes on the OLED screen with smooth LERP (interpolation) transitions, blinking, saccades (random eye movements), screen shake effects (in the angry state), and a sleepy Zzz floating text animation.
*   **[cat_animation](file:///d:/DESKTOP/watch/cat_animation)**: A placeholder workspace set aside for custom cat character animations.
*   **[test](file:///d:/DESKTOP/watch/test)**: A diagnostics test sketch to verify OLED screen wiring, displaying centered text (**"Mundane Mann"**) on the screen.
*   **[connections.md](file:///d:/DESKTOP/watch/connections.md)**: The hardware specification file detailing safe GPIO selections, wiring tables (I2C/SPI), power requirements, and IDE settings.

---

## 🔌 Hardware Connections (I2C)

The standard configuration utilizes a **0.96-inch OLED screen (SSD1306)** communicating over the I2C protocol. Due to the tiny form factor of the **ESP32-C3 Super Mini**, we avoid conflicting strapping/LED pins (like GPIO 8 and 9) and route communication through:

| OLED Pin | ESP32-C3 Super Mini Pin | Description |
| :--- | :--- | :--- |
| **GND** | **GND** | Ground reference |
| **VCC** | **3V3** | Power supply (3.3V) |
| **SDA** (or **SDI**) | **GPIO 4** | Serial Data Line |
| **SCK** (or **SCL**) | **GPIO 5** | Serial Clock Line |

> [!NOTE]
> Detailed pinouts, including alternative **7-Pin SPI Display Connections**, can be found in the [connections.md](file:///d:/DESKTOP/watch/connections.md) guide.

---

## 🛠️ Software Setup

To flash any of the projects to your ESP32-C3 Super Mini:

1.  **Arduino IDE Setup**:
    *   Add the Espressif Board Manager URL under Preferences:
        `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
    *   Install the **esp32** boards via Tools > Board > Boards Manager.
    *   Select **ESP32C3 Dev Module** as your target board.
2.  **Install Libraries**:
    *   Open the Library Manager and install **Adafruit SSD1306** (install all dependencies like **Adafruit GFX** when prompted).
3.  **Flash**:
    *   Select the correct COM port and click Upload.
    *   *Tip:* If the IDE fails to upload, force the chip into download mode by holding the **BOOT** button, pressing **EN (Reset)** once, and releasing **BOOT**.

---

## 🤖 Controlling the Robotic Eyes

The [robotic_eyes](file:///d:/DESKTOP/watch/robotic_eyes) project includes an interactive Serial interface. Open the Serial Monitor at **115200 Baud** and send any of the following text commands to dynamically change the expression state:

*   `neutral`: Calm, looking around naturally.
*   `happy`: Crescent-shaped smiling eyes with a happy vertical jiggle.
*   `angry`: Aggressively slanted eyes with screen vibration.
*   `sad`: Drooping slanted eyes with slow breathing.
*   `surprised`: Wide, circular dilated eyes.
*   `confused`: Asymmetric squinting eyes.
*   `scan`: High-tech sweeping horizontal lines.
*   `sleep`: Thin sleeping lines with floating **"Zzz"** text.
*   `cycle`: Toggles auto-cycling through all expressions every 6 seconds.

---

## 🚀 Future Roadmap

As development on the watch ecosystem continues, the next milestones include:
1.  **Fleshing out `cat_animation`**: Implementation of sprite sheet or procedural cat face animations.
2.  **Captive Portal Integration**: Adding settings or customization options on the `ayane_portal` webpage to let users change the OLED display's expression or text from their smartphone.
3.  **Smartwatch Features**: Incorporating clock faces, BLE connectivity, and notification synchronization.
