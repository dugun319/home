const int BuzzPin = 3;
const int PotPin = 14;
const int Button1 = 15;
const int Button2 = 16;
const int Button3 = 17;

const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;
const int A = 440;
const int B = 494;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BuzzPin, OUTPUT);
  digitalWrite(BuzzPin, HIGH);
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  int frequency = 100;

  if(digitalRead(Button1) == 0){
    digitalWrite(BuzzPin, LOW);
  }else if(digitalRead(Button2) == 0){
    digitalWrite(BuzzPin, HIGH);
  }else if(digitalRead(Button3) == 0){
    digitalWrite(BuzzPin, LOW);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, A, 500);
    delay(500);
    tone(BuzzPin, A, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, E, 1000);
    delay(1000);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, E, 500);
    delay(500);
    tone(BuzzPin, E, 500);
    delay(500);   
    tone(BuzzPin, D, 1000);
    delay(1500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, A, 500);
    delay(500);
    tone(BuzzPin, A, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, E, 1000);
    delay(1000);
    tone(BuzzPin, G, 500);
    delay(500);
    tone(BuzzPin, E, 500);
    delay(500);
    tone(BuzzPin, D, 500);
    delay(500);
    tone(BuzzPin, E, 500);
    delay(500);
    tone(BuzzPin, C, 200);
    delay(2000);  
  }
  
  Serial.print("Button1 : ");
  Serial.print(digitalRead(Button1));
  Serial.print("     Button2 : ");
  Serial.print(digitalRead(Button2));
  Serial.print("      Button3 : ");
  Serial.println(digitalRead(Button3));
  
}

