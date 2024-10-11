#define RELAY_RED 2
#define RELAY_GREEN 3
#define RELAY_BLUE 4

void setup() {
  pinMode(RELAY_RED, OUTPUT);
  pinMode(RELAY_GREEN, OUTPUT);
  pinMode(RELAY_BLUE, OUTPUT);

  digitalWrite(RELAY_RED, HIGH);  // Turn off the relay (assuming active low)
  digitalWrite(RELAY_GREEN, HIGH);
  digitalWrite(RELAY_BLUE, HIGH);
}

void loop() {
  // Turn on red
  digitalWrite(RELAY_RED, LOW);
  delay(1000);
  digitalWrite(RELAY_RED, HIGH);
  
  // Turn on green
  digitalWrite(RELAY_GREEN, LOW);
  delay(1000);
  digitalWrite(RELAY_GREEN, HIGH);

  // Turn on blue
  digitalWrite(RELAY_BLUE, LOW);
  delay(1000);
  digitalWrite(RELAY_BLUE, HIGH);

  // Turn on red + green (yellow)
  digitalWrite(RELAY_RED, LOW);
  digitalWrite(RELAY_GREEN, LOW);
  delay(1000);
  digitalWrite(RELAY_RED, HIGH);
  digitalWrite(RELAY_GREEN, HIGH);

  // Turn on red + blue (magenta)
  digitalWrite(RELAY_RED, LOW);
  digitalWrite(RELAY_BLUE, LOW);
  delay(1000);
  digitalWrite(RELAY_RED, HIGH);
  digitalWrite(RELAY_BLUE, HIGH);

  // Turn on green + blue (cyan)
  digitalWrite(RELAY_GREEN, LOW);
  digitalWrite(RELAY_BLUE, LOW);
  delay(1000);
  digitalWrite(RELAY_GREEN, HIGH);
  digitalWrite(RELAY_BLUE, HIGH);

  // Turn on all (white)
  digitalWrite(RELAY_RED, LOW);
  digitalWrite(RELAY_GREEN, LOW);
  digitalWrite(RELAY_BLUE, LOW);
  delay(1000);
  digitalWrite(RELAY_RED, HIGH);
  digitalWrite(RELAY_GREEN, HIGH);
  digitalWrite(RELAY_BLUE, HIGH);
}
