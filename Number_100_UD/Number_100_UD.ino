#include <MsTimer2.h>

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  MsTimer2::set(100, Serial_Write);  
  MsTimer2::start();
}

void Serial_Read(){

    if(Serial.read() == 49) {
    digitalWrite(13, HIGH);    
  }
  if(Serial.read() == 48) {
    digitalWrite(13, LOW);
  }
}

void Serial_Write(){
  for(int i = 0 ; i<101 ; i++){
    Serial.println(i);   
  }
  for(int j = 1 ; j<101 ; j++){
    Serial.println(100-j);      
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial_Read();
}
