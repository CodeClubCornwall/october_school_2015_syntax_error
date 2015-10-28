#define turn_pulse_count 90
#define forward_pulse_count 150

volatile int L_count = 0;
volatile int R_count = 0;
volatile int F_count = 0;
volatile int Rt_count = 0;
  
void setup() { //done 
  // put your setup code here, to run once:
  default_settings();
}

void loop() { //done
  // put your main code here, to run repeatedly: 
 left_square();
 right_square();
 while(1);
}

void forwards() {
  F_count = 0;
  L_count = 0;
  R_count = 0;
  left_forward();
  right_forward();
  while(F_count < forward_pulse_count) {
    course_correction();
  }
  stop_motors();
}

void left_forward() {
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);  
}

void left_reverse() {
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);  
}

void right_reverse() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);  
}

void right_forward() {
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);  
}

void stop_motors() {
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
    R_count = 0;
    L_count = 0;  
}

void rotate_clockwise_90() {
  left_forward();
  right_reverse();
  turn();
}

void turn () {
  Rt_count = 0;
  L_count = 0;
  R_count = 0;
  while (Rt_count < turn_pulse_count) {
    course_correction();
  }
  stop_motors();
} 

void rotate_anticlockwise_90() {
  right_forward();
  left_reverse();
  turn();
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

void course_correction() {
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
}

void left_square() { 
  int count = 0; 
  while(count < 3) {
    forwards();
    rotate_clockwise_90();
    count ++;
  }
  forwards();
}

void right_square() {
  int count = 0;
  while(count < 3) {
    forwards();
    rotate_anticlockwise_90();
    count ++;
  }
  forwards();
}
