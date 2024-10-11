const int LED = 11;
const int Potential = A0;

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(Potential,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int v = analogRead(Potential);
analogWrite(LED,v);
delay(100);
}
