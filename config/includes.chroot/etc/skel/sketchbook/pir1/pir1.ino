int pirPin = 2; //digital 2
int led = 13;
int squirt = 12;

void setup(){
 Serial.begin(9600); 
 pinMode(squirt, OUTPUT);
 pinMode(pirPin, INPUT);
 pinMode(led, OUTPUT);  
 digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
 digitalWrite(squirt, LOW);   // turn the Squirter off (LOW is the voltage level)
}



void loop(){
  int pirVal = digitalRead(pirPin);

  if(pirVal == LOW){ //was motion detected
    Serial.println("Motion Detected"); 
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(squirt, HIGH);   // turn the Squirter on (HIGH is the voltage level)
    delay(3000);  
    digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(squirt, LOW);   // turn the Squirter on (HIGH is the voltage level)
    delay(1000); 
            // wait for a second
  }
}
