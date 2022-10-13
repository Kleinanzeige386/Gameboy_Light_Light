#include <stdio.h>;

int MATRIXWIDTH = 16;
int MATRIXHEIGHT = 8;
int POINTSTOWIN = 4;

char * PLAYERTOKEN = "O";
char* EMPTYTOKEN = "-";

int ball[]={0,0};
int ballvelocity[]={1,1};
int playerpoints[]={0,0};

void checkVelo();
int checkWin();
void playround();
void simulate();
void moveBall();


int checkWin(){    //Is Ball on the far left or right side of the Matrix?
    if (ball[1]==(MATRIXHEIGHT-1)) //Right Side
    {
        playerpoints[0]++;
        return 1;   //Left Player wins
    }else if (ball[1]==0)   //Left Side
    {
        playerpoints[1]++;
        return 2; //Right Player wins
    }
    return 0;
    
}

void moveBall(){
    ball[0]+=ballvelocity[0];
    ball[1]+=ballvelocity[1];
}

void playround(){
    while(checkWin()==0){
        checkVelo();
        moveBall();

        simulate();
    }
}

void simulate(){
    /*
    * SIMULATION START
    */
    for (int i = 0; i < MATRIXHEIGHT ; i++) //Go through Matrix rows
    {
        printf("\n"); //Start new row
        for (int  j = 0; j < MATRIXWIDTH ; j++)//Go through Matrix Collumns
        {
            if ((ball[0]==j) && (ball[1]==i)) //Is Ball in that position?
            {
                printf(PLAYERTOKEN);
            }else{
                printf(EMPTYTOKEN);
            }

            
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

    }

  



    

    return 0;
}
