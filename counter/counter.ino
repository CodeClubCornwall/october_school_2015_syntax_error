
volatile int L_counter = 0;
volatile int R_counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  attachInterrupt(0, left_counter, RISING);
  attachInterrupt(1, right_counter, RISING);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print (L_counter); 
  Serial.print ("   ");
  Serial.println (R_counter);
  delay (500);  
  if (L_counter > R_counter) {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  } else if (R_counter > L_counter) {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
  if ((L_counter >= 1093) || (R_counter >= 1093)) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    while(1);
  }
    
  //delay(1000);
  //digitalWrite(9, LOW);
  //digitalWrite(10, LOW);
  //while(1);
  
}
void left_counter() {
  L_counter = L_counter + 1;
}

void right_counter() {
  R_counter = R_counter + 1;
}


