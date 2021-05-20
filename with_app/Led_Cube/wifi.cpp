#include <ESP8266WiFi.h>                    // LIB FOR WiFi
#include "wifi.h"

const char * ssid = "your-ssid";             // SSID OF WLAN
const char * pwd = "your-pwd";              // PASSWORD OF WLAN
const int udpPort = 2001;                   // PORT OF UDP

///////////////////////////////////////////////////////////
//     CONNECTS TO WIFI     
///////////////////////////////////////////////////////////
void wifi_connect() {
   WiFi.setSleepMode(WIFI_NONE_SLEEP);
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, pwd);                       // FOLLOWING CODE IS A STANDART WIFI CONNECT WALKTHROUGH
   while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
   }
   Serial.println("");
   Serial.print("Connected to ");
   Serial.println(ssid);
   Serial.print("IP address: ");
   Serial.println(WiFi.localIP());
   Serial.print("Port: ");
   Serial.println(udpPort);
}

///////////////////////////////////////////////////////////
//          RECONNECTS TO WIFI
///////////////////////////////////////////////////////////
void wifi_reconnect() {
   WiFi.mode(WIFI_OFF);         // WIFI IS TURNED OFF
   WiFi.begin(ssid, pwd);       // FOLLOWING CODE IS A STANDART WIFI CONNECT WALKTHROUGH
   while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
   }
   Serial.println("");
   Serial.print("Connected to ");
   Serial.println(ssid);
   Serial.print("IP address: ");
   Serial.println(WiFi.localIP());
}


///////////////////////////////////////////////////////////
//          CHECKS WIFI Connection
///////////////////////////////////////////////////////////
void checkWifi() {
   if (WiFi.status() != WL_CONNECTED) {
      wifi_reconnect();
   }
}
