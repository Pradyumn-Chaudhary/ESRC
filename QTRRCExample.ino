// Define the number of sensors in the array
#define NUM_SENSORS   8  

// Define the Arduino digital input pins to which each sensor is connected
#define SENSOR_PIN_1 2  // Example digital pin numbers
#define SENSOR_PIN_2 3
#define SENSOR_PIN_3 4
#define SENSOR_PIN_4 5
#define SENSOR_PIN_5 6
#define SENSOR_PIN_6 7
#define SENSOR_PIN_7 8
#define SENSOR_PIN_8 9

// Array to hold sensor values
bool sensorValues[NUM_SENSORS];

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Configure sensor pins as inputs
  pinMode(SENSOR_PIN_1, INPUT);
  pinMode(SENSOR_PIN_2, INPUT);
  pinMode(SENSOR_PIN_3, INPUT);
  pinMode(SENSOR_PIN_4, INPUT);
  pinMode(SENSOR_PIN_5, INPUT);
  pinMode(SENSOR_PIN_6, INPUT);
  pinMode(SENSOR_PIN_7, INPUT);
  pinMode(SENSOR_PIN_8, INPUT);
}

void loop() {
  // Read sensor values
  sensorValues[0] = digitalRead(SENSOR_PIN_1);
  sensorValues[1] = digitalRead(SENSOR_PIN_2);
  sensorValues[2] = digitalRead(SENSOR_PIN_3);
  sensorValues[3] = digitalRead(SENSOR_PIN_4);
  sensorValues[4] = digitalRead(SENSOR_PIN_5);
  sensorValues[5] = digitalRead(SENSOR_PIN_6);
  sensorValues[6] = digitalRead(SENSOR_PIN_7);
  sensorValues[7] = digitalRead(SENSOR_PIN_8);
  
  // Print sensor values to serial monitor
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // Print a tab
  }
  Serial.println(); // Move to the next line for the next set of readings
  
  // Optional: Add a short delay before the next reading
  delay(100); // Adjust delay as needed
}
