#include <ESP8266mDNS.h>
#include </wifi/wifi.h>
#include "WebServer.h"
#include "WebSocket.h"
#include "LedModi.h"


void setup() {
  Serial.begin(115200);
  Wifi_Mdns_Setup();
  webserver_Setup();
  WebSocket_Setup();
  led_begin();
}

void loop() {
  MDNS.update();
  WebPageHandle();
  WebSocketLoop();
  led_mode_sort();
}
