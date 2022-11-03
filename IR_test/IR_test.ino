const int IR_out = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_out, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("IR_out : ");
  Serial.println(digitalRead(IR_out));
  if(digitalRead(IR_out) == 0){
    Serial.println("Get out of my Way!");
  }
  delay(500);
}
