// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

volatile int L_count = 0;
volatile int R_count = 0;
volatile int F_count = 0;
volatile int Rt_count = 0;
volatile int Ping_count = 100;
#define ping_distance 10
#define turn_pulse_count 90

#include <NewPing.h>

#define TRIGGER_PIN_forward  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_forward     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN_forward, ECHO_PIN_forward, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  default_settings();
}

void loop() {
  /*delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");*/
  Serial.println("Start loop");
   forwards_until_blocked();
   rotate_anticlockwise_90();
   while(1); 
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

void forwards_until_blocked() {
  Serial.println("forward");
  sonar.ping_cm();
  F_count = 0;
  L_count = 0;
  R_count = 0;
  left_forward();
  right_forward();
  while(ping_distance < Ping_count || Ping_count == 0) {
    course_correction();
    Ping_count = sonar.ping_cm();
    Serial.print(Ping_count);
    delay(40);
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

void turn () {
  Rt_count = 0;
  L_count = 0;
  R_count = 0;
  while (Rt_count < turn_pulse_count) {
    course_correction();
  }
  stop_motors();
} 

void left_count() {
  L_count ++;
  F_count ++;
  Rt_count ++;
}

void right_count() {
  R_count ++;
}

void rotate_anticlockwise_90() {
  right_forward();
  left_reverse();
  turn();
}


