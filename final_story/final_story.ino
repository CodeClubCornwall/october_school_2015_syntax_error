//move towards the light
//if you find a drop, reverse, turn left/right, move forwards
//if you find a
#include <NewPing.h>

long left_or_right_test = 0;
volatile int ping_count_forward = 0;
volatile int ping_count_down = 0;

#define ping_distance_forward 20
#define ping_distance_down 10

#define TRIGGER_PIN_FORWARD 4//Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_FORWARD 5// Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN_DOWN 13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_DOWN 17
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar_forward(TRIGGER_PIN_FORWARD, ECHO_PIN_FORWARD, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_down(TRIGGER_PIN_DOWN, ECHO_PIN_DOWN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  default_settings();
  
}

void loop() {
  if (ping_count_down <= ping_distance_down || ping_count_down != 0)  {
    
    while (ping_count_forward >= ping_distance_forward || ping_count_forward == 0)  {
      
      while(analogRead(1) <= analogRead(0) && analogRead(1) <= analogRead(2))  {
        forwards();
        ping_count_forward = sonar_forward.ping_cm();
        delay(30);
        stop_motors();
        ping_count_down = sonar_down.ping_cm();
      }
        
      delay(30);
      
      while(analogRead(0) < analogRead(1))  {
        left_turn(); 
        ping_count_forward = sonar_forward.ping_cm();
        delay(30);
        stop_motors();
        ping_count_down = sonar_down.ping_cm();
      }
      
      delay(30);
      while(analogRead(2) < analogRead(1))  {
        right_turn();
        ping_count_forward = sonar_forward.ping_cm();
        delay(30);
        stop_motors();
        ping_count_down = sonar_down.ping_cm();
        
      }
      delay(30);
    }
      
      
      if(ping_count_forward < ping_distance_forward && ping_count_forward != 0)  {
        reverse();
        turn();
        ping_count_forward = sonar_forward.ping_cm();
      }
      
      
    }
  
  if(ping_count_down > ping_distance_down) {
        reverse();
        turn();
        ping_count_down = sonar_down.ping_cm();
  }
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

void L_turn_R() {
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9, 150);  
}

void R_turn_R() {
  analogWrite(10, 150); 
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);  
}

void L_turn_F() {
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9, 150);  
}

void R_turn_F() {
  analogWrite(10, 150); 
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);  
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

void reverse() {
  right_reverse();
  left_reverse();
  delay(1000);
  stop_motors;
}

void turn() {
  left_or_right_test = random(1, 2);
  if(left_or_right_test == 1)  {
    left_turn();
  }
  if(left_or_right_test == 2)  {
    right_turn();
  }  
}

void left_turn()  {
  L_turn_R();
  R_turn_F();
}

void right_turn() {
  L_turn_F();
  R_turn_R();
}
    
void forwards()  {
  left_forward();
  right_forward();
}
