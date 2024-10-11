const int Buzzer = 13;
const int Blink = A0;

void setup(){
  pinMode(Buzzer,OUTPUT);
}

void loop(){
  digitalWrite(Buzzer,HIGH);
  digitalWrite(Blink,HIGH);
  delay(1000);
  digitalWrite(Buzzer,LOW);
  digitalWrite(Blink,LOW);
  delay(1000);
}
