#ifndef _LED_CUBE_h
#define _LED_CUBE_h

///////////////////////////////////////////////////////////
//          SETTINGS FOR: WIFI, UDP, UDP BUFFER, LEDS
///////////////////////////////////////////////////////////
extern const char * ssid;      // SSID OF WLAN (definiert in wifi.cpp)
extern const char * pwd;       // PASSWORD OF WLAN
extern const int udpPort;      // PORT OF UDP

#define NUM_LEDS 20                         // AMOUNT OF LEDS IN STRIP
#define FASTLED_DATA_PIN 6                  // USED DATAOUT PIN

#endif
