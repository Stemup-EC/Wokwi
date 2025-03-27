#define LED_PIN 13  // LED connected to digital pin 13

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as OUTPUT
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED ON
  delay(1000);  // Wait for 1 second
  digitalWrite(LED_PIN, LOW);   // Turn LED OFF
  delay(1000);  // Wait for 1 second
}
