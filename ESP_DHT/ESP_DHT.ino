#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL34rPG9xkw"
#define BLYNK_TEMPLATE_NAME "DHT"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// 🔹 Replace with your Blynk Auth Token
char auth[] = "kBmw9jiUQ8trzNlY_Vz3XkvMNAD-ecB9";  

// 🔹 Replace with your WiFi Credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Define DHT sensor
#define DHT_PIN 34  // DHT22 Connected to GPIO 34
#define DHT_TYPE DHT22  
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");

  Blynk.begin(auth, ssid, pass);  // Initialize Blynk
  dht.begin();
}

void loop() {
  Blynk.run();  // Run Blynk IoT

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22 sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V0, temperature); // Send Temperature to Blynk
  Blynk.virtualWrite(V1, humidity);    // Send Humidity to Blynk

  delay(2000); // Update every 2 seconds
}
