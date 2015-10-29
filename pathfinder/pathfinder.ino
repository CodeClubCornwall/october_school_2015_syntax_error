void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  default_settings();
  
}

void loop() {
 while(analogRead(0) <= analogRead(1)) {
   left_turn();
 }
 stop_motors();
 while(analogRead(2) <= analogRead(1)) {
   right_turn();
 }
 stop_motors();
 while(analogRead(1) < analogRead(0) && analogRead(1) < analogRead(2)) { 
   forward();  
 }
 stop_motors();
 
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
  Serial.begin(115200);
}

void left_turn()  {
 left_reverse();
 right_forward();  
}

void right_turn() {
  right_reverse();
  left_forward();
}

void forward() {
  right_forward();
  left_forward();  
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
}


