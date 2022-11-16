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
//void DrawSetup();
void PongSetup();

//Pong
int pongMain(); //Main program

void playRound();   //plays a round of Pong until one Player scores a point
void resetRound();  //resets all needed variables
bool checkWin();     //checks whether the ball hits a goal

void moveBall();//moves the ball 1 space in each of its directions
int hitsPlayer();
void checkBallVelo();   //checks whether the ball hits a border / Player

void changeBotVeloSmart();  //Used by bot player to track the ball movement
void movePlayers();    //moves players


void getPlayerInput(); //Change Position to Poti status

void writePongOutput(); // Write Coords to Matrix
void drawPongDelay(int n);