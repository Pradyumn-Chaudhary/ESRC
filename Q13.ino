// Pin definitions for segment display and switches
const int increment_Switch = 2;
const int decrement_Switch = 3;
const int A = 12;
const int B = 13;
const int C = 8;
const int D = 7;
const int E = 6;
const int F = 11;
const int G = 10;
const int DOT = 9;

// Global variables
int count = 0;              // Counter variable
int increment_status;       // Stores state of increment switch
int decrement_status;       // Stores state of decrement switch

void setup() {
  // Set pin modes for switches and segment display
  pinMode(increment_Switch, INPUT_PULLUP);
  pinMode(decrement_Switch, INPUT_PULLUP);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DOT, OUTPUT);

  // Initialize the display to be clear
  clearSegment();
  displayNumber(count);    // Display initial count
}

void loop() {
  // Read switches
  increment_status = digitalRead(increment_Switch);
  decrement_status = digitalRead(decrement_Switch);
  
  // Increment count if increment switch is pressed
  if(increment_status == HIGH) {
    count++;
    delay(200);   // Debounce delay
  }
  
  // Decrement count if decrement switch is pressed
  if(decrement_status == HIGH) {
    count--;
    delay(200);   // Debounce delay
  }

  // Display current count
  displayNumber(count);
  delay(200);   // Delay between updates

  // Reset count to 0 if it goes out of bounds
  if(count < 0 || count > 9) {
    count = 0;
  }
}

// Function to clear all segments
void clearSegment() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DOT, LOW);  // Turn off DOT segment
}

// Function to display a number on the segment display
void displayNumber(int num) {
  // Clear the display before showing a new number
  clearSegment();

  // Turn on the appropriate segments to display the number
  switch(num) {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 4:
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    default:
      digitalWrite(DOT, HIGH); // Display DOT if number is out of range
      break;
  }
}
