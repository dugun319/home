const int num_Rows = 4;
const int num_Cols = 4;
const int debounceTime = 20;

//const int row_Pins[num_Rows] = {3, 2, 1, 0};
//const int col_Pins[num_Cols] = {4, 5, 6, 7};

const int inPin = 3;
const int outPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inPin, INPUT_PULLUP);
  pinMode(outPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(outPin);

}
