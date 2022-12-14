/*
 *  Libraries
 */

#include "./Data.h"

/*
 *
 *  Prototypes
 *
 */

//Setup
void Potisetup();
void DrawSetup();
void PongSetup();
void DinoSetup();
void IRRemoteSetup();

//Pong
int pongMain();                     //Main program

void playRound();                   //plays a round of Pong until one Player scores a point
void resetRound();                  //resets all needed variables
bool checkWin();                    //checks whether the ball hits a goal

void moveBall();                    //moves the ball 1 space in each of its directions
int hitsPlayer();
void checkBallVelo();               //checks whether the ball hits a border / Player

void changeBotVeloSmart();          //Used by bot player to track the ball movement
void movePlayers();                 //moves players

void getPlayerInput();              //Change Position to Poti status

void writePongOutput();             //Write Coords to Matrix
void drawPongDelay(int n);          //Alternative delay function : makes sure MatrixLEDs dont flicker (!! since Matrix keeps getting updated the delay here isn't the same amount each time !!)


//Poti
void readPoti();



//Matrix
void createBitMap(byte Bitmap[], int bitmap_Length);

void drawBitOnMap(byte Bitmap[], int bitmap_Length);
void drawBitmapToScreen(byte BITMAP[]); //
void drawScreen(byte buffer2[], byte row[], byte column[]);

void resetDisplay();
void setDisplay();
