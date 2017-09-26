const int pin = 6;
long previousMillis = 0;
long interval = 1000;
int ledState = LOW;

void setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin,ledState);  
}

void loop()
{
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
      
      
    previousMillis = currentMillis;
    digitalWrite(pin, ledState);
  }
  
    
}
