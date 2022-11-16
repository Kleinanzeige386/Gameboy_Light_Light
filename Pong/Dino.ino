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

void dinoSetup(){
Obstacle temp;
  temp.xCoordinate= MATRIXWIDTH-1;
  temp.height = 0;
  for(int i=0; i<100;i++){
    obstacles[i] = temp;
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
  byte temp[16];
  
  createBitMap(temp,16);

  drawBitOnMap(2,MATRIXHEIGHT-2-dino,temp);
  drawBitOnMap(2,MATRIXHEIGHT-3-dino,temp);

  for(int i=0;i<MATRIXWIDTH;i++){
    drawBitOnMap(i,MATRIXHEIGHT-1,temp);
  }

  for(int i=0; i<100;i++){
    for(int j=0; j<obstacles[i].height;j++){
      drawBitOnMap(obstacles[i].xCoordinate,MATRIXHEIGHT-j-1,temp);
    }
  }


  drawBitmapToScreen(temp);
  

}

void drawDinoDelay(int n){
  for(int i=0; i<n; i++){
    delay(1);
    writePongOutput();
  }
}