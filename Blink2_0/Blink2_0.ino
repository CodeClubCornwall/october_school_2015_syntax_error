/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_1 = 2;
int led_2 = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_1, OUTPUT);  
  pinMode(led_2, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_1, HIGH);   
  delay(500
  );               
  digitalWrite(led_1, LOW);
  delay(1000);  
  digitalWrite(led_2, HIGH); 
  delay(500);            
  digitalWrite(led_2, LOW);
  delay (1000);  
 
}
