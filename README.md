# 🚀 Arduino Distance Meter with OLED Display and LED Indicators

This project uses an **HC-SR04 ultrasonic sensor** and a **0.96" I2C OLED display (SSD1306)** to measure distance and display it in real time. It also uses three LEDs (Green, Yellow, Red) to visually indicate the distance range.

---

## 🎯 Features

- 🔍 Measures distance using an **ultrasonic sensor (HC-SR04)**
- 📺 Displays the distance in centimeters on a **128x64 OLED**
- 🟢🟡🔴 Uses 3 LEDs to indicate:
  - **Green** for safe distance (> 50 cm)
  - **Yellow** for medium range (20–50 cm)
  - **Red** for close/danger range (< 20 cm)

---

## 🧰 Components Used

| Component           | Quantity |
|---------------------|----------|
| Arduino UNO         | 1        |
| HC-SR04 Sensor      | 1        |
| OLED SSD1306 (I2C)  | 1        |
| Green LED           | 1        |
| Yellow LED          | 1        |
| Red LED             | 1        |
| 220Ω Resistors      | 3        |
| Jumper Wires        | Several  |
| Breadboard (optional) | 1      |

---

## 🔌 Pin Connections

| Module       | Arduino Pin |
|--------------|-------------|
| HC-SR04 TRIG | D9          |
| HC-SR04 ECHO | D8          |
| OLED SDA     | A4          |
| OLED SCL     | A5          |
| Green LED    | D3          |
| Yellow LED   | D4          |
| Red LED      | D5          |
| All LED GND  | GND (via resistor) |

---

## 🧪 How It Works

1. The ultrasonic sensor sends out a short sound pulse.
2. It measures the time taken for the echo to return.
3. The Arduino calculates the distance using the formula:


4. The distance is shown on the OLED screen.
5. LEDs change based on the measured distance:
- 🟢 Green: Safe (> 50 cm)
- 🟡 Yellow: Caution (20–50 cm)
- 🔴 Red: Danger (< 20 cm)

---

## 📦 Dependencies

Add the following to your `platformio.ini` file to include the required libraries:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino

lib_deps =
adafruit/Adafruit SSD1306 @ ^2.5.9
adafruit/Adafruit GFX Library @ ^1.11.9
---

🧠 Possible Extensions
🔊 Add a buzzer for audible alerts

📈 Log data to SD card

📐 Display distance in inches or meters

🤖 Attach a servo to react to distance

📶 Add wireless display via Bluetooth or WiFi (ESP32/ESP8266)



