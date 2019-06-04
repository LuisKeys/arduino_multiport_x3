#define PORT_1 8
#define PORT_2 9
#define PORT_3 10

void turnOnLed(byte portNumber) {
  digitalWrite(portNumber, LOW); 
}

void turnOffLed(byte portNumber) {
  digitalWrite(portNumber, HIGH); 
}

void initLeds() {
  pinMode(PORT_1, OUTPUT);
  pinMode(PORT_2, OUTPUT);
  pinMode(PORT_3, OUTPUT);
  turnOffLed(PORT_1);
  turnOffLed(PORT_2);
  turnOffLed(PORT_3);

  turnOnLed(PORT_1);
  delay(1000);  
  turnOnLed(PORT_2);
  delay(1000);  
  turnOnLed(PORT_3);
  delay(1000);  
    
  turnOffLed(PORT_1);
  delay(1000);  
  turnOffLed(PORT_2);
  delay(1000);  
  turnOffLed(PORT_3);
  
}
