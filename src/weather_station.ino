#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Define Analog Pin for Photoresistor
const int LIGHT_SENSOR_PIN = A0;

// Create BME280 object
Adafruit_BME280 bme; 

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10); // Wait for Serial Monitor

  Serial.println("==========================================");
  Serial.println("  Weather Station Hardware Test");
  Serial.println("  Sensing: BME280 + Photoresistor");
  Serial.println("==========================================");

  // Initialize BME280 (Checking I2C address 0x76 first, then 0x77)
  if (!bme.begin(0x76)) {
    Serial.println("Not found at address 0x76, trying 0x77...");
    if (!bme.begin(0x77)) {
      Serial.println("ERROR: Could not find BME280 sensor!");
      Serial.println("Check 3.3V power, GND, A4 (SDA), and A5 (SCL).");
      while (1); // Halt execution on failure
    }
  }

  Serial.println("BME280 Initialized Successfully!");
  Serial.println("Reading data every 2 seconds...\n");
}

void loop() {
  // 1. Read Photoresistor (Analog A0)
  int rawLight = analogRead(LIGHT_SENSOR_PIN);
  int lightPercent = map(rawLight, 0, 1023, 0, 100);

  // 2. Read BME280 Values
  float tempC = bme.readTemperature();
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F; // Convert Pa to hPa

  // 3. Print Results to Serial Monitor
  Serial.print("Light: ");
  Serial.print(lightPercent);
  Serial.print("% (Raw: ");
  Serial.print(rawLight);
  Serial.print(") | Temp: ");
  Serial.print(tempF, 1);
  Serial.print(" °F | Humidity: ");
  Serial.print(humidity, 1);
  Serial.print(" % | Pressure: ");
  Serial.print(pressure, 1);
  Serial.println(" hPa");

  delay(2000); // Read every 2 seconds
}
