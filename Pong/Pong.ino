

/*
 * Includes
 */
#include <Arduino.h>
#include "Project.h"


/*
* IDK why but Arduino wants this to be here??
*/
const byte row1[8] = {
  ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8,
};
const byte row2[8] = {
   ROW_9, ROW_10, ROW_11, ROW_12, ROW_13, ROW_14, ROW_15, ROW_16
};
const byte col1[8] = {
  COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};
const byte col2[8] ={
   COL_9, COL_10, COL_11, COL_12, COL_13, COL_14, COL_15, COL_16
};


enum Border{LEFT_BORDER = 0, RIGHT_BORDER = MATRIXWIDTH-1, UPPER_BORDER = 0, LOWER_BORDER = MATRIXHEIGHT-1, };
enum Direction{LEFT = -1, RIGHT = 1,UP = -1,DOWN = 1};

typedef struct Player{
    int yCoordinate;
    Border border;
    Direction direction;
}Player;


/*
 *  Global variables
 */
int game=0; //Number of Games played
int playerPoints[2];    //Points achieved by   User | Bot

int ball[2];    // x | y coordinates of the ball
Direction ballVelocity[2];    // x | y directions of the ball

Player user;    // Human player
Player bot;     // Bot player

int GameOutput = 0;



/*
 * Grid schema
 *
 *
 *Grid:
 *   00  10  20  30 .. n0
 *   01  11  21  31 .. n1
 *   02  12  22  32 .. n2
 *   04  13  23  33 .. n3
 *   ..  ..  ..  ..    ..
 *   0n  1n  2n  3n .. nn
 */




/*
 * Functions
 */


void PongSetup(){

    ball[0]=MATRIXWIDTH/2;
    ball[1]=MATRIXHEIGHT/2;
    ballVelocity[0]=DOWN;
    ballVelocity[1]=RIGHT;

    user.border = LEFT_BORDER;
    user.yCoordinate = -1 + MATRIXHEIGHT/2;
    user.direction = DOWN;

    bot.border = RIGHT_BORDER;
    bot.yCoordinate = -1 + MATRIXHEIGHT/2;
    bot.direction = DOWN;
}

int pongMain(){



    //Play Rounds until one Player reached the required Points
    while((playerPoints[0]<=POINTSTOWIN) && (playerPoints[1]<=POINTSTOWIN)){
        playRound();
        game +=1;
    }


    return 0;
}


void playRound(){
    resetRound();
    drawPongDelay(50);

  
    while(!checkWin()){
      movePlayers();
      moveBall();
      
      writePongOutput();
      drawPongDelay(MSperStep); 
    }

}

void resetRound(){
    ball[0]=MATRIXWIDTH/2;
    ball[1]=MATRIXHEIGHT/2;

    ballVelocity[0]=DOWN;
    ballVelocity[1]=RIGHT;


    bot.yCoordinate = -1 + MATRIXHEIGHT/2;
    bot.direction = DOWN;
}

bool checkWin(){

    //Is Ball on the far left or right side of the Matrix?
    if (ball[0] == (RIGHT_BORDER))
    {
        playerPoints[0]++;
        return true;   //Left Player wins
    }else if (ball[0] == LEFT_BORDER)
    {
        playerPoints[1]++;
        return true; //Right Player wins
    }

    return false;

}


void moveBall(){
    checkBallVelo();
    ball[0]+=ballVelocity[0];
    ball[1]+=ballVelocity[1];
}

int hitsPlayer(){// -1 == user | 1 == bot | 0==false
    if( ball[0]==LEFT_BORDER+1 ){ //does ball hit user?
        if( (ball[1]== user.yCoordinate) || (ball[1]== user.yCoordinate+1)){
            return -1;
        }
    }

    if( ball[0]==RIGHT_BORDER-1 ){ //does ball hit bot?
        if(( ball[1]== bot.yCoordinate) || (ball[1]== bot.yCoordinate+1)){
            return 1;
        }
    }

    return 0; //ball doesnt hit anything
}

void checkBallVelo(){
    if( ( hitsPlayer()== -1))//Ball hits User
    {
        ballVelocity[0] = RIGHT;
    }

    if( ( hitsPlayer()== 1) )//Ball hits leftBorder or User
    {
        ballVelocity[0] = LEFT;
    }


    if( ball[1] == UPPER_BORDER)//Ball hits UpperBorder
    {
        ballVelocity[1] = DOWN;
    }

    if( ball[1] == LOWER_BORDER)//Ball hits LowerBorder
    {
        ballVelocity[1] = UP;
    }


}


Player changeBotVeloSmart(Player player){ //Adjust Bot position to ball coordinates

    if(player.yCoordinate+1 > ball[1]){ //Is players head lower than ball?
        player.direction =UP;                                                                                                             //              bot
    }                                                                                                                                     //              bot+1
    if ((player.yCoordinate)<ball[1]){ //Is players body higher than ball?
        player.direction = DOWN;
    }


    switch (player.yCoordinate)    //Make sure Player doesnt collide with border
    {
        case UPPER_BORDER: //Head hits upper Border
            player.direction = DOWN;
            break;

        case LOWER_BORDER: //Body hits lower Border
            player.direction =UP;
            break;

        default:
            break;
    }

    return player;
}

void movePlayers(){
  
    getPlayerInput(); //Get Player position from Input


    

    bot = changeBotVeloSmart(bot);
    bot.yCoordinate  += bot.direction;
}


void getPlayerInput(){
    readPoti(); //Update poti variable
    user.yCoordinate = GameOutput; //Set player coordinates to input
}


void writePongOutput(){
  byte temp[16];
  
  createBitMap(temp,16);

  drawBitOnMap(ball[0],ball[1],temp);



  drawBitOnMap(0, user.yCoordinate,temp);
  drawBitOnMap(0, user.yCoordinate+1,temp);

  drawBitOnMap(MATRIXWIDTH-1, bot.yCoordinate,temp);
  drawBitOnMap(MATRIXWIDTH-1, bot.yCoordinate+1,temp);

  
  drawBitmapToScreen(temp);
  

}

void drawPongDelay(int n){
  for(int i=0; i<n; i++){
    delay(1);
    writePongOutput();
  }
}