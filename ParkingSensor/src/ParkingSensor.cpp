/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/andrewleonard/Desktop/LabAndProjects/ParkingSensor/src/ParkingSensor.ino"
/*
 * Project ParkingSensor
 * Description: This app will use the chainable led and ultrasonic sensor to create a parking sensionr
 * Author:Andrew Leonard
 * Date:09/29/2022
 */

#include <Grove_ChainableLED.h> 
#include <Grove-Ultrasonic-Ranger.h> 
#include <twilio.h>

void setup();
void loop();
#line 12 "/Users/andrewleonard/Desktop/LabAndProjects/ParkingSensor/src/ParkingSensor.ino"
Ultrasonic ultrasonic(D4);  
ChainableLED leds(D2, D3, 1);  
int BuzzerPin = A0;  

float distance1 = 4.0; // car parked range boundary


String body = "Stop! Your Car is Parked!"; //message to be sent


void setup() {
  pinMode(BuzzerPin, OUTPUT);// Put initialization like pinMode and begin functions here.
  Serial.begin(9600);             // Begin serial communications
  leds.init();    //leds initialized 


}


void loop() {
 
long RangeININCHES; //dist variable

RangeININCHES = ultrasonic.MeasureInInches();
Serial.print(RangeININCHES);
Serial.println(" IN");

if (RangeININCHES > distance1 ){
  leds.setColorRGB(0, 0, 255, 0);//not pulled in far enough
  noTone(BuzzerPin); 
}
else if (RangeININCHES <= distance1)
{
  leds.setColorRGB(0, 255, 0, 0);//parked 
  tone(BuzzerPin, 1000); // Send 1KHz sound through the grove buzzer
  Particle.publish("twilio_sms", body, PRIVATE);
 
}

 delay(100); 
}