// Define sensor pins (adjust these according to your wiring)
#define SENSOR_PIN_0 2
#define SENSOR_PIN_1  3
#define SENSOR_PIN_2 4
#define SENSOR_PIN_3 5
#define SENSOR_PIN_4 6
#define SENSOR_PIN_5 7
#define SENSOR_PIN_6 8
#define SENSOR_PIN_7 9

// Define number of sensors
#define NUM_SENSORS 8

// Array to store sensor pin numbers
const int sensorPins[NUM_SENSORS] = {SENSOR_PIN_0, SENSOR_PIN_1, SENSOR_PIN_2, SENSOR_PIN_3, SENSOR_PIN_4, SENSOR_PIN_5, SENSOR_PIN_6, SENSOR_PIN_7};

// Array to store sensor values
unsigned int sensorValues[NUM_SENSORS];

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read sensor values
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
  
  // Print sensor values to serial monitor
  Serial.print("Sensor Values: ");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  Serial.println();
  
  // Delay before next reading
  delay(100);
}
