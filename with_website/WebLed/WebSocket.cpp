#include <WebSocketsServer.h>
#include <Arduino.h>
#include "WebSocket.h"
#include "stringSplit.h"
#include "LedModi.h"
#include <cstring>
#include <string>

WebSocketsServer webSocket(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);

void WebSocket_Setup(){
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("WebSocket server started.");
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) { // When a WebSocket message is received
  switch (type) {
    case WStype_DISCONNECTED:             // if the websocket is disconnected
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {              // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:                     // if new text data is received
      Serial.println((char*)payload);
      String WebContent = (char*) payload;
      String* sa = splitString(WebContent, ':');
      String msg = sa[0];
      String param = sa[1];
      Serial.println(param);
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
  }
}

void WebSocketLoop(){
  webSocket.loop();
}
