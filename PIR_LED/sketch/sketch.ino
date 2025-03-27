#define IR_SENSOR_PIN 7  // Define IR sensor input pin
#define LED_PIN 13       // Define LED output pin

void setup() {
    pinMode(IR_SENSOR_PIN, INPUT);  // Set pin 7 as input
    pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read IR sensor data
    
    if (sensorValue == LOW) {  // Object detected
        digitalWrite(LED_PIN, HIGH);  // Turn LED ON
        Serial.println("Object Detected! Light ON");
    } else {
        digitalWrite(LED_PIN, LOW);  // Turn LED OFF
        Serial.println("No Object Detected. Light OFF");
    }
    
    delay(500);
}
