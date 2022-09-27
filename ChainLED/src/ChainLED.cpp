/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/andrewleonard/Desktop/LabAndProjects/ChainLED/src/ChainLED.ino"
/*
 * Project ChainLED
 * Description: Using Chain LEd
 * Author:Andrew Leonard
 * Date:09/22/2022
 */
#include "Grove_ChainableLED.h"
int toggleLed(String args);
void setup();
void loop();
#line 8 "/Users/andrewleonard/Desktop/LabAndProjects/ChainLED/src/ChainLED.ino"
ChainableLED leds(A4, A5, 1);

int toggleLed(String args) {
leds.setColorHSB(0, 0.0, 1.0, 0.5);

delay(500);

leds.setColorHSB(0, 0.0, 0.0, 0.0);

delay(500);

return 1;
}


// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
leds.init();
leds.setColorHSB(0, 0.0, 0.0, 0.0);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
toggleLed("");

}