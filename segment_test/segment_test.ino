extern volatile unsigned long timer0_millis;

const int lchclhPin = 4;
const int sftclkPin = 7;
const int sdiPin = 8;
const int Pot1 = 14;

const byte SEGMENT_MAP[] = 
 {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90,    //0 부터 9까지
  0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10,    //0. 부터 9. 까지
  0x88, 0x83, 0xA7, 0xA1, 0x86, 0x8E, 0xFF};                     //A, b, c, d, E, F, NULL

const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};    //1번~4번 세그먼트

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lchclhPin, OUTPUT);
  pinMode(sftclkPin, OUTPUT);
  pinMode(sdiPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue;
  potValue = analogRead(Pot1);
  
  Serial.print("Potentiometer : ");
  Serial.println(potValue);

  int realTime;
  
  realTime = millis();

  if(realTime > 10000)
  {
    timer0_millis=0;
  }
  /*
  for(int i=0 ; i<27 ; i++)
  {
    WriteNTS(0, i);
    delay(210);
    WriteNTS(1, i);
    delay(210);
    WriteNTS(2, i);
    delay(210);
    WriteNTS(3, i);
    delay(210);
  }
  */
  
  WriteNTS(0, realTime / 1000);
  //delay(5);
  WriteNTS(1, (realTime / 100) % 10);
  //delay(5);
  WriteNTS(2, (realTime / 10) % 10);
  //delay(5);
  WriteNTS(3, realTime % 10);
  //delay(5);   
  
}

void WriteNTS(byte Segment, byte Value)
{
  digitalWrite(lchclhPin, LOW);
  shiftOut(sdiPin, sftclkPin, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(sdiPin, sftclkPin, MSBFIRST, SEGMENT_SELECT[Segment]);
  digitalWrite(lchclhPin, HIGH);
}
