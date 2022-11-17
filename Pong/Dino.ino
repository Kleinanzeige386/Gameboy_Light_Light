/*
 * Includes
 */
#include "Project.h"

typedef struct Obstacle{
    int xCoordinate;
    int height;
}Obstacle;

int dino;
Obstacle obstacles[100];

void DinoSetup(){
Obstacle tempDino;
  tempDino.xCoordinate= MATRIXWIDTH-1;
  tempDino.height = 0;
  for(int i=0; i<100;i++){
    obstacles[i] = tempDino;
  }
}

void dinoMain(){
  dino = 0;
  obstacles[0].height= 1;
  while(!death()){
    makeStep();
  }
}


bool death(){
return false;

}
void makeStep(){
  drawDinoDelay(10);
  writeDinoOutput();
  moveObstacles();
}

void moveObstacles(){
  for(int i=0; i<100;i++){
    obstacles[i].xCoordinate--;
  }
}

void writeDinoOutput(){
  byte tempDino[16];
  
  createBitMap(tempDino,16);

  drawBitOnMap(2,MATRIXHEIGHT-2-dino,tempDino);
  drawBitOnMap(2,MATRIXHEIGHT-3-dino,tempDino);


  for(int i=0;i<MATRIXWIDTH;i++){
    drawBitOnMap(i,MATRIXHEIGHT-1,tempDino);
  }
  

  for(int i=0; i<100;i++){
    for(int j=0; j<obstacles[i].height;j++){
      drawBitOnMap(obstacles[i].xCoordinate,MATRIXHEIGHT-j-1,tempDino);
    }
  }


  drawBitmapToScreen(tempDino);
  

}

void drawDinoDelay(int n){
  for(int i=0; i<n; i++){
    delay(1);
    writeDinoOutput();
  }
}