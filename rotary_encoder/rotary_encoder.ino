const int clk_Pin = 17;
const int dk_Pin = 18;
const int sw_Pin = 19;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clk_Pin, INPUT);
  pinMode(dk_Pin, INPUT);
  pinMode(sw_Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("clk_Pin : ");
  Serial.print(analogRead(clk_Pin));
  Serial.print("     dk_Pin : ");
  Serial.print(analogRead(dk_Pin));
  Serial.print("     sw_Pin : ");
  Serial.println(analogRead(sw_Pin));
}
