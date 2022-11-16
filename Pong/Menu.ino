/*
 * Includes
 */
#include "Project.h"

int input;



void setup() {

    input=1;
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    Potisetup();

    for (int i = 22; i <= 52; i += 2){
        pinMode(i, OUTPUT);
    }
    for (int i = 23; i <= 53; i += 2){
        pinMode(i, OUTPUT);
    }

    dinoSetup();
}


void loop(){
  switch(input){
    case 0:
      pongMain();
    break;

    case 1:
      dinoMain();
    break;
  }
  
  delay(100000);
}