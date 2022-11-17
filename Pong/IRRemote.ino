#include  <IRremote.h>
#include "Project.h"

int RECV_PIN = 7; //in pin

IRrecv irrecv(RECV_PIN);

decode_results results;

int dot[2];    // x | y coordinates of the dot
Direction dotVelocity[2];    // x | y directions of the dot


void IRRemoteSetup(){
  dot[0]=MATRIXWIDTH/2;
  dot[1]=MATRIXHEIGHT/2;
  dotVelocity[0]=DOWN;
  dotVelocity[1]=RIGHT;
  irrecv.enableIRIn();
}

int signalToInt(int signal){
  switch(signal){
  case	ZERO	      : return 0	;
  case	ONE	        : return 1	;
  case	TWO	        : return 2	;
  case	THREE	      : return 3	;
  case	FOUR	      : return 4	;
  case	FIVE	      : return 5	;
  case	SIX	        : return 6	;
  case	SEVEN	      : return 7	;
  case	EIGHT	      : return 8	;
  case	NINE	      : return 9	;
  case	PWR	        : return 10	;
  case	MODE	      : return 11	;
  case	MUTE	      : return 12	;
  case	STOP_RESUME	: return 13	;
  case	LAST	      : return 14	;
  case	NEXT	      : return 15	;
  case	EQ	        : return 16	;
  case	MINUS	      : return 17	;
  case	PLUS	      : return 18	;
  case	SNAKE	      : return 19	;
  case	USDOLLAR	  : return 20	;

  default           : return -1;

  }

}



int readIRRemote(){
  int input=-1;

  while(input == -1){
    idle();
    if(irrecv.decode(&results)){
      input= signalToInt(results.value);
      
      irrecv.resume();
    }
  }
  return input;
}

void movedot(){
    checkdotVelo();
    dot[0]+=dotVelocity[0];
    dot[1]+=dotVelocity[1];

    if(dot[0]==0 || dot[0]==MATRIXWIDTH-1){
      if(dot[1]==0 || dot[1]== MATRIXHEIGHT-1){
        for(int i=0; i<10;i++){
          byte temp[16];
          createBitMap(temp,16);

          drawBitOnMap(dot[0],dot[1],temp);
         

          drawBitmapToScreen(temp);
          delay(50);
        }
      }
    }

    
}

void checkdotVelo(){
    if( dot[0] == LEFT_BORDER)//dot hits left Border
    {
        dotVelocity[0] = RIGHT;
    }

    if( dot[0] == RIGHT_BORDER )//dot hits right Border
    {
        dotVelocity[0] = LEFT;
    }


    if( dot[1] == UPPER_BORDER)//dot hits UpperBorder
    {
        dotVelocity[1] = DOWN;
    }

    if( dot[1] == LOWER_BORDER)//dot hits LowerBorder
    {
        dotVelocity[1] = UP;
    }


}

void idle(){
  byte temp[16];
  movedot();
  createBitMap(temp,16);

  drawBitOnMap(dot[0],dot[1],temp);

  drawBitmapToScreen(temp);
}