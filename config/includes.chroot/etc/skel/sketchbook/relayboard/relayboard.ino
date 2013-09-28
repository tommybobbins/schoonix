/*
  Blink relays
  Turns on a relay on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
  tng@chegwin.org
  Thanks to gareth@4tronix.co.uk for both relays blinking mods.
 */

 //Arduino    Sainsmart
 //GND->      Gnd 3 pin header
 //GND->      Gnd 4 pin header
 //5V->       JDVCC
 //None       VCC (3pin header)
 //3.3V->     VCC (4pin header) 
 //Digital7   Int1 (4pin header)
 //Digital8   Int2 (4pin header)


// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int relay1 = 7;
// give it a name:
int relay2 = 8;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
    
}

// the loop routine runs over and over again forever:
void loop() {
digitalWrite(relay1, HIGH); 
delay(300); // gives time to hear 2 clicks (one ON, the other OFF)
digitalWrite(relay2, LOW);
delay(2000); // wait for a second
digitalWrite(relay1, LOW); 
delay(300); // gives time to hear 2 clicks (one ON, the other OFF)
digitalWrite(relay2, HIGH);
delay(2000); // wait for a second
}
