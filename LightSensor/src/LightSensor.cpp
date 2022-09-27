/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/andrewleonard/Desktop/LabAndProjects/LightSensor/src/LightSensor.ino"
/*
 * Project LightSensor
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "/Users/andrewleonard/Desktop/LabAndProjects/LightSensor/src/LightSensor.ino"
double currentLightLevel;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
pinMode(A0, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
double lightAnalogVal = analogRead(A0);
currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);

if (currentLightLevel > 50) {
Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
}
}