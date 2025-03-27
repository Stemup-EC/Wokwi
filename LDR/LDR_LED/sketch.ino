#define LDR_PIN A0  // LDR connected to analog pin A0
#define LED_PIN 7   // LED connected to digital pin 7
#define THRESHOLD 500  // Light threshold value (adjust as needed)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);  // Read LDR sensor value
  Serial.print("Light Intensity: ");
  Serial.println(lightValue);  // Display on Serial Monitor

  if (lightValue < THRESHOLD) {  // If dark
    digitalWrite(LED_PIN, HIGH);  // Turn ON LED
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn OFF LED
  }

  delay(500);
}