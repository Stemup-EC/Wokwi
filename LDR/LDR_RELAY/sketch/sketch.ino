#define LDR_PIN A0    // LDR connected to Analog Pin A0
#define RELAY_PIN 7   // Relay connected to Digital Pin D7
#define THRESHOLD 500 // Adjust threshold based on light conditions

void setup() {
  pinMode(RELAY_PIN, OUTPUT);  // Set relay as output
  pinMode(LDR_PIN, INPUT);     // Set LDR as input
  Serial.begin(9600);          // Start serial communication
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);  // Print LDR value to Serial Monitor

  if (ldrValue < THRESHOLD) {  // If it's dark
    digitalWrite(RELAY_PIN, HIGH);  // Turn ON Relay (Activate Load)
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn OFF Relay
  }

  delay(500);  // Small delay for stability
}