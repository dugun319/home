void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    Serial.print("avaiable :");
    Serial.print(Serial.available());
    Serial.print("read: ");
    Serial.print(Serial.read());    
  }

}
