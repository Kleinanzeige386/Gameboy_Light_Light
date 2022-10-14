#include <stdio.h>
#include<windows.h> //remove
#include <conio.h>



int MATRIXWIDTH = 16;
int MATRIXHEIGHT = 8;
int POINTSTOWIN = 4;
int MSperStep=100;

int ball[]={8,4};
int ballvelocity[]={1,1};

int player=0;
int bot=0;
int playervelocity=-1; //replace wit poti
int botvelocity=-1;
int playerpoints[]={0,0};

void checkVelo();
int checkWin();
void playround();
void simulate();
void movePlayers();
void moveBall();
bool isXBorder(int n);
bool isYBorder(int n);


/*
Grid:
    00  10  20  30
    01  11  21  31
    02  12  22  32
    04  13  23  33
*/



int checkWin(){    //Is Ball on the far left or right side of the Matrix?
/*
    if (ball[1]==(MATRIXHEIGHT-1)) //Right Side
    {
        playerpoints[0]++;
        return 1;   //Left Player wins
    }else if (ball[1]==0)   //Left Side
    {
        playerpoints[1]++;
        return 2; //Right Player wins
    }
    */
    return 0;
    
}

bool isYBorder(int n){
    if (n>=(MATRIXHEIGHT-1) || n<=0) return true;
    return false;
}

bool isXBorder(int n){
    if (n>=(MATRIXWIDTH-1) || n<=0) return true;
    return false;
}

void movePlayers(){
    if (isYBorder(player) || isYBorder(player+1))
    {
        playervelocity *= -1;
    }

    if (isYBorder(bot) || isYBorder(bot+1))
    {
        botvelocity *= -1;
    }

    player += playervelocity;
    bot += botvelocity;
    
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

void moveBall(){
    ball[0]+=ballvelocity[0];
    ball[1]+=ballvelocity[1];
}

void playround(){

    printf("\n%d : %d",playerpoints[0],playerpoints[1]); //REMOVE
    simulate(); //Remove
    int iterations=0;
    int outOfBounds=0;

    while(checkWin()==0){

    //    if( (ball[1]>(MATRIXHEIGHT-1))   ||  (ball[0]>(MATRIXWIDTH-1 ))  ||  ball[0]<0   ||  ball[1]<0      ){outOfBounds++;} //remove
    //    printf("\n\nIteration %10d                Times out of Bounds: %d",++iterations,outOfBounds);   //remove

        Sleep(MSperStep); // Replace with delay(x)
       
        movePlayers(); 
        checkVelo();
        
        moveBall();

       system("cls");   //remove
       simulate(); //Remove
        
    }

}

void simulate(){ //Remove
    /*
    * SIMULATION START
    */

   printf("\n Ball:  %d|%d\n Player:  0 |%d\n Bot:  15 |%d\n\n",ball[0],ball[1],player,bot);
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
    
   /*
    * SIMULATION END
    */
}

int main(int argc, char const *argv[])
{

    while((playerpoints[0]<POINTSTOWIN) && (playerpoints[1]<POINTSTOWIN)){
        playround();
      
    }

    scanf(("\nEnd\n"));

    

    return 0;
}
