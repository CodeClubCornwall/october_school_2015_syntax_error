

// the goal of this program is to run three pairs of lights at specified times. 

//the LED cluster closest to the Arduio represents the left motor
//the LED cluster furthest from the Arduio represents the right motor

//green LEDs represent the motor enable function
//red LEDs represent the motor forwards function
//yellow LEDs represent the reverse function

#define FORWARD_TIME 10000
#define STOP_TIME 1000
#define REVERSE_TIME 1000

//first, we must designate our leds 

//right side
int right_motor_enable = 10;  
int right_motor_forwards = 12; 
int right_motor_reverse = 11;

//left side

int left_motor_enable = 9; 
int left_motor_forwards = 8;
int left_motor_reverse = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(right_motor_enable ,OUTPUT);     
  pinMode(right_motor_forwards ,OUTPUT);     
  pinMode(right_motor_reverse ,OUTPUT);
  pinMode(left_motor_enable ,OUTPUT);
  pinMode(left_motor_forwards ,OUTPUT);     
  pinMode(left_motor_reverse ,OUTPUT);       
}

// the loop routine runs over and over again forever:
void loop() {
   
  forward_motion();

  delay(FORWARD_TIME);
  
  stop_motion();

  delay(STOP_TIME);
  
  reverse_motion();

  delay(REVERSE_TIME); 
}

void forward_motion() {
  
   digitalWrite(right_motor_forwards, HIGH);   
  digitalWrite(left_motor_forwards, HIGH);
  digitalWrite(right_motor_reverse, LOW);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_enable, HIGH);
  digitalWrite(left_motor_enable, HIGH);

}

void stop_motion() { 
 
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_reverse, LOW);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_enable, LOW);
  digitalWrite(left_motor_enable, LOW);
 
}

void reverse_motion() {
  

  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_reverse, HIGH);
  digitalWrite(left_motor_reverse, HIGH);
  digitalWrite(right_motor_enable, HIGH);
  digitalWrite(left_motor_enable, HIGH);
  
}
