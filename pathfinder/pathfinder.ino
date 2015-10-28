void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.print(analogRead(0)); 
 Serial.print("   ");
 Serial.print(analogRead(1));
 Serial.print("   ");
 Serial.println(analogRead(2));
 delay(50);
 
}

/* to make a pathfinding program, compare the left and right light sensors to the center censor. If the numerical output of either sensor is less then that of the centeral sensor
rotate the robot in the direction of the sensor. */
