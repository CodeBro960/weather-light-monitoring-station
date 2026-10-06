# weather-light-monitoring-station-
Embedded weather &amp; light monitor built with Elegoo Uno R3, BME280 (I2C), and an analog photoresistor voltage divider.
# Embedded Weather & Ambient Light Monitoring Station

An embedded environmental monitoring system engineered with an **Elegoo Uno R3** microcontroller. The station collects real-time atmospheric data (temperature, relative humidity, and barometric pressure) via an **I2C-based BME280 sensor** alongside ambient light levels using an **analog photoresistor voltage divider circuit**.

Designed and built as a personal engineering portfolio project demonstrating hardware interfacing, signal processing, and low-level protocol debugging.

---

## Technical Features

* **Multi-Sensor Interfacing:** Simultaneously processes digital I2C bus communications and continuous analog signal inputs.
* **Mixed Logic Power Rails:** Integrates dual-voltage peripherals safely—$3.3\text{V}$ regulated supply for the BME280 sensor and $5\text{V}$ supply for the analog photoresistor rail.
* **Analog Signal Mapping:** Implements a $10\text{k}\Omega$ pull-down resistor circuit to translate changing light resistance into calibrated $0\text{--}100\%$ ambient light levels.
* **Automatic Protocol Scanning:** Includes dual I2C address initialization (`0x76` and `0x77`) to ensure reliable hardware connection on system boot.

---

## Hardware Specifications & Component List

| Component | Quantity | Interface Protocol | Operating Voltage | Notes |
| :--- | :---: | :--- | :---: | :--- |
| **Elegoo Uno R3** | 1 | Microprocessor | $5\text{V}$ | ATmega328P board |
| **BME280 Sensor** | 1 | I2C (SDA / SCL) | $3.3\text{V}$ | Temperature, Humidity, Pressure |
| **Photoresistor (LDR)** | 1 | Analog (Pin A0) | $5\text{V}$ | Light intensity sensing |
| **$10\text{k}\Omega$ Resistor** | 1 | Passive Divider | — | Pull-down resistor for LDR circuit |
| **Breadboard & Jumpers** | — | Direct Wiring | — | Shared GND & 5V/3.3V power distribution |

---

## Circuit Wiring Schematic

### BME280 Connection (I2C)
> **CRITICAL:** The BME280 logic and power require **$3.3\text{V}$**. Connecting to $5\text{V}$ can damage the sensor module.

* `VIN` $\rightarrow$ **3.3V Pin** on Uno
* `GND` $\rightarrow$ **GND Rail**
* `SDA` $\rightarrow$ **Analog Pin A4** (or dedicated SDA pin)
* `SCL` $\rightarrow$ **Analog Pin A5** (or dedicated SCL pin)

### Photoresistor Voltage Divider
* **Leg 1 (LDR):** Connected directly to **5V Power Rail**
* **Leg 2 (LDR):** Connected to **Analog Pin A0** **AND** to **GND Rail** through a **$10\text{k}\Omega$ resistor**

---

## Software Dependencies & Libraries

To compile and run this project in the **Arduino IDE**, install the following libraries via the Library Manager (`Ctrl + Shift + I`):

1. `Adafruit BME280 Library` (by Adafruit)
2. `Adafruit Unified Sensor` (by Adafruit)
3. `Wire.h` (Built-in I2C library)

---

## Project Structure

```text
weather-light-monitoring-station/
├── README.md                  # Project overview and technical documentation
├── LICENSE                    # MIT Open-Source License
├── .gitignore                 # C++ / Arduino build artifacts ignore list
├── docs/                      # Circuit diagrams and setup photos
└── src/
    └── weather_station.ino    # Main C++ embedded source code
