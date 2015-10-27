

// the goal of this program is to run three pairs of lights at specified times. 

//first, we must designate our leds 

//right side
int right_motor_enable =10  
int right_motor_forwards =11 
int right_motor_reverse = 12

//left side

int left_motor_enable = 9 
int left_motor_forwards = 8
int left_motor_reverse = 7

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(right_motor_forward, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(left_motor_forward, HIGH);
  delay(10000);               // wait for 10 seconds
  digitalWrite(right_motor_forward, LOW);
  digitalWrite(left_motor_forward, LOW);
  digitalWrite(right_motor_stop, HIGH);
  digitalWrite(
  delay(1000);               // wait for a second
}
