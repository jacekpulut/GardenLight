// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _GardenLight_H_
#define _GardenLight_H_
#include "Arduino.h"
#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include "WifiConnection.h"
#include "ButtonSwitcher.h"
#include "MQTTDHT.h"
#include <Ticker.h>
#include "MQTT2.h"
#include "MQTTTwilightSwitcher.h"

MQTT2 mqttChannel;
WifiConnection myWifi;
ButtonSwitcher buttonSwitcher(D1, D2, "GardenLight", &mqttChannel);
MQTTPinSwitcher pinSwitcher(D0, "GardenLight", &mqttChannel);
MQTTTwilightSwitcher twilight(&mqttChannel, &pinSwitcher, buttonSwitcher.getPinSwitcher());
MQTTDHT myDHT(D7, DHT22, "GardenLight", &mqttChannel);

Ticker timer1;
boolean shouldPublish = true;
void timer1Callback();

#endif /* _GardenLight_H_ */
