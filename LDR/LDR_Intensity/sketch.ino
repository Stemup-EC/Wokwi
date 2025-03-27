#define LDR_PIN A0  // LDR connected to Analog Pin A0

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(LDR_PIN, INPUT);  // Set LDR pin as input
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);  // Print LDR value to Serial Monitor
  delay(500);  // Small delay to stabilize readings
}