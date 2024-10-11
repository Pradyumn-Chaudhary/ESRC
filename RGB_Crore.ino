const int RED_LED = 11;    // Pin number for the red LED
const int GREEN_LED = 10;  // Pin number for the green LED
const int BLUE_LED = 9;    // Pin number for the blue LED
byte i, j, k;

void setup() {
  // Initialize the pin modes for the LEDs as OUTPUT
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  // Iterate through all possible color combinations
  for (i = 0; i < 256; i++) {
    for (j = 0; j < 256; j++) {
      for (k = 0; k < 256; k++) {
        analogWrite(RED_LED, i);
        analogWrite(GREEN_LED, j);
        analogWrite(BLUE_LED, k);

        // Add a small delay to make the color changes noticeable
        delay(10);
      }
    }
  }
}
