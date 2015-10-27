#define turn_pulse_count  66
#define forward_pulse_count 531
 
  volatile int L_count = 0;
  volatile int R_count = 0;
  int F_count = 0;
  int Rt_count = 0;
  int C_count = 0;
  
void setup() { //done 
  // put your setup code here, to run once:
  default_settings();
}

void loop() { //done
  // put your main code here, to run repeatedly: 
  // if control == 0
  // run forward func
  if (L_count > R_count) {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  } else if (R_count > L_count) {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
  if ((C_count % 2 != 0) && (C_count <= 6)) { //if the control count has no remainder and is less then 6
      Rt_count = 0;
      while((C_count % 2 != 0) && (C_count <= 6)) {
        rotate_90();
      }
  }

  
  if ((C_count % 2 == 0) && (C_count <= 6)) { //if the control count has remainder and is less then 6
    F_count = 0;
    while ((C_count % 2 != 0) && (C_count <= 6)) {
      forwards();
    }
  }


  if (C_count >= 6) {
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
  }


}
void forwards() {
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  if (F_count >= forward_pulse_count)  {
    C_count ++;
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
  }
}

void rotate_90() {
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  if (Rt_count >= turn_pulse_count) {
    C_count ++;
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
  }
}

void default_settings() {
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  attachInterrupt(0, left_count, RISING);
  attachInterrupt(1, right_count, RISING);
  Serial.begin(115200);
}

void left_count() {
  L_count ++;
  F_count ++;
  Rt_count ++;
}

void right_count() {
  R_count ++;
}
