// Pin definitions for motors
#define ENA 5
#define ENB 6
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A2

// Pin definitions for LEDs
#define FRONT_LEFT_LED 2
#define FRONT_RIGHT_LED 3
#define BACK_LEFT_LED 4
#define BACK_RIGHT_LED 7

char command; // Stores the received command

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set all the LED pins to outputs
  pinMode(FRONT_LEFT_LED, OUTPUT);
  pinMode(FRONT_RIGHT_LED, OUTPUT);
  pinMode(BACK_LEFT_LED, OUTPUT);
  pinMode(BACK_RIGHT_LED, OUTPUT);

  // Initialize the motors and LEDs as stopped and off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(FRONT_LEFT_LED, LOW);
  digitalWrite(FRONT_RIGHT_LED, LOW);
  digitalWrite(BACK_LEFT_LED, LOW);
  digitalWrite(BACK_RIGHT_LED, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the received command

    switch (command) {
      case 'F': // Move Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255); // Full speed
        analogWrite(ENB, 255); // Full speed
        digitalWrite(FRONT_LEFT_LED, HIGH); // Turn on front LEDs
        digitalWrite(FRONT_RIGHT_LED, HIGH);
        digitalWrite(BACK_LEFT_LED, LOW); // Turn off back LEDs
        digitalWrite(BACK_RIGHT_LED, LOW);
        break;

      case 'B': // Move Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255); // Full speed
        analogWrite(ENB, 255); // Full speed
        digitalWrite(FRONT_LEFT_LED, LOW); // Turn off front LEDs
        digitalWrite(FRONT_RIGHT_LED, LOW);
        digitalWrite(BACK_LEFT_LED, HIGH); // Turn on back LEDs
        digitalWrite(BACK_RIGHT_LED, HIGH);
        break;

      case 'L': // Turn Left
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255); // Full speed
        analogWrite(ENB, 255); // Full speed
        blinkLeftLEDs(); // Blink left LEDs
        break;

      case 'R': // Turn Right
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255); // Full speed
        analogWrite(ENB, 255); // Full speed
        blinkRightLEDs(); // Blink right LEDs
        break;

      case 'S': // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0); // Stop speed
        analogWrite(ENB, 0); // Stop speed
        digitalWrite(FRONT_LEFT_LED, LOW); // Turn off front LEDs
        digitalWrite(FRONT_RIGHT_LED, LOW);
        digitalWrite(BACK_LEFT_LED, HIGH); // Turn on back LEDs
        digitalWrite(BACK_RIGHT_LED, HIGH);
        break;
    }
  }
}

// Function to blink left LEDs
void blinkLeftLEDs() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(FRONT_LEFT_LED, HIGH);
    digitalWrite(BACK_LEFT_LED, HIGH);
    delay(250);
    digitalWrite(FRONT_LEFT_LED, LOW);
    digitalWrite(BACK_LEFT_LED, LOW);
    delay(250);
  }
}

// Function to blink right LEDs
void blinkRightLEDs() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(FRONT_RIGHT_LED, HIGH);
    digitalWrite(BACK_RIGHT_LED, HIGH);
    delay(250);
    digitalWrite(FRONT_RIGHT_LED, LOW);
    digitalWrite(BACK_RIGHT_LED, LOW);
    delay(250);
  }
}
