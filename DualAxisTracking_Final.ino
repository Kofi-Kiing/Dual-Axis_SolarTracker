#include <Servo.h>
Servo vertical;
Servo horizontal; 

int threshold = 500;
float vangle;
float hangle;
void setup(){
Serial.begin(9600); 
vertical.attach(6);
horizontal.attach(5);
vertical.write(0);
horizontal.write(0);
delay(1000);
}

void loop() {

// Initialize LDRs
float l1 = analogRead(A1);
float l2 = analogRead(A2);
float l3 = analogRead(A3);
float l4 = (analogRead(A4)/1.4);

//Calculating Average LDR outputs
float avt = (l1+l2)/2;
float avd = (l3+l4)/2;
float avl = (l1+l3)/2;
float avr = (l2+l4)/2;

//Calculating Average of all LDRs
float average = (l1+l2+l3+l4)/4;

//Calculating Difference in Horizointal and Vertical Planes
float dvert = (avt-avd);
float dhoriz = (avl-avr);

//For LDR calibration purposes
Serial.print("dvert is ");
Serial.print(dvert);
Serial.print(" dhoriz is ");
Serial.print(dhoriz);
Serial.print(" l1 is ");
Serial.print(l1);
Serial.print(" l2 is ");
Serial.print(l2);
Serial.print(" l3 is ");
Serial.print(l3);
Serial.print(" l4 is ");
Serial.print(l4);
Serial.print(" average is ");
Serial.print(average);
Serial.print(" vangle is ");
Serial.print(vangle);
Serial.print(" hangle is ");
Serial.print(hangle);
Serial.println();

//Setting limits on angles
if (vangle > 160){
  vangle = 160;
}
if (vangle < 0){
  vangle = 0;
}
if (hangle > 210){
  hangle = 210;
}
if (hangle < 120){
  hangle = 120;
}

//vertical motor
//upward rotation
if (abs(dvert)>=50){ 
    if (dvert > 0){
    
    vertical.write(vangle);
    vangle -=7;
    delay(50);
            
  }

  //downard rotation
  if (dvert < 0){
  
    vertical.write(vangle);
    vangle +=7;
    delay(50);
      
  } 
 
}

  //horizontal motor
if (abs(dhoriz)>= 100){
  //leftward rotation
  if (dhoriz > 0){
    
    horizontal.write(hangle);
    hangle -= 5;
    delay(100);
            
  }

  //rightward rotation
  if (dhoriz < 0){
  
    horizontal.write(hangle);
    hangle += 5;
    delay(100);
    }
    
      
  } 
}







