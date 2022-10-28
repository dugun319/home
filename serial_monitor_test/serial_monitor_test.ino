#include <MsTimer2.h>
int num = 0;
int state = 0;

//TIMER/COUNTERO CONTROL REGISTER A: TCCROA
//TIMER/COUNTERO CONTROL REGISTER B: TCCROB

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  MsTimer2::set(100, Serial_Write);  
  MsTimer2::start();
}

void Serial_Read(){

  if(Serial.read() == 49) {
    Serial.println("LED_ON");
    digitalWrite(13, HIGH);    
  }
  if(Serial.read() == 48) {
    digitalWrite(13, LOW);
    Serial.println("LED_OFF");
  }
}

void Serial_Write(){
  if(state == 0)
  {
    Serial.println(num);
    num++;
    if(num == 100) {
      state = 1;
    }
  }else if(state == 1){
    Serial.println(num);
    num--;
    if(num == 0) {
      state = 0;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial_Read();
}
