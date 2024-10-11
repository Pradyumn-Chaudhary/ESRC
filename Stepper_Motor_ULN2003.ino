// Define the pins connected to the ULN2003 driver board
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Number of steps per revolution for 28BYJ-48
const int stepsPerRevolution = 2048;

// Define step sequences for the 28BYJ-48 stepper motor
const int stepCount = 8;
const int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int stepIndex = 0;  // Current step index

void setup() {
  // Set the IN pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Rotate the motor one revolution in one direction
  for (int i = 0; i < stepsPerRevolution; i++) {
    stepMotor(1);  // Step forward
    delay(5);      // Adjust delay for speed control
  }
  
  delay(1000);  // Wait for 1 second
  
  // Rotate the motor one revolution in the opposite direction
  for (int i = 0; i < stepsPerRevolution; i++) {
    stepMotor(-1);  // Step backward
    delay(5);       // Adjust delay for speed control
  }
  
  delay(1000);  // Wait for 1 second
}

// Function to step the motor
void stepMotor(int direction) {
  // Update the step index
  stepIndex += direction;
  
  // Wrap around the step index
  if (stepIndex >= stepCount) {
    stepIndex = 0;
  } else if (stepIndex < 0) {
    stepIndex = stepCount - 1;
  }
  
  // Set the IN pins according to the current step sequence
  digitalWrite(IN1, stepSequence[stepIndex][0]);
  digitalWrite(IN2, stepSequence[stepIndex][1]);
  digitalWrite(IN3, stepSequence[stepIndex][2]);
  digitalWrite(IN4, stepSequence[stepIndex][3]);
}
