#include <Servo.h>

Servo servo1;

void setup() {
  pinMode(1,OUTPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
  servo1.attach(10);

}

void loop() {
  
  if ( Serial.available()) {
    char ch = Serial.read();
    
    switch(ch) {
      case 's':
        servo1.write(1);
        break;
      case 'd':
        servo1.detach();
        break;
      case 'a':
        servo1.attach(10);
        break;
    }
  }
}
