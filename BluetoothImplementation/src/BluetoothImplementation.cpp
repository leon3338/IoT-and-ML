/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/andrewleonard/Desktop/LabAndProjects/BluetoothImplementation/src/BluetoothImplementation.ino"
/*
 * Project BluetoothImplementation
 * Description:
 * Author:
 * Date:
 */

#include "DiagnosticsHelperRK.h"
#include "Grove_Temperature_And_Humidity_Sensor.h"
void configureBLE();
void setup();
void loop();
#line 10 "/Users/andrewleonard/Desktop/LabAndProjects/BluetoothImplementation/src/BluetoothImplementation.ino"
SYSTEM_THREAD(ENABLED);
DHT dht(D2);
pinMode(A0, INPUT);
double currentLightLevel;
float temp, humidity;
double temp_dbl, humidity_dbl;
const unsigned long UPDATE_INTERVAL = 2000;
unsigned long lastUpdate = 0;
// Private battery and power service UUID
const BleUuid serviceUuid("57f5ed37-d4e9-4b77-8917-c5f4c55e51d9"); // CHANGE ME

BleCharacteristic uptimeCharacteristic("uptime", BleCharacteristicProperty::NOTIFY, BleUuid("fdcf4a3f-3fed-4ed2-84e6-04bbb9ae04d4"), serviceUuid);
BleCharacteristic signalStrengthCharacteristic("strength", BleCharacteristicProperty::NOTIFY, BleUuid("cc97c20c-5822-4800-ade5-1f661d2133ee"), serviceUuid);
BleCharacteristic freeMemoryCharacteristic("freeMemory", BleCharacteristicProperty::NOTIFY, BleUuid("d2b26bf3-9792-42fc-9e8a-41f6107df04c"), serviceUuid);

void configureBLE(){
BLE.addCharacteristic(uptimeCharacteristic);
BLE.addCharacteristic(signalStrengthCharacteristic);
BLE.addCharacteristic(freeMemoryCharacteristic);

BleAdvertisingData advData;

// Advertise our private service only
advData.appendServiceUUID(serviceUuid);

// Continuously advertise when not connected
BLE.advertise(&advData);

}

void setup() {
configureBLE();

Serial.begin(9600);

dht.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

unsigned long currentMillis = millis();
if (currentMillis - lastUpdate >= UPDATE_INTERVAL)
{
 lastUpdate = millis();

 temp = (int)dht.getTempFarenheit();
 humidity = (int)dht.getHumidity();

 Serial.printlnf("Temp: %f", temp);
 Serial.printlnf("Humidity: %f", humidity);

 double lightAnalogVal = analogRead(A0);
 currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);

 if (currentLightLevel > 50)
 {
   Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
 }
}

float temp, humidity;

temp = dht.getTempFarenheit();
humidity = dht.getHumidity();

Serial.printlnf("Temp: %f", temp);
Serial.printlnf("Humidity: %f", humidity);

delay(10000);
}