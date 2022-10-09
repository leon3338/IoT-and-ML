/*
 * Project ParkingSensor
 * Description: This app will use the chainable led, ultrasonic sensor, and buzzer for creating a parking sensor
 * it also includes an integration with twilio to send a sms message. 
 * Author:Andrew Leonard
 * Date:09/29/2022
 */

#include <Grove_ChainableLED.h> 
#include <Grove-Ultrasonic-Ranger.h> 
#include <twilio.h>

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
  Particle.publish("twilio_sms", body, PRIVATE);//does this publishing rate need to be adjusted so the message will actually trigger to phone?
 
}

 delay(100); 
}