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
  Serial.println(";");
}

void loop() {
  
  String content = "";
  char character;
  int delimIndex = 0;
  String command = "";
  
  while(Serial.available() && !content.endsWith(";\r\n")) {
    character = Serial.read();
    content.concat(character);
    delay(2);
  }
  

  if (content != ""){
    delimIndex = content.indexOf("=");
    command = content.substring(0, delimIndex);

    //Serial.println("command = " + command);
    
    if (command == "HA"){
      //Serial.println("started " + command + " command");    
      String contentI = "";
      contentI = content.substring(delimIndex+1);
      if(contentI != ""){
        char valueArrayI[contentI.length() + 1];
        contentI.toCharArray(valueArrayI, sizeof(valueArrayI));    
        int i = 0;
        i = atoi(valueArrayI);
    
        if(i >= 50 && i <= 180){
          servo1.write(i);
        }
        Serial.print("HA="+contentI);
        delay(2);   
      }
    } else if(command == "VA"){
      //Serial.println("started " + command + " command");          
      String contentY = "";
      contentY = content.substring(delimIndex+1);
      if(contentY != ""){
        char valueArrayY[contentY.length() + 1];
        contentY.toCharArray(valueArrayY, sizeof(valueArrayY));    
        int y = 0;
        y = atoi(valueArrayY);
  
        if(y >= 50 && y <= 180) {
          servo2.write(y); 
        }  
        Serial.print("VA="+contentY);   
        delay(2);
      }
    }
    Serial.println(";");
  }

}
