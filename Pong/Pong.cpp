#include <stdio.h>
#include<windows.h> //remove
#include <conio.h>



int MATRIXWIDTH = 16;
int MATRIXHEIGHT = 8;
int POINTSTOWIN = 100;
int MSperStep=1;
int game=0;

int ball[2];
int ballvelocity[2];

int player;
int bot;
int playervelocity; //replace wit poti
int botvelocity;
int playerpoints[2];



void playround();
void resetround();
void simulate();
int checkWin();

bool isXBorder(int n);
bool isYBorder(int n);
bool hitsPlayers();
void checkVelo();
void changeBotVeloSmart();
void movePlayers();
void moveBall();

/*
Grid:
    00  10  20  30
    01  11  21  31
    02  12  22  32
    04  13  23  33
*/

void playround(){

    printf("\n%d : %d",playerpoints[0],playerpoints[1]); //REMOVE
    simulate(); //Remove
    int iterations=0;//Remove
    int outOfBounds=0;//Remove

    resetround();
    while(checkWin()==0){


        //Sleep(MSperStep); // Replace with delay(x)
       
        movePlayers(); 
        checkVelo();
        
        moveBall();

       system("cls");   //remove
       simulate(); //Remove
        
    }

}

void resetround(){
    ball[0]=8;
    ball[1]=4;

    ballvelocity[0]=1;
    ballvelocity[1]=1;

    player=0;
    bot=0;
    playervelocity=-1; //replace wit poti
    botvelocity=-1;



}

void simulate(){ //Remove
    /*
    * SIMULATION START
    */

   printf("\nGame: %d\n\n Ball:  %d|%d\n Player:  %d\n Bot: %d\n\n",game,ball[0],ball[1],playerpoints[0],playerpoints[1]);

   /*
    for (int i = 0; i < MATRIXHEIGHT ; i++) //Go through Matrix rows
    {
        printf("\n"); //Start new row
        
        for (int  j = 0; j < 16 ; j++)//Go through Matrix Collumns
        {
            char* temp="- ";
          
            if ((ball[0]==j) && (ball[1]==i)) //Is Ball in that position?
            {
                temp="O ";
            }else if (      j==0 && ((player==i)  ||  player==i-1))
            {
                temp="P ";
            }else if (    j==(MATRIXWIDTH-1) && ((bot==i)  ||  bot==i-1))
            {
                temp="B "; 
            }

            printf(temp);
            
        }
        
    }
    printf("\n\n");
    */
    
   /*
    * SIMULATION END
    */
}

int checkWin(){    //Is Ball on the far left or right side of the Matrix?

    if (ball[0]==(MATRIXWIDTH-1)) //Right Side
    {
        playerpoints[0]++;
        return 1;   //Left Player wins
    }else if (ball[0]==0)   //Left Side
    {
        playerpoints[1]++;
        return 2; //Right Player wins
    }

    return 0;
    
}


bool isXBorder(int n){
    if (n>=(MATRIXWIDTH-1) || n<=0) return true;
    return false;
}

bool isYBorder(int n){
    if (n>=(MATRIXHEIGHT-1) || n<=0) return true;
    return false;
}

bool hitsPlayers(){

    switch (ball[0]) //x-Position Ball
    {
    case 1:
        if( (ball[1]==player)   ||  (ball[1]==player+1)   ){
            return true;
        }
        break;

    case 14:
        if( (ball[1]==bot)   ||  (ball[1]==bot+1)   ){
            return true;
        }
        break;    
    
    default:
        return false;
        break;
    }

    return false;
}

void checkVelo(){
    if (isYBorder(ball[1]))  //Top or Bottom
    {
        ballvelocity[1] *= -1;
    }
    if (isXBorder(ball[0]) || hitsPlayers())   //Right or Left
    {
         ballvelocity[0] *= -1;
    }

    

    
}

void movePlayers(){
    changeBotVeloSmart();
    if (isYBorder(player) || isYBorder(player+1))
    {
        playervelocity *= -1;
    }


    player += playervelocity;
    bot += botvelocity;
    
}

void moveBall(){
    ball[0]+=ballvelocity[0];
    ball[1]+=ballvelocity[1];
}

void changeBotVeloSmart(){
    
    if(bot>ball[1]){    
        botvelocity=1;                                                                                                             //              bot
    }                                                                                                                                           //              bot+1
    if ((bot+1)>ball[1])
    {
        botvelocity=-1;
    }


    switch (bot)
    {
    case 0:
            botvelocity=1;
        break;

    case 6:
            botvelocity=-1;
        break;    
    
    default:
        break;
    }

    
}


int main(int argc, char const *argv[])
{

    while((playerpoints[0]<=POINTSTOWIN) && (playerpoints[1]<=POINTSTOWIN)){
        playround();
        game +=1;
    }
    //system("cls");   //remove
    if (playerpoints[0]>playerpoints[1]) printf("player 1 Won!");  else printf("player 2 Won!");
    



    scanf(("\nEnd\n"));

    

    return 0;
}
