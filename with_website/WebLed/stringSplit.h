// stringSplit.h
//Dieser Teil des Codes stammt von Ulrich Bien

#ifndef _STRINGSPLIT_H
#define _STRINGSPLIT_H
#include <WString.h>


// Teilt einen String in einezelne Teilstrings anhand eines Delimiters
// Liefert ein String-Array mit der Größe RESULT_SIZE
// Nicht gefüllte Elemente sind "".
// Gibt es mehr als RESULT_SIZE Teilstrings wird der Rest verworfen.
String* splitString(String s, char delimiter);

#endif
