#include <OneWire.h>
#include <DallasTemperature.h>
#include <swRTC.h>
#include <Thread.h>
#include <ThreadController.h>

//Multi-Thread
ThreadController controll = ThreadController();
Thread sensorThread = Thread();
Thread segmentThread = Thread();

//Buzz
const int BuzzPin = 3;

//button
const int button1 = 15;
const int button2 = 16;
const int button3 = 17;
static int button_status = 0;

// extern volatile unsigned long timer0_millis;   //아두이노 보드의 타이머를 0으로 초기와

//Potentionmeter
const int Potentionmeter = 14;
int potValue = 100;

//Temperature Sensor
const int ONE_WIRE_BUS = 19;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float current_Temp = 0;
int intTemp = 0;
int  resolution = 12;
DeviceAddress tempDeviceAddress;

//7Segment
const int lchclhPin = 4;
const int sftclkPin = 7;
const int sdiPin = 8;

const byte SEGMENT_MAP[] = 
 {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90,    //0 부터 9까지
  0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10,    //0. 부터 9. 까지
  0x88, 0x83, 0xA7, 0xA1, 0x86, 0x8E, 0xFF};                     //A, b, c, d, E, F, NULL

const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};    //1번~4번 세그먼트

//RealTimeClock
swRTC cur_RTC;
int cur_Hour;
int cur_Min;
int cur_Sec;

void setup() {
  // put your setup code here, to run once:
  //Serial Begin
  Serial.begin(9600);

  //Sensor Begin
  sensors.begin();
  sensors.getAddress(tempDeviceAddress, 0);
  sensors.setResolution(tempDeviceAddress, resolution);
  sensors.setWaitForConversion(false);

  //Set Current Time
  cur_RTC.stopRTC();
  cur_RTC.setTime(15, 22, 50);  //시, 분, 초
  //rtc.setDate(26, 5, 2018); //일, 월, 년
  cur_RTC.startRTC();

  //INPUT setting
  pinMode(Potentionmeter, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  //OUTPUT setiing
  pinMode(BuzzPin, OUTPUT);
  digitalWrite(BuzzPin, HIGH);
  pinMode(lchclhPin, OUTPUT);
  pinMode(sftclkPin, OUTPUT);
  pinMode(sdiPin, OUTPUT);

  //MultiThread
  sensorThread.onRun(getCurrent_Temp);
  sensorThread.setInterval(500);

  segmentThread.onRun(buttonStatus);
  segmentThread.setInterval(50);

  controll.add(&sensorThread);
  controll.add(&segmentThread);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  int intTemp = current_Temp * 100;
  int cur_Hour = cur_RTC.getHours();
  int cur_Min = cur_RTC.getMinutes();
  int cur_Sec = cur_RTC.getSeconds();
  int potValue = map(analogRead(Potentionmeter), 0, 1023, 0, 100);
  */ 

  if(current_Temp > potValue)
  {
    digitalWrite(BuzzPin, LOW);
  }else{
    digitalWrite(BuzzPin, HIGH);
  }

  controll.run();
  /*
  if(digitalRead(button1) == 0)
  {
    button_status = 1;
  }else if(digitalRead(button2) == 0){
    button_status = 2;
  }else if(digitalRead(button3) == 0){
    button_status = 3;
  }
  */

  /*
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
  */
}

void WriteNTS(byte Segment, byte Value)
{
  digitalWrite(lchclhPin, LOW);
  shiftOut(sdiPin, sftclkPin, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(sdiPin, sftclkPin, MSBFIRST, SEGMENT_SELECT[Segment]);
  digitalWrite(lchclhPin, HIGH);
}

void WriteTemp(int intTemp)
{
  WriteNTS(0, intTemp / 1000);
  delay(11);
  WriteNTS(1, ((intTemp / 100) % 10 + 10));
  delay(11);
  WriteNTS(2, (intTemp / 10) % 10);
  delay(11);
  WriteNTS(3, intTemp % 10);
}

void WriteTime(int cur_min, int cur_sec)
{
  WriteNTS(0, cur_min / 10);
  delay(12);
  WriteNTS(1, cur_min % 10 + 10);
  delay(12);
  WriteNTS(2, cur_sec / 10);
  delay(12);
  WriteNTS(3, cur_sec % 10);
}

void WritePotMeter(int potValue)
{
  WriteNTS(0, potValue / 1000);
  delay(5);
  WriteNTS(1, ((potValue / 100) % 10));
  delay(5);
  WriteNTS(2, (potValue / 10) % 10);
  delay(5);
  WriteNTS(3, potValue % 10);
  delay(5);
}

void buttonStatus()
{
  cur_Hour = cur_RTC.getHours();
  cur_Min = cur_RTC.getMinutes();
  cur_Sec = cur_RTC.getSeconds();
  potValue = map(analogRead(Potentionmeter), 0, 1023, 0, 100);

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
    WriteTemp(intTemp);
  }else if(button_status == 2){
    WriteTime(cur_Min, cur_Sec);
  }else if(button_status == 3){
    WritePotMeter(potValue);
  }
}

void getCurrent_Temp()
{
  //sensors.requestTemperatures();
  current_Temp = 22.54;
  //sensors.getTempCByIndex(0);
  intTemp = current_Temp * 100;
}

