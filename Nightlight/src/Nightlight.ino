/*
 * Project Nightlight
 * Description:
 * Author:
 * Date:
 */

#include "Grove_ChainableLED.h"
ChainableLED leds(A4, A5, 1);

double currentLightLevel;

int toggleLed(String args) {
leds.setColorHSB(0, 0.0, 1.0, 0.5);
return 1;
}


void setup() {
  // Put initialization like pinMode and begin functions here.
pinMode(A0, INPUT);
leds.init();
leds.setColorHSB(0, 0.0, 0.0, 0.0);


}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
double lightAnalogVal = analogRead(A0);
currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);

Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
if (currentLightLevel > 50) {
toggleLed("");
}

}
