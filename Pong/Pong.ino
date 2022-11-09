/*
 * Includes
 */
 #include <Arduino.h>


/*
 * Constants
 */
const int MATRIXWIDTH = 16;     //Number of collumns in the matrix
const int MATRIXHEIGHT = 8;     //Number of rows in the matrix
const int POINTSTOWIN = 100;    //Number of Points, needed to win
const int MSperStep=50;        // Miliseconds between steps



#define ROW_1 22
#define ROW_2 24
#define ROW_3 26
#define ROW_4 28
#define ROW_5 30
#define ROW_6 32
#define ROW_7 34
#define ROW_8 36

#define COL_1 38
#define COL_2 40
#define COL_3 42
#define COL_4 44
#define COL_5 46
#define COL_6 48
#define COL_7 50
#define COL_8 52

#define ROW_9 23
#define ROW_10 25
#define ROW_11 27
#define ROW_12 29
#define ROW_13 31
#define ROW_14 33
#define ROW_15 35
#define ROW_16 37

#define COL_9 39
#define COL_10 41
#define COL_11 43
#define COL_12 45
#define COL_13 47
#define COL_14 49
#define COL_15 51
#define COL_16 53

const byte row1[] = {
  ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8,
};
const byte row2[] = {
   ROW_9, ROW_10, ROW_11, ROW_12, ROW_13, ROW_14, ROW_15, ROW_16
};
const byte col1[] = {
  COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};
const byte col2[] ={
   COL_9, COL_10, COL_11, COL_12, COL_13, COL_14, COL_15, COL_16
};


/*
 * Datatypes
 */
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

int poti=0;

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
 * Function prototypes
 */
int main(); //Main program

void playRound();   //plays a round of Pong until one Player scores a point
void resetRound();  //resets all needed variables
bool checkWin();     //checks whether the ball hits a goal

void moveBall();//moves the ball 1 space in each of its directions
int hitsPlayer();
void checkBallVelo();   //checks whether the ball hits a border / Player

void changeBotVeloSmart();  //Used by bot player to track the ball movement
void movePlayers();    //moves players


void getPlayerInput(); //Change Position to Poti status
void writeOutput(); // Write Coords to Matrix

void Poitsetup();
void DrawSetup();



/*
 * Functions
 */

void setup(){

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Potisetup();
  Drawsetup();
  for (byte i = 22; i <= 52; i += 2)
    pinMode(i, OUTPUT);
  for (byte i = 23; i <= 53; i += 2)
    pinMode(i, OUTPUT);
}



void loop(){
  resetRequest();
drawBitOnMap(4,4);
  Serial.print(getDrawRequest());
for(int i = 0; i < 1000; i++)
  {
drawToScreen();
  }
  delay(1000);
  //main();
}



int main()
{
  /*
    user.border = LEFT_BORDER;
    bot.border = RIGHT_BORDER;

    while((playerPoints[0]<=POINTSTOWIN) && (playerPoints[1]<=POINTSTOWIN)){
        playRound();
        game +=1;
    }
    */
    writeOutput();

    return 0;
}

void playRound(){
    resetRound();

  
    while(!checkWin()){
        readPoti();
        delay(MSperStep); 
        movePlayers();
        moveBall();
        
        writeOutput();

    }

}

void resetRound(){
    ball[0]=8;
    ball[1]=4;

    ballVelocity[0]=DOWN;
    ballVelocity[1]=RIGHT;

    user.yCoordinate = 0;
    user.direction = DOWN;

    bot.yCoordinate = 0;
    bot.direction = DOWN;
}

bool checkWin(){    //Is Ball on the far left or right side of the Matrix?
/*
    if (ball[0] == (RIGHT_BORDER))
    {
        playerPoints[0]++;
        return true;   //Left Player wins
    }else if (ball[0] == LEFT_BORDER)   //Left Side
    {
        playerPoints[1]++;
        return true; //Right Player wins
    }
*/
    return false;

}


void moveBall(){
    checkBallVelo();
    ball[0]+=ballVelocity[0];
    ball[1]+=ballVelocity[1];
}

void checkBallVelo(){
    if( ( ball[0]==LEFT_BORDER ) /*|| ( hitsPlayer()== -1)*/ )//Ball hits leftBorder or User
    {
        ballVelocity[0] = RIGHT;
    }

    if( ( ball[0]==RIGHT_BORDER ) /*|| ( hitsPlayer()== 1)*/ )//Ball hits leftBorder or User
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

int hitsPlayer(){
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
}// -1 == user | 1 == bot | 0==false


Player changeBotVeloSmart(Player player){

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
    user.yCoordinate = poti;
}


byte xToByte(int x){
  switch(x){
    case 0:
      return B10000000;
  
    case 1:
      return B01000000;

    case 2:
      return B00100000;

    case 3:
      return B00010000;

    case 4:
      return B00001000;

    case 5:
      return B00000100;

    case 6:
      return B00000010;

    case 7:
      return B00000001;
  
  }






  

}

void writeOutput(){
  /*
  drawBitOnMap(ball[0],ball[1]);

  drawBitOnMap(0, user.yCoordinate);
  drawBitOnMap(0, user.yCoordinate+1);


  drawBitOnMap(MATRIXWIDTH-1, bot.yCoordinate);
  drawBitOnMap(MATRIXWIDTH-1, bot.yCoordinate+1);
  */
  drawBitOnMap(4,4);

  drawToScreen();

}




