// Define pin assignments for sensors and motor control
const int Left_IR = A1; // Left IR sensor
const int Right_IR = A0; // Right IR sensor
const int Left_wheel_forward = 8; // Left wheel forward control
const int Left_wheel_reverse = 7; // Left wheel reverse control
const int Right_wheel_forward = 10; // Right wheel forward control
const int Right_wheel_reverse = 9; // Right wheel reverse control
const int Red_Led = 6;
const int Blue_Led = 3;
const int Green_Led = 2;
const int GND = 5;

// Define sensor states
const int white = LOW;
const int black = HIGH;

// Variables to store sensor states
int left_status;
int right_status;

void setup() {
  // Initialize sensor pins as input with internal pull-up resistors
  pinMode(Left_IR, INPUT_PULLUP);
  pinMode(Right_IR, INPUT_PULLUP);

  // Initialize LED pins as output
  pinMode(Red_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);
  pinMode(Blue_Led, OUTPUT);
  pinMode(GND, OUTPUT);

  // Initialize motor control pins as output
  pinMode(Left_wheel_forward, OUTPUT);
  pinMode(Left_wheel_reverse, OUTPUT);
  pinMode(Right_wheel_forward, OUTPUT);
  pinMode(Right_wheel_reverse, OUTPUT);
  
  // Ensure LEDs are off initially
  digitalWrite(Red_Led, LOW);
  digitalWrite(Green_Led, LOW);
  digitalWrite(Blue_Led, LOW);
  
  // Set GND pin to LOW
  digitalWrite(GND, LOW);
}

void loop() {
  // Continuously run the line follower function
  line_follower();
}

void line_follower() {
  // Read the state of the IR sensors
  left_status = digitalRead(Left_IR);
  right_status = digitalRead(Right_IR);

  // Control left wheel based on the left sensor state
  if (left_status == white) {
    digitalWrite(Left_wheel_forward, HIGH); // Move forward
    digitalWrite(Left_wheel_reverse, LOW);
  } else {
    digitalWrite(Left_wheel_forward, LOW); // Stop
    digitalWrite(Left_wheel_reverse, LOW);
  }

  // Control right wheel based on the right sensor state
  if (right_status == white) {
    digitalWrite(Right_wheel_forward, HIGH); // Move forward
    digitalWrite(Right_wheel_reverse, LOW);
  } else {
    digitalWrite(Right_wheel_forward, LOW); // Stop
    digitalWrite(Right_wheel_reverse, LOW);
  }

  // Control LEDs based on the sensor states
  if (right_status == black && left_status == black) {
    digitalWrite(Green_Led, HIGH); // Turn on green LED
    digitalWrite(Blue_Led, HIGH); // Turn on blue LED
  } else {
    digitalWrite(Green_Led, LOW); // Turn off green LED
    digitalWrite(Blue_Led, LOW); // Turn off blue LED
  }
}
