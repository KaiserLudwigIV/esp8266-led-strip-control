#include <WiFiUdp.h>                        // LIB FOR UDP CONNECTION
#include "UDP_Request.h"
#include "Led_Service.h"
#include "stringSplit.h"
#include <cstring>
#include <string>

char buffer[50];                            // BUFFER TO HOLD INCOMING PACKETS OF UDP
WiFiUDP udp;                                // INIT UDP

void udp_begin(uint16_t port) {
   udp.begin(port);
}

///////////////////////////////////////////////////////////
//          FUNCTION TO HANDLE THE UDP REQUEST
///////////////////////////////////////////////////////////
void udp_request_handler() {
   int packetSize = udp.parsePacket();                         // LISTEN FOR INCOMING PACKETS
   if (packetSize) {                                     // BUFFER TO HOLD INCOMING PACKETS OF UDP// IF THERE ARE PACKETS, START THIS
      udp.read(buffer, packetSize);
      Serial.println((char*)buffer);                            // PRINT THE RECIEVED MSG TO SERIAL
      String udpContent = buffer;
      String* sa = splitString(udpContent, ':');              // Aufteilen
      String msg = sa[0];                                     // Kopieren, weil das nächste Split den Inhalt von 'sa' zerstört.
      String param = sa[1];
      if (msg == "mode"){
        MODUS = param;
        if(param == "ma_one"){e_off();}
      }
      else if(msg == "H"){
        H = atoi(param.c_str());
        STATIC_TEST = 1;
      }
      else if(msg == "S"){
        S = atoi(param.c_str());
        STATIC_TEST = 1;
      }
      else if(msg == "V"){
        V = atoi(param.c_str());
        STATIC_TEST = 1;
      }
      else if(msg == "D"){
        DELAY_P = atoi(param.c_str());
      }
      else if(msg == "A"){
        WAHRSCHEINLICHKEIT = atoi(param.c_str());
      }
      else if(msg == "W"){
        L_W_WIDTH = atoi(param.c_str());
      }
      else if(msg == "MA"){
        MA_PARAM = param;
        MA_TEST = 1;
      }
      memset(buffer, 0, sizeof(buffer));                        // EMPTY THE BUFFER AGAIN FOR THE NEXT REQUEST
   }
}
