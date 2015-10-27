
int L_counter = 0;
int R_counter = 0;

void setup() {
  // put your setup code here, to run once:
  
  attachInterrupt(0, left_counter, RISING);
  attachInterrupt(1, right_counter, RISING);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.print(L_counter, R_counter);
  delay(1000);
}

void left_counter() {
  L_counter = L_counter + 1;
}

void right_counter() {
  R_counter = R_counter + 1;
}
