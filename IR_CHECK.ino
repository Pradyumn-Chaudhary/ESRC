 // Left IR sensor
const int Right_IR = A0;
const int white = LOW;
const int black = HIGH;

void setup() {
  // put your setup code here, to ru
  pinMode(Right_IR, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
int  left_status = digitalRead(Right_IR);
  // put your main code here, to run repeatedly:
if (left_status == white) {
    Serial.println("W");
  } else {
    Serial.println("B");
  }
}
