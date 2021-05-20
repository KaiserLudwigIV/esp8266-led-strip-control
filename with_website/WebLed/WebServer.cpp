#include <ESP8266WebServer.h>
#include "WebServer.h"
#include "WebPage.h"

ESP8266WebServer server(80);

void sendPage();
void httpNotFound();

void webserver_Setup(){
  server.begin();
  server.on("/", sendPage);
  server.onNotFound(httpNotFound);
  Serial.println("WebServer started.");
}

void sendPage(){
  server.send(200, "text/html", WebPage);
}

void httpNotFound(){
  server.send(404, "text/plain", "404: Das ist die Falsche Addresse! Ruf mich mal an dann erklaere ich es dir nochmal!");
}

void WebPageHandle(){
  server.handleClient();
}
