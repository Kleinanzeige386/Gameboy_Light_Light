/*
 * Includes
 */
#include <stdio.h>
#include<windows.h> //remove
#include <conio.h> //remove

#pragma clang diagnostic pop// remove


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Writable-strings"
/*
 * Constants
 */
const int MATRIXWIDTH = 16;     //Number of collumns in the matrix
const int MATRIXHEIGHT = 8;     //Number of rows in the matrix
const int POINTSTOWIN = 100;    //Number of Points, needed to win
const int MSperStep=50;        // Miliseconds between steps


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
int main(int argc, char const *argv[]); //Main program

void playRound();   //plays a round of Pong until one Player scores a point
void resetRound();  //resets all needed variables
bool checkWin();     //checks whether the ball hits a goal

void moveBall();//moves the ball 1 space in each of its directions
int hitsPlayer();
void checkBallVelo();   //checks whether the ball hits a border / Player

void changeBotVeloSmart();  //Used by bot player to track the ball movement
void movePlayers();    //moves players

void simulate();    //Prints the game to the console, !!!!!remove when porting!!!!!


/*
 * Functions
 */

int main(int argc, char const *argv[])
{
    user.border = LEFT_BORDER;
    bot.border = RIGHT_BORDER;

    while((playerPoints[0]<=POINTSTOWIN) && (playerPoints[1]<=POINTSTOWIN)){
        playRound();
        game +=1;
    }
    //system("cls");   //remove
    if (playerPoints[0]>playerPoints[1]) printf("player 1 Won!");  else printf("player 2 Won!");




    scanf(("\nEnd\n")); //remove



    return 0;
}

void playRound(){
    resetRound();

    printf("\n%d : %d",playerPoints[0],playerPoints[1]); //REMOVE
    simulate(); //Remove
    int iterations=0;//Remove
    int outOfBounds=0;//Remove

    while(!checkWin()){
        Sleep(MSperStep); // Replace with delay(x)
        movePlayers();
        moveBall();

        simulate(); //Remove
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

    if (ball[0] == (RIGHT_BORDER))
    {
        playerPoints[0]++;
        return true;   //Left Player wins
    }else if (ball[0] == LEFT_BORDER)   //Left Side
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

void checkBallVelo(){
    if( ( ball[0]==LEFT_BORDER ) || ( hitsPlayer()== -1) )//Ball hits leftBorder or User
    {
        ballVelocity[0] = RIGHT;
    }

    if( ( ball[0]==RIGHT_BORDER ) || ( hitsPlayer()== 1) )//Ball hits leftBorder or User
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
    }                                                                                                                                           //              bot+1
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
    user = changeBotVeloSmart(bot);
    bot = changeBotVeloSmart(user);

    user.yCoordinate += user.direction;
    bot.yCoordinate  += bot.direction;
}


void simulate(){ //Remove
    /*
    * SIMULATION START
    */
    system("cls");
    printf("\nGame: %d\n\n Ball:  %d|%d\n Player:  %d\n Bot: %d\n\n",game,ball[0],ball[1],playerPoints[0],playerPoints[1]);


    for (int i = 0; i < MATRIXHEIGHT ; i++) //Go through Matrix rows
    {
        printf("\n"); //Start new row

        for (int  j = 0; j < 16 ; j++)//Go through Matrix Collumns
        {
            char* temp="- ";

            if ((ball[0]==j) && (ball[1]==i)) //Is Ball in that position?
            {
                temp="O ";
            }else if (      j==0 && ((user.yCoordinate ==i)  ||  user.yCoordinate==i-1))
            {
                temp="P ";
            }else if (    j==(MATRIXWIDTH-1) && ((bot.yCoordinate ==i)  ||  bot.yCoordinate ==i-1))
            {
                temp="B ";
            }

            printf("%s", temp);

        }

    }
    printf("\n\n");


    /*
     * SIMULATION END
     */
}



