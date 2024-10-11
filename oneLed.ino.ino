const int RED_LED = A0;
const int WHITE_LED = A1;
const int BLUE_LED = A2;
const int YELLOW_LED = A3;
const int GREEN_LED = A4;

void setup() {
  // put your setup code here, to run once:
pinMode(RED_LED,OUTPUT);
pinMode(WHITE_LED,OUTPUT);
pinMode(BLUE_LED,OUTPUT);
pinMode(YELLOW_LED,OUTPUT);
pinMode(GREEN_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(RED_LED,HIGH);
digitalWrite(WHITE_LED,LOW);
digitalWrite(BLUE_LED,LOW);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,LOW);
delay(200);

digitalWrite(RED_LED,LOW);
digitalWrite(WHITE_LED,HIGH);
digitalWrite(BLUE_LED,LOW);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,LOW);
delay(200);

digitalWrite(RED_LED,LOW);
digitalWrite(WHITE_LED,LOW);
digitalWrite(BLUE_LED,HIGH);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,LOW);
delay(200);

digitalWrite(RED_LED,LOW);
digitalWrite(WHITE_LED,LOW);
digitalWrite(BLUE_LED,LOW);
digitalWrite(YELLOW_LED,HIGH);
digitalWrite(GREEN_LED,LOW);
delay(200);

digitalWrite(RED_LED,LOW);
digitalWrite(WHITE_LED,LOW);
digitalWrite(BLUE_LED,LOW);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,HIGH);
delay(200);
}
