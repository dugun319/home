/*
 * This code was Created by Jonathan Pereira on 10th February 2016 and is in the public domain.
 * Comment the type of wave that you do not wish to generate.
*/
const int inputPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}

void loop() 
{
  //Sine Wave & Cosine Wave
  int val = digitalRead(inputPin);
  Serial.print(val);
  
}