// Pin definitions
const int leftWheelForward = A0;
const int leftWheelBackward = A1;
const int rightWheelForward = A2;
const int rightWheelBackward = A3;
const int backLED = A4;
const int rightIndicator = A5;
const int leftIndicator = 2;

// Variables to store Bluetooth commands
char command;

// Blink interval in milliseconds
const unsigned long blinkInterval = 500;
unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  // Initialize the motor control pins as outputs
  pinMode(leftWheelForward, OUTPUT);
  pinMode(leftWheelBackward, OUTPUT);
  pinMode(rightWheelForward, OUTPUT);
  pinMode(rightWheelBackward, OUTPUT);
  
  // Initialize the LED pins as outputs
  pinMode(backLED, OUTPUT);
  pinMode(rightIndicator, OUTPUT);
  pinMode(leftIndicator, OUTPUT);

  // Initialize the serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Check if there is any data from the Bluetooth module
  if (Serial.available() > 0) {
    command = Serial.read();
    
    // Reset all outputs
    digitalWrite(leftWheelForward, LOW);
    digitalWrite(leftWheelBackward, LOW);
    digitalWrite(rightWheelForward, LOW);
    digitalWrite(rightWheelBackward, LOW);
    digitalWrite(backLED, LOW);
    digitalWrite(rightIndicator, LOW);
    digitalWrite(leftIndicator, LOW);
  }

  // Handle the commands
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= blinkInterval) {
    // Save the last time you blinked the LED
    previousMillis = currentMillis;

    // If the LED is off turn it on and vice-versa
    ledState = !ledState;
  }
  
  switch (command) {
    case 'F': // Move forward
      digitalWrite(leftWheelForward, HIGH);
      digitalWrite(rightWheelForward, HIGH);
      break;
    case 'B': // Move backward
      digitalWrite(leftWheelBackward, HIGH);
      digitalWrite(rightWheelBackward, HIGH);
      digitalWrite(backLED, ledState);
      break;
    case 'L': // Turn left
      digitalWrite(leftWheelBackward, HIGH);
      digitalWrite(rightWheelForward, HIGH);
      digitalWrite(leftIndicator, ledState);
      break;
    case 'R': // Turn right
      digitalWrite(leftWheelForward, HIGH);
      digitalWrite(rightWheelBackward, HIGH);
      digitalWrite(rightIndicator, ledState);
      break;
    case 'S': // Stop
      // All outputs are already LOW by default
      break;
    default:
      // Invalid command, do nothing
      break;
  }
}
