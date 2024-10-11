#define LDR A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(LDR);
  Serial.print("The Value of LDR is : ");
  Serial.println(data);
  delay(500);
}
