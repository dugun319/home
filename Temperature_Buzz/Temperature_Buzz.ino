#include <OneWire.h>
#include <DallasTemperature.h>
#include <swRTC.h>
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

//Buzz
const int BuzzPin = 3;

//button
const int button1 = 15;
const int button2 = 16;
const int button3 = 17;

//Potentionmeter
const int Potentionmeter = 14;

//Temperature Sensor
const int ONE_WIRE_BUS = 19;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//RealTimeClock
swRTC cur_RTC;

void setup() {

  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  MFS.write("Hi--");

  Serial.begin(9600);
  pinMode(BuzzPin, OUTPUT);
  digitalWrite(BuzzPin, HIGH);

  sensors.begin();

  cur_RTC.stopRTC();
  cur_RTC.setTime(17, 05, 50);  //시, 분, 초
  //cur_RTC.setDate(26, 5, 2018); //일, 월, 년
  cur_RTC.startRTC();

  pinMode(Potentionmeter, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensors.requestTemperatures();
  float current_Temp = sensors.getTempCByIndex(0);
  //float current_Temp = 22.56;

  int intTemp = current_Temp * 100;
  int cur_Hour = cur_RTC.getHours();
  int cur_Min = cur_RTC.getMinutes();
  int cur_Sec = cur_RTC.getSeconds();
  float potValue = pot_map(analogRead(Potentionmeter), 0, 1023, 0, 99);

  float cur_Time = cur_Min + (cur_Sec * 0.01);

  
  if(current_Temp > potValue)
  {
    digitalWrite(BuzzPin, LOW);
  }else{
    digitalWrite(BuzzPin, HIGH);
  }

  static int button_status = 0;

  if(digitalRead(button1) == 0)
  {
    button_status = 1;
  }else if(digitalRead(button2) == 0){
    button_status = 2;
  }else if(digitalRead(button3) == 0){
    button_status = 3;
  }

  if(button_status == 1)
  {
    MFS.write(current_Temp, 2);
  }else if(button_status == 2){
    MFS.write(cur_Time, 2);
  }else if(button_status == 3){
    MFS.write(potValue, 2);
  }

  Serial.print("Temperature : ");
  Serial.print(current_Temp);
  
  Serial.print("     Current Time : "); 
  Serial.print(cur_Hour);
  Serial.print(":");
  Serial.print(cur_Min);
  Serial.print(":");
  Serial.print(cur_Sec);

  Serial.print("     Button1 : ");
  Serial.print(digitalRead(button1));
  Serial.print("     Button2 : ");
  Serial.print(digitalRead(button2));
  Serial.print("     Button3 : ");
  Serial.print(digitalRead(button3));

  Serial.print("     Threshold : ");
  Serial.println(potValue);
}

float pot_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
