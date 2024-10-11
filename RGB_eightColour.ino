const int RED_LED =  11;    // Pin number for the red LED
const int GREEN_LED =  10;  // Pin number for the green LED
const int BLUE_LED =  9;    // Pin number for the blue LED

void setup() {
  // Initialize the pin modes for the LEDs as OUTPUT
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  // Turn off all LEDs initially
  nocolour();

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Prompt the user to choose a color via the serial monitor
  Serial.println(F("Which Colour?\n1.Black\n2.Red\n3.Green\n4.Yellow\n5.Blue\n6.Magenta\n7.Cyan\n8.White"));

  // Wait for user input
  while (Serial.available() == 0) {}

  // Read the input as an integer
  int num = Serial.parseInt();

  // Display the chosen color based on the input
  displayColour(num);

  // Small delay before the next loop iteration
  delay(200);
}

void nocolour() {
  // Turn off all LEDs
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void displayColour(int num) {
  // Turn off all LEDs before setting the new color
  nocolour();

  // Set the LEDs based on the chosen color
  switch (num) {
    case 1:
      nocolour();  // Black (all LEDs off)
      break;
    case 2:
      digitalWrite(RED_LED, HIGH);  // Red
      break;
    case 3:
      digitalWrite(GREEN_LED, HIGH);  // Green
      break;
    case 4:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);  // Yellow (Red + Green)
      break;
    case 5:
      digitalWrite(BLUE_LED, HIGH);  // Blue
      break;
    case 6:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);  // Magenta (Red + Blue)
      break;
    case 7:
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);  // Cyan (Blue + Green)
      break;
    case 8:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);  // White (Red + Green + Blue)
      break;
  }
}
