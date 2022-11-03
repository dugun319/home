const int potPin = 14;
const int ledPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  int percent;

  val = analogRead(potPin);
  percent = map(val, 0, 1023, 0, 100);
  
  digitalWrite(ledPin, HIGH);
  delay(percent);
  
  digitalWrite(ledPin, LOW);
  delay(100-percent);

  Serial.println(percent);
}
