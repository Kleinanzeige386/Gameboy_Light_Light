/*
 * Includes
 */
#include "Project.h"

int input; 



void setup() {

    input=1;
    
    pinMode(LED_BUILTIN, OUTPUT); //Why this here?
    Potisetup();
    DrawSetup();
    PongSetup();
    DinoSetup();
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