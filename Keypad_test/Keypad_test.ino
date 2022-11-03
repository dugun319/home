const int num_Rows = 4;
const int num_Cols = 4;
const int debounceTime = 20;

const int row_Pins[num_Rows] = {4, 5, 6, 7};
const int col_Pins[num_Cols] = {8, 9, 10, 11};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int row = 0 ; row < num_Rows ; row++){
    pinMode(row_Pins[row], INPUT_PULLUP);
  }
  for(int col = 0 ; col < num_Cols ; col++){
    pinMode(col_Pins[col], OUTPUT);
    digitalWrite(col_Pins[col], HIGH);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int col = 0 ; col < num_Cols ; col++){
    digitalWrite(col_Pins[col], LOW);
    for(int row = 0 ; row < num_Rows ; row++){
      if(digitalRead(row_Pins[row]) == LOW){
        delay(debounceTime);
        Serial.print(col);
        Serial.println(row);
        digitalWrite(col_Pins[col], HIGH);        
      }
    }
  }
}
