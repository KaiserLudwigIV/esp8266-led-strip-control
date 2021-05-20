//Dieser Teil des Codes stammt von Ulrich Bien


#include "stringSplit.h"
#include <WString.h>

#define RESULT_SIZE 10

String* splitString(String s, char delimiter) {

   static String result[RESULT_SIZE];                       // Ergebnisfeld

   char deli[] = { delimiter, 0 };                         // Delimiter als C-String

   char buffer[255];                                // Source umkopieren, weil der String von strtok() modifiziert wird.
   strncpy(buffer, s.c_str(), sizeof(buffer));

   for (int i = 0; i < RESULT_SIZE; i++)                    // Ergebnisfeld löschen
      result[i] = "";

   int index = 0;                                   // aktuell zu füllendes Ergebnis-Element

   // Liefert das 1. token
   char* token = strtok(buffer, deli);

   // Liefert die folgenden token
   while (token != NULL) {
      result[index++] = token;
      if (index >= RESULT_SIZE)                             // Abbruch, wenn Ergebnisfeld voll
         break;
      token = strtok(NULL, deli);
   }
   return result;
}
