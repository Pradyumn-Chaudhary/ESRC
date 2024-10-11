// Motor speed
#define Speed 255

// Define motor control pins
const int Left_Forward = A0;
const int Left_Reverse = A1;
const int Right_Forward = A2;
const int Right_Reverse = A3;

const int Left_Indicator_Front = 2;
const int Left_Indicator_Back = 4;
const int Right_Indicator_Front = 3;
const int Right_Indicator_Back = 5;
const int Front_LED1 = 6;
const int Front_LED2 = 7;
const int Back_LED1 = 8;
const int Back_LED2 = 9;

char value;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins as outputs
  pinMode(Left_Forward, OUTPUT);
  pinMode(Left_Reverse, OUTPUT);
  pinMode(Right_Forward, OUTPUT);
  pinMode(Right_Reverse, OUTPUT);
  
  pinMode(Left_Indicator_Front, OUTPUT);
  pinMode(Left_Indicator_Back, OUTPUT);
  pinMode(Right_Indicator_Front, OUTPUT);
  pinMode(Right_Indicator_Back, OUTPUT);
  pinMode(Front_LED1, OUTPUT);
  pinMode(Front_LED2, OUTPUT);
  pinMode(Back_LED1, OUTPUT);
  pinMode(Back_LED2, OUTPUT);

  // Stop the motors initially
  Stop();
}

void loop() {
  Bluetoothcontrol();
}

void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read(); // Read the incoming data
    if (value == 'F') {
      forward();
    } else if (value == 'B') {
      backward();
    } else if (value == 'L') {
      left();
    } else if (value == 'R') {
      right();
    } else if (value == 'S') {
      Stop();
    }
  }
}

void forward() {
  digitalWrite(Right_Forward,HIGH);
  digitalWrite(Right_Reverse, 0);
  digitalWrite(Left_Forward,HIGH);
  digitalWrite(Left_Reverse, 0);
  digitalWrite(Front_LED1, HIGH);
  digitalWrite(Front_LED2, HIGH);
  digitalWrite(Back_LED1, LOW);
  digitalWrite(Back_LED2, LOW);
  digitalWrite(Right_Indicator_Front, LOW);
  digitalWrite(Right_Indicator_Back, LOW);
  digitalWrite(Left_Indicator_Front, LOW);
  digitalWrite(Left_Indicator_Back, LOW);
}

void backward() {
  digitalWrite(Right_Reverse, HIGH);
  digitalWrite(Right_Forward, 0);
  digitalWrite(Left_Reverse, HIGH);
  digitalWrite(Left_Forward, 0);
  digitalWrite(Back_LED1, HIGH);
  digitalWrite(Back_LED2, HIGH);
  digitalWrite(Front_LED1, LOW);
  digitalWrite(Front_LED2, LOW);
  digitalWrite(Right_Indicator_Front, LOW);
  digitalWrite(Right_Indicator_Back, LOW);
  digitalWrite(Left_Indicator_Front, LOW);
  digitalWrite(Left_Indicator_Back, LOW);
}

void left() {
  digitalWrite(Right_Forward, HIGH);
  digitalWrite(Right_Reverse, 0);
  digitalWrite(Left_Forward, 0);
  digitalWrite(Left_Reverse, 0);
  digitalWrite(Back_LED1, LOW);
  digitalWrite(Back_LED2, LOW);
  digitalWrite(Right_Indicator_Front, LOW);
  digitalWrite(Right_Indicator_Back, LOW);
  digitalWrite(Left_Indicator_Front, HIGH);
  digitalWrite(Left_Indicator_Back, HIGH);
}

void right() {
  digitalWrite(Right_Forward, 0);
  digitalWrite(Right_Reverse, 0);
  digitalWrite(Left_Forward, HIGH);
  digitalWrite(Left_Reverse, 0);
  digitalWrite(Front_LED1, HIGH);
  digitalWrite(Front_LED2, HIGH);
  digitalWrite(Back_LED1, LOW);
  digitalWrite(Back_LED2, LOW);
  digitalWrite(Left_Indicator_Front, LOW);
  digitalWrite(Left_Indicator_Back, LOW);
  digitalWrite(Right_Indicator_Front, HIGH);
  digitalWrite(Right_Indicator_Back, HIGH);
}

void Stop() {
  digitalWrite(Right_Forward, 0);
  digitalWrite(Right_Reverse, 0);
  digitalWrite(Left_Forward, 0);
  digitalWrite(Left_Reverse, 0);
  
  digitalWrite(Front_LED1, LOW);
  digitalWrite(Front_LED2, LOW);
  digitalWrite(Back_LED1, LOW);
  digitalWrite(Back_LED2, LOW);
  digitalWrite(Right_Indicator_Front, LOW);
  digitalWrite(Right_Indicator_Back, LOW);
  digitalWrite(Left_Indicator_Front, LOW);
  digitalWrite(Left_Indicator_Back, LOW);
}
