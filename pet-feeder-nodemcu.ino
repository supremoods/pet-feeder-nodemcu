#include <WiFiManager.h>
#include <string>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include "certs.h"
#include <Servo.h> //Servo library
 
Servo myservo; //Servo name is myservo
WiFiUDP ntpUDP;
WiFiServer ESPserver(80);
WiFiManager wifiManager;

NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 0);

String schedId;

void wifiConnect();
void wifiReset();
bool checkIsSched();
