// Define motor control pins
const int Left_Forward = A0;
const int Left_Reverse = A1;
const int Right_Forward = A2;
const int Right_Reverse = A3;

const int Left_Indicator = 2;
const int Right_Indicator = A5;
const int Back_LED = A4;

char value;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins as outputs
  pinMode(Left_Forward, OUTPUT);
  pinMode(Left_Reverse, OUTPUT);
  pinMode(Right_Forward, OUTPUT);
  pinMode(Right_Reverse, OUTPUT);
  
  pinMode(Left_Indicator, OUTPUT);
  pinMode(Right_Indicator, OUTPUT);
  pinMode(Back_LED, OUTPUT);

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
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Left_Forward,HIGH);
  digitalWrite(Left_Reverse, LOW);
  digitalWrite(Back_LED, LOW);
  digitalWrite(Right_Indicator, LOW);
  digitalWrite(Left_Indicator, LOW);
  delay(300);
  digitalWrite(Right_Forward,LOW);
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Left_Forward,LOW);
  digitalWrite(Left_Reverse, LOW);
}

void backward() {
  digitalWrite(Right_Reverse, HIGH);
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Left_Reverse, HIGH);
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Back_LED, HIGH);
  digitalWrite(Right_Indicator, LOW);
  digitalWrite(Left_Indicator, LOW);
  delay(300);
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Left_Reverse, LOW);
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Back_LED, LOW);
}

void left() {
  digitalWrite(Right_Forward, HIGH);
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Left_Reverse, HIGH);
  digitalWrite(Back_LED, LOW);
  digitalWrite(Right_Indicator, LOW);
  digitalWrite(Left_Indicator, HIGH);
  delay(150);
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Left_Reverse, LOW);
  digitalWrite(Left_Indicator, LOW);
}

void right() {
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Right_Reverse, HIGH);
  digitalWrite(Left_Forward, HIGH);
  digitalWrite(Left_Reverse, LOW);
  digitalWrite(Back_LED, LOW);
  digitalWrite(Left_Indicator, LOW);
  digitalWrite(Right_Indicator, HIGH);
  delay(150);
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Right_Reverse, LOW);
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Left_Reverse, LOW);
  digitalWrite(Right_Indicator, LOW);
}

void Stop() {
  digitalWrite(Right_Forward, 0);
  digitalWrite(Right_Reverse, 0);
  digitalWrite(Left_Forward, 0);
  digitalWrite(Left_Reverse, 0);
  
  digitalWrite(Back_LED, LOW);
  digitalWrite(Right_Indicator, LOW);
  digitalWrite(Left_Indicator, LOW);
}
