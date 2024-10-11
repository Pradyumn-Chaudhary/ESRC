  #include <Servo.h>

// Pin assignments
const int joyXPin = A0; // X-axis of the joystick
const int joyYPin = A1; // Y-axis of the joystick
const int SW = A3;      // Switch pin
const int Buzzer = A4;  // Buzzer pin
const int in1 = 3; 
const int in2 = 5; 
const int in3 = 6; 
const int in4 = 9; 

const int trigPin = 10; // Ultrasonic sensor TRIG pin
const int echoPin = 11; // Ultrasonic sensor ECHO pin
const int servoPin = 12; // Servo motor pin

char value;

Servo myServo;

void setup() {
  // Initialize the motor control pins as outputs
  pinMode(SW, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(90); // Set servo to middle position (90 degrees)
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  Manual();
  Bluetoothcontrol();
}

void Manual() {
  // Read the joystick values
  myServo.write(90);
  int joyX = analogRead(joyXPin);
  int joyY = analogRead(joyYPin);
  int H = digitalRead(SW);

  // Map joystick values to PWM values (0-255)
  int motorSpeedX = map(joyX, 0, 1023, -255, 255);
  int motorSpeedY = map(joyY, 0, 1023, -255, 255);

  // Check for obstacles
  if (isObstacleDetected()) {
    Stop();
    return; // Stop further execution in Manual mode if an obstacle is detected
  }

  // Control the motors based on joystick input for forward/backward movement
  if (motorSpeedY > 0) {
    // Move forward
    analogWrite(in1, motorSpeedY);
    analogWrite(in2, LOW);
    analogWrite(in3, motorSpeedY);
    analogWrite(in4, LOW);
  } else if (motorSpeedY < 0) {
    // Move backward
    analogWrite(in1, LOW);
    analogWrite(in2, -motorSpeedY);
    analogWrite(in3, LOW);
    analogWrite(in4, -motorSpeedY);
  } else {
    // Stop
    Stop();
  }

  // Control the motors based on joystick input for left/right movement
  if (motorSpeedX > 0) {
    // Turn right
    analogWrite(in1, motorSpeedX);
    analogWrite(in2, LOW);
    analogWrite(in3, LOW);
    analogWrite(in4, motorSpeedX);
  } else if (motorSpeedX < 0) {
    // Turn left
    analogWrite(in1, LOW);
    analogWrite(in2, -motorSpeedX);
    analogWrite(in3, -motorSpeedX);
    analogWrite(in4, LOW);
  } else {
    // Stop turning
    Stop();
  }

  if (H == LOW) { // Assuming the switch is active LOW
    Horn();
  }

  // Debugging output
  Serial.print("X: ");
  Serial.print(motorSpeedX);
  Serial.print(" Y: ");
  Serial.println(motorSpeedY);

  delay(100); // Small delay for stability
}

void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read(); // Read the incoming data
    if (value == 'F') {
      forward();
    } else if (value == 'B') {
      reverse();
    } else if (value == 'L') {
      left();
    } else if (value == 'R') {
      right();
    } else if (value == 'S') {
      Stop();
    } else if (value == 'H') {
      Horn();
    }
  }
}

void forward() {
  myServo.write(90);
  if (isObstacleDetected()) {
    Stop();
    return;
  }
  analogWrite(in1, 255);
  analogWrite(in2, LOW);
  analogWrite(in3, 255);
  analogWrite(in4, LOW);
}

void reverse() {
  myServo.write(90);
  analogWrite(in1, LOW);
  analogWrite(in2, 255);
  analogWrite(in3, LOW);
  analogWrite(in4, 255);
}

void left() {
    myServo.write(140);
  if (isObstacleDetected()) {
    Stop();
    return;
  }
  analogWrite(in1, LOW);
  analogWrite(in2, 255);
  analogWrite(in3, 255);
  analogWrite(in4, LOW);
}

void right() {
    myServo.write(40);
  if (isObstacleDetected()) {
    Stop();
    return;
  }
  analogWrite(in1, 255);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, 255);
}

void Stop() {
  analogWrite(in1, LOW);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, LOW);
}

void Horn() {
  digitalWrite(Buzzer, HIGH);
  delay(100);
  digitalWrite(Buzzer, LOW);
}

bool isObstacleDetected() {
  long duration;
  int distance;

  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse from the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert the time into a distance

  // Check if the distance is less than a threshold (e.g., 10 cm)
  if (distance < 10) {
    return true; // Obstacle detected
    Horn();
  } else {
    return false; // No obstacle
  }
}
