/*
 * Includes
 */
#include "Project.h"

const int buzzer =  2;

int PotiInput = A0;



// SETUP

void Potisetup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}




// LOOP


void readPoti() {
  // put your main code here, to run repeatedly:

 int poti = analogRead(PotiInput);


  if (poti <= 146) // 0
  {
    GameOutput = 0;
  }

  else if (146 <= poti && poti <= 292) // 1
  {
    GameOutput = 1;
  }

  else if (292 <= poti && poti <= 438) // 2
  {
    GameOutput = 2;
  }

  else if (438 <= poti && poti <= 584) // 3
  {
    GameOutput = 3;
  }

  else if (584 <= poti && poti <= 730)  // 4
  {
    GameOutput = 4;
  }

  else if (730 <= poti && poti <= 876) // 5
  {
    GameOutput = 5;
  }

  else if( 876 <= poti && poti <= 1023) // 6
  {
  
    GameOutput = 6;
  }
}