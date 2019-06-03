#define MONITOR_LED 3

void blinkLed() {
  digitalWrite(MONITOR_LED, HIGH); 
  delay(1000);  
  digitalWrite(MONITOR_LED, LOW);  
  delay(1000);  
  digitalWrite(MONITOR_LED, HIGH); 
}

void initLeds() {
  pinMode(MONITOR_LED, OUTPUT);
  blinkLed();
}
