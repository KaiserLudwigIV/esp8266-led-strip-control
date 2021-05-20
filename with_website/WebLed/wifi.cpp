#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include "wifi.h"

const char * ssid = "your-ssid";             // SSID OF WLAN
const char * pwd = "your-pwd";              // PASSWORD OF WLAN
const char* mdnsName = "your-mdns-name";           // DOMAIN NAME FOR mDNS

void wifi_connect();
void startMDNS();

///////////////////////////////////////////////////////////
//     CONNECTS TO WIFI     
///////////////////////////////////////////////////////////
void Wifi_Mdns_Setup(){
  wifi_connect();
  startMDNS();
}

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

///////////////////////////////////////////////////////////
//          Starts mDNS
///////////////////////////////////////////////////////////
void startMDNS() {                              // Start the mDNS responder
  if (!MDNS.begin(mdnsName)){
    Serial.println("Error setting up MDNS responder!");
  }
  else{
    Serial.print("mDNS responder started: http://");
    Serial.print(mdnsName);
    Serial.println(".local");
  }
}
