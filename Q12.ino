const int IR = A0;   // Define the pin number for the IR sensor
const int White = 0; // Define the value representing White
const int Black = 1; // Define the value representing Black
int IR_status;       // Variable to store the IR sensor status
int count = 1;       // Counter variable to keep track of the number readings

void setup() {
  // Setup function runs once at the beginning
  pinMode(IR, INPUT);   // Set the IR sensor pin as an input
  Serial.begin(9600);   // Initialize serial communication at a baud rate of 9600
}

void loop() {
  // Loop function runs repeatedly
  IR_status = digitalRead(IR);  // Read the current status of the IR sensor
  if (IR_status == White) {     // Check if the IR sensor detects white
    Serial.print(count);        // Print the current count
    Serial.println(F(" White"));// Print " White" and move to a new line
    delay(200);
  } else {                      // If the IR sensor does not detect white
    Serial.print(count);        // Print the current count
    Serial.println(F(" Black"));// Print " Black" and move to a new  line
    delay(200);
  }
 count++;    }                  // Increment the counter
