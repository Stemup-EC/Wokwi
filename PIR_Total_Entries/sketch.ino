#define IR_SENSOR_PIN 7  // Define IR sensor input pin

int objectCount = 0;  // Variable to count detected objects
const int MAX_COUNT = 10;  // Threshold for "House is Full" message

void setup() {
    pinMode(IR_SENSOR_PIN, INPUT);  // Set pin 7 as input
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read IR sensor data
    
    if (sensorValue == LOW) {  // Object detected
        objectCount++;  // Increment count
        if (objectCount < MAX_COUNT) {
            Serial.print("Object Detected! Count: ");
            Serial.println(objectCount);
        } else {
            Serial.println("House is Full!");
        }
        delay(500);  // Avoid multiple detections for a single object
    } else {
        Serial.println("No Object Detected.");
    }
    
    delay(500);
}