const int ledPin1 = 10;
const int inPin1 = 15;
const int ledPin2 = 11;
const int inPin2 = 16;
const int ledPin3 = 12;
const int inPin3 = 17;

const int debounceTime = 20;
const int fastIncrement = 1000;
const int veryFastIncrement = 2000;
int count1 = 0;
int count2 = 0;
int count3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(inPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(inPin3, INPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  /*
  static bool state1, state2, state3;

  if(digitalRead(inPin1) != state1)
  {
    digitalWrite(ledPin1, state1);
    state1 = !state1;
  }
  if(digitalRead(inPin2) != state2)
  {
    digitalWrite(ledPin2, state2);
    state2 = !state2;
  }
  if(digitalRead(inPin3) != state3)
  {
    digitalWrite(ledPin3, state3);
    state3 = !state3;
  }
  */

  int duration1 = switchTime1();
  int duration2 = switchTime2();
  int duration3 = switchTime3();

  if(duration1 > veryFastIncrement)
  {
    count1 = count1 + 10;
  }
  else if(duration1 > fastIncrement)
  {
    count1 = count1 + 4;
  }
  else if(duration1 > debounceTime)
  {
    count1 = count1 +1 ;
  }else
  {
    if(count1 == 0)
    {
      digitalWrite(ledPin1, LOW);
    }else{
      digitalWrite(ledPin1, HIGH);
      count1 = count1 - 1;
    }
  }

  if(duration2 > veryFastIncrement)
  {
    count2 = count2 + 10;
  }
  else if(duration2 > fastIncrement)
  {
    count2 = count2 + 4;
  }
  else if(duration2 > debounceTime)
  {
    count2 = count2 +1 ;
  }else
  {
    if(count2 == 0)
    {
      digitalWrite(ledPin2, LOW);
    }else{
      digitalWrite(ledPin2, HIGH);
      count2 = count2 - 1;
    }
  }

  if(duration3 > veryFastIncrement)
  {
    count3 = count3 + 10;
  }
  else if(duration3 > fastIncrement)
  {
    count3 = count3 + 4;
  }
  else if(duration3 > debounceTime)
  {
    count3 = count3 +1 ;
  }else
  {
    if(count3 == 0)
    {
      digitalWrite(ledPin3, LOW);
    }else{
      digitalWrite(ledPin3, HIGH);
      count3 = count3 - 1;
    }
  }

  /*
  if(digitalRead(inPin2) == LOW)
  {
    count = count - 100;
    digitalWrite(ledPin2, LOW);
  }

  
  int LED_count = 0;
  if(digitalRead(ledPin2) == LOW){
    LED_count++;
    if(LED_count == 500){
      digitalWrite(ledPin2, HIGH);
    }
  }
  */

  Serial.print("Button1: ");
  Serial.print(count1);

  Serial.print("     Button2: ");
  Serial.print(count2);

  Serial.print("     Button3: ");
  Serial.println(count3);

  delay(100);
}

long switchTime1()
{
  static unsigned long startTime1 = 0;
  static bool state;

  if(digitalRead(inPin1) != state)
  {
    state = !state;
    startTime1 = millis();
  }

  if(state == LOW)
  {
    return millis() - startTime1;
  }else{
    return 0;
  }
}

long switchTime2()
{
  static unsigned long startTime2 = 0;
  static bool state;

  if(digitalRead(inPin2) != state)
  {
    state = !state;
    startTime2 = millis();
  }

  if(state == LOW)
  {
    return millis() - startTime2;
  }else{
    return 0;
  }
}

long switchTime3()
{
  static unsigned long startTime3 = 0;
  static bool state;

  if(digitalRead(inPin3) != state)
  {
    state = !state;
    startTime3 = millis();
  }

  if(state == LOW)
  {
    return millis() - startTime3;
  }else{
    return 0;
  }
}