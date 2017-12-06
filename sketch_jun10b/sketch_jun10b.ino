#include <Servo.h> 

Servo servo1;
Servo servo2;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  // turn on servo
  servo1.attach(10);
  servo1.write(90);

  servo2.attach(9);
  servo2.write(70);
  delay(1000);
  
  Serial.println("initialized");
}

void loop() {
  
  String content = "";
  String contentI = "";
  String contentY = "";
  char character;
  int delimIndex = 0;

  while(Serial.available()) {
    character = Serial.read();
    content.concat(character);
    delay(4);
  }

  if (content != ""){
    delimIndex = content.indexOf("|");

    contentI = content.substring(0, delimIndex);
    char valueArrayI[contentI.length() + 1];
    contentI.toCharArray(valueArrayI, sizeof(valueArrayI));    
    int i = atoi(valueArrayI);

    if(i >= 50 && i <= 180){
      servo1.write(i);
    }


    if(delimIndex > 0){    
      contentY = content.substring(delimIndex+1);
      char valueArrayY[contentY.length() + 1];
      contentY.toCharArray(valueArrayY, sizeof(valueArrayY));    
      int y = atoi(valueArrayY);

      if(y >= 50 && y <= 180) {
        servo2.write(y); 
      }  
    }
    delay(2);
    Serial.println(content);   
  }
}
