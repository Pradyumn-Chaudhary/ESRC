#include <Servo.h>

Servo myServo;
 void setup()

{ 
  myServo.attach(9);

}

int pos;

void loop()

{

for(pos=0; pos <=180; pos++)

{ 
  myServo.write(pos);

delay(10);

}

for(pos=180; pos >=0; pos--)

{ myServo.write(pos);

delay(10);

}
}
