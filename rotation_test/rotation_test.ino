volatile int R_counter = 0;

#define pulse_count 143

void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(2, HIGH);
attachInterrupt(0, right_counter, RISING);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (R_counter >= pulse_count) { 
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  
}

void right_counter() {
  R_counter = R_counter + 1;
}
