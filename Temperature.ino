const int lm35Pin = A3;
void setup() {
   pinMode(lm35Pin,INPUT);
  Serial.begin(9600);
}


float readTemperature(int analogPin) {
 int analogValue = analogRead(analogPin);
   float voltage = analogValue * (5.0 / 1023.0);
   float temperatureC = voltage*100;
   
}

void loop(){

  float temperature = readTemperature(lm35Pin);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
}
