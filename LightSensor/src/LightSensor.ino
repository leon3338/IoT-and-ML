/*
 * Project LightSensor
 * Description:Use of light sensor
 * Author:Andrew Leonard
 * Date:09/22/2022
 */

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