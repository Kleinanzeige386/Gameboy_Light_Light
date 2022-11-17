/*
 * Includes
 */
#include "Project.h"




void setup() {
    

    pinMode(LED_BUILTIN, OUTPUT); //Why this here?
    Potisetup();
    DrawSetup();
    PongSetup();
    DinoSetup();
    IRRemoteSetup();
}


void loop(){
  while(1){
  int input = readIRRemote();
  

  switch(input){
    case 0:
      pongMain();
    break;

    case 1:
      dinoMain();
    break;
  
    case 10:
      heartBeat();
  }
  
  }
  
}


void heartBeat(){
  while(1){
    for(int i=0; i<50;i++){
      beat1();
    }
    for(int i=0; i<20;i++){
      beat2();
    }
  }
  
}

void beat1(){
  
  byte temp[16];
  
  createBitMap(temp,16);

  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2-1,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2-1,temp);
  
  drawBitmapToScreen(temp);


}

void beat2(){
byte temp[16];
  
  createBitMap(temp,16);

  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2-1,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2-1,temp);

  drawBitOnMap(MATRIXWIDTH/2-2, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2-2, MATRIXHEIGHT/2-1,temp);

  drawBitOnMap(MATRIXWIDTH/2+1, MATRIXHEIGHT/2,temp);
  drawBitOnMap(MATRIXWIDTH/2+1, MATRIXHEIGHT/2-1,temp);

  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2-2,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2-2,temp);

  drawBitOnMap(MATRIXWIDTH/2, MATRIXHEIGHT/2+1,temp);
  drawBitOnMap(MATRIXWIDTH/2-1, MATRIXHEIGHT/2+1,temp);
  
  drawBitmapToScreen(temp);

}

