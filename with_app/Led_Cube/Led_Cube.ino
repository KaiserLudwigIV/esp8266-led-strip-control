/*
    Name:       Led_Cube.ino
    Created:	  07.04.2020 08:48:13
    Authors:    Maximilian Heppner & Ulrich Bien
*/



#include "UDP_Request.h"
#include "Led_Service.h"
#include "wifi.h"
///////////////////////////////////////////////////////////
//          SETUP FUNCTION
///////////////////////////////////////////////////////////
void setup() {
   Serial.begin(115200);    // START A SERIAL OUTPUT
   led_begin();             // INIT THE LED STRIP AND ITS GIVEN PARAMETERS
   wifi_connect();          
   udp_begin(udpPort);      // BEGIN THE UDP SERVER WITH ITS PORT
}

///////////////////////////////////////////////////////////
//          LOOP FUNCTION
///////////////////////////////////////////////////////////
void loop() {
   checkWifi();
   udp_request_handler();
   led_mode_sort();
}
