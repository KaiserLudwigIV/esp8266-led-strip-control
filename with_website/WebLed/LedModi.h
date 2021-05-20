// Led_Service.h

#ifndef _LEDMODI_h
#define _LEDMODI_h

#include <Arduino.h>

///////////////////////////////////////////////////////////
//          GLOBAL VARS FOR SETTINGS AND LED MODES
///////////////////////////////////////////////////////////
// definiert in Led_service.cpp
extern String MODUS;                           // INT TO HOLD THE CURRENT MODE
extern volatile uint16_t H;                    // INT TO HOLD CURRENT HUE ------------ ANYTHING BETWEEN 0 - 255
extern volatile uint16_t S;                    // INT TO HOLD CURRENT SATURATION ----- ANYTHING BETWEEN 0 - 255
extern volatile uint16_t V;                    // INT TO HOLD CURRENT VALUE ---------- ANYTHING BETWEEN 0 - 255
extern volatile uint16_t DELAY_P;              // INT TO HOLD CURRENT SPEED/ DELAY

extern volatile boolean STATIC_TEST;           // TEST IF STATIC SHOULD CHANGE COLOR
extern volatile uint8_t WAHRSCHEINLICHKEIT;    // INT FOR STROBE OR RANDOMSTROBE TO HOLD PROPABILITY
extern volatile int L_W_WIDTH;
extern String MA_PARAM;
extern volatile boolean MA_TEST;

void led_mode_sort(); // SORT BY MODE AND PLAY IT
void led_begin();
void e_off();

#endif
