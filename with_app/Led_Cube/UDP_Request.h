// UDPService.h

#ifndef _UDPSERVICE_h
#define _UDPSERVICE_h


#include <Arduino.h>

void udp_request_handler();             // FUNCTION TO HANDLE THE UDP REQUEST
void udp_begin(uint16_t port);
String convertTo(char* a);
#endif
