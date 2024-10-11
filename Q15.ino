// Pin definitions for segment display and switches
const int A = 3;       // Segment A pin
const int B = 5;       // Segment B pin
const int C = 6;       // Segment C pin
const int D = 9;       // Segment D pin
const int E = 10;      // Segment E pin
const int F = 11;      // Segment F pin
const int DOT = A0;    // Using A0 for DOT, adjust as necessary
int stringInput;       // Variable to store input from serial

void setup() {
  // Set pin modes for segment display and DOT
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(DOT, OUTPUT);
  
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Prompt for user input
  Serial.println(F("Choose Brightness\n1.off\n2.dimmer\n3.dim\n4.bright\n5.brighter\n6.brighest"));
  
  // Wait for input from serial monitor
  while (!Serial.available()) {}
  
  // Read the input string from serial
  String inputString = Serial.readString();
  
  // Convert input string to lowercase for case-insensitive comparison
  inputString.toLowerCase();
  
  // Convert input string to integer
  stringInput = inputString.toInt();
  
  // Call function based on user input
  function_analog(stringInput);
}

void function_analog(int input) {
  // Clear all segments initially
  analogWrite(A, 0);
  analogWrite(B, 0);
  analogWrite(C, 0);
  analogWrite(D, 0);
  analogWrite(E, 0);
  analogWrite(F, 0);
  digitalWrite(DOT, LOW); // Ensure DOT is off
  
  // Set brightness levels based on user input
  switch (input) {
    case 1: // off
      break;
    case 2: // dimmer
      analogWrite(A, 50);
      analogWrite(B, 50);
      analogWrite(C, 50);
      analogWrite(D, 50);
      analogWrite(E, 50);
      analogWrite(F, 50);
      break;
    case 3: // dim
      analogWrite(A, 100);
      analogWrite(B, 100);
      analogWrite(C, 100);
      analogWrite(D, 100);
      analogWrite(E, 100);
      analogWrite(F, 100);
      break;
    case 4: // bright
      analogWrite(A, 150);
      analogWrite(B, 150);
      analogWrite(C, 150);
      analogWrite(D, 150);
      analogWrite(E, 150);
      analogWrite(F, 150);
      break;
    case 5: // brighter
      analogWrite(A, 200);
      analogWrite(B, 200);
      analogWrite(C, 200);
      analogWrite(D, 200);
      analogWrite(E, 200);
      analogWrite(F, 200);
      break;
    case 6: // brightest
      analogWrite(A, 255);
      analogWrite(B, 255);
      analogWrite(C, 255);
      analogWrite(D, 255);
      analogWrite(E, 255);
      analogWrite(F, 255);
      break;
    default:
      digitalWrite(DOT, HIGH); // Indicate error with DOT segment
      Serial.println(F("ERROR404: Invalid input")); // Print error message
      break;
  }
}
