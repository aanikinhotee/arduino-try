// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(50);
  motor1.run(RELEASE);

  motor2.setSpeed(50);
  motor2.run(RELEASE);

  motor3.setSpeed(50);
  motor3.run(RELEASE);

  motor4.setSpeed(50);
  motor4.run(RELEASE);

}

void loop() {
  if ( Serial.available()) {
    char ch = Serial.read();
    
    switch(ch) {
      case 'f':
        Serial.print("f");
        
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        break;
      case 'b':
        Serial.print("b");
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        break;
      case 'r':
        Serial.print("r");
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(FORWARD);
        motor1.setSpeed(250);
        motor2.setSpeed(250);
        motor3.setSpeed(250);
        motor4.setSpeed(250);
        delay(100);
        // turn on motor
        motor1.setSpeed(50);
        motor1.run(RELEASE);
      
        motor2.setSpeed(50);
        motor2.run(RELEASE);
      
        motor3.setSpeed(50);
        motor3.run(RELEASE);
      
        motor4.setSpeed(50);
        motor4.run(RELEASE);
        
        break;
      case 'l':      
        Serial.print("l");      
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(BACKWARD);
        motor1.setSpeed(250);
        motor2.setSpeed(250);
        motor3.setSpeed(250);
        motor4.setSpeed(250);
        delay(100);
        // turn on motor
        motor1.setSpeed(50);
        motor1.run(RELEASE);
      
        motor2.setSpeed(50);
        motor2.run(RELEASE);
      
        motor3.setSpeed(50);
        motor3.run(RELEASE);
      
        motor4.setSpeed(50);
        motor4.run(RELEASE);

        break;
      case 's':
      
        Serial.print("s");
      
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        break;
    }
  }  
}
