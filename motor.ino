const int A = 3;        // Define pin A as analog pin A0
const int B = 5;        // Define pin B as analog pin A   // Define button pin as analog pin A2
int count = 0;           // Initialize count to 0

void setup() {
  // Set pin modes
  pinMode(A, OUTPUT);    // Set pin A as an output
  pinMode(B, OUTPUT);    // Set pin B as an output
 // Set button pin as an input
}

void loop() {
  // Check the state of the button and toggle count
  analogWrite(A,0);
  digitalWrite(B,LOW);
  analogWrite(A,50);
  delay(3000);
  analogWrite(A,100);
  delay(3000);
  analogWrite(A,150);
  delay(3000);
  analogWrite(A,200);
  delay(3000);
  analogWrite(A,250);
  delay(3000);
  


}
