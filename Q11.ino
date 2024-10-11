void setup() {
  Serial.begin(9600);
}

void loop() {
  String name = "";
  
  
  Serial.println("Please enter your given name (2 to 12 characters): ");
  
  
  while (Serial.available() == 0) { }
    if (Serial.available() > 0) {
    name = Serial.readStringUntil('\n');
    name.trim();
  }
  


  if (name.length() < 2 || name.length() > 12) {
    Serial.println("Invalid name length. Please enter a name between 2 to 12 characters.");
    return;
  }
  
 
  name.toUpperCase();

  Serial.print("The length of name is ");
  Serial.print(name.length());
  Serial.println(" char");

  displayBoxedName(name);
  
  Serial.println("Thanks.");
  delay(10000); 
}

void displayBoxedName(String name) {
  int length = name.length();
  
  Serial.print("+");
  for (int i = 0; i < length; i++) {
    Serial.print("-+");
  }
  Serial.println();
  
  Serial.print("|");
  for (int i = 0; i < length; i++) {
    Serial.print(name[i]);
    Serial.print("|");
  }
  Serial.println();
  
  Serial.print("+");
  for (int i = 0; i < length; i++) {
    Serial.print("-+");
  }
  Serial.println();
}
