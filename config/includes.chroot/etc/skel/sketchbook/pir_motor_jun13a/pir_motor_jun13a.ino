const int 
PWM_A   = 3,
DIR_A   = 12,
led = 13,
BRAKE_A = 9,
pirPin = 2,
SNS_A   = A0;


  int loopCounter = 0;
  char buf[20];
  
void setup() {
  // Configure the A output
  pinMode(BRAKE_A, OUTPUT);  // Brake pin on channel A
  pinMode(DIR_A, OUTPUT);    // Direction pin on channel A
  pinMode(led, OUTPUT);  
  pinMode(pirPin, INPUT);
  digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
;

  // Open Serial communication
  Serial.begin(9600);
}

void loop() {

  int pirVal = digitalRead(pirPin);

  if(pirVal == LOW){ //was motion detected
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BRAKE_A, LOW);  // setting brake LOW disable motor brake
  digitalWrite(DIR_A, HIGH);   // setting direction to HIGH the motor will spin forward
  analogWrite(PWM_A, 255);     // Set the speed of the motor, 255 is the maximum value
  // now stop the motor by inertia, the motor will stop slower than with the brake function
  analogWrite(PWM_A, 0);       // turn off power to the motor
  delay(1000);
  loopCounter++;
  sprintf(buf, "%d :Motion Detected", loopCounter);
  Serial.println(buf);
  }
  
}
