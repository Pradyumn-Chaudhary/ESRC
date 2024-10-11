// Pin definitions
const int Switch = 2;  // Pin connected to the switch
const int LED = 3;     // Pin connected to the LED

// Variables
int toggle = 0;         // Variable to toggle LED state
int switch_status;       // Variable to store switch status

void setup() {
  pinMode(Switch, INPUT_PULLUP);   // Set switch pin as input
  pinMode(LED, OUTPUT);     // Set LED pin as output

  Serial.begin(9600);       // Initialize serial communication at 9600 baud
}

void loop() {
  switch_status = digitalRead(Switch);  // Read the state of the switch
  
  // If switch is pressed (HIGH state), toggle the toggle variable
  if (switch_status == LOW) {
    if (toggle == 0)
      toggle = 1;
    else
      toggle = 0;
        // Control the LED based on the state of the toggle variable
 
    delay(200);  // Delay to debounce the switch
  }
   if (toggle == 0)
    digitalWrite(LED, LOW);   // Turn off the LED
  else
    digitalWrite(LED, HIGH);  // Turn on the LED

}
