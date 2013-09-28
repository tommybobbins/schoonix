int LDR_Pin = A0; //analog pin 0
int led = 13;
//Maximum reading from the LDR with laser on.
int LDR_Maxvalue=1000;
int dot_length=800;
int dash_length=2500;
int letter_pause=2400;
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// 10k between GND and A0
// LDR between 5V and A0


void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);  

  lcd.begin(16,2);
  
}
int counter_high = 0;
int counter_low = 0;

void loop(){

  int LDRReading = analogRead(LDR_Pin); 
//  Serial.println(LDRReading);
  if (LDRReading >= LDR_Maxvalue){
  counter_high++ ;
   if ( counter_low > 0 ){
//     Serial.print("Low\t");
//     Serial.print(counter_low);
//     Serial.print("\n");
   }
   if ( counter_low >= letter_pause) {
      Serial.println();
      lcd.clear();
      lcd.setCursor(0, 0);

  }
      
     counter_low=0;
     digitalWrite(led, HIGH);

  
  } else {
//   Serial.print(".");
  counter_low++;
  if ( counter_high > 0 ){
//      Serial.print("High\t");  
//   Serial.print(counter_high);

  }
  if ( (counter_high <= letter_pause ) &&( counter_high >=dot_length)){
//      Serial.print(counter_high);
    Serial.print(".");
    lcd.print(".");
  }
  if ( counter_high > letter_pause ){
 //         Serial.print(counter_high);
        Serial.print("-");
        lcd.print("-");
  }

      counter_high=0;
      digitalWrite(led, LOW);

  }

 
}
