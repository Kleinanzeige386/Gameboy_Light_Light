#include <stdio.h>
#include<windows.h> //remove

int MATRIXWIDTH = 16;
int MATRIXHEIGHT = 8;
int POINTSTOWIN = 4;
int MSperStep=500;

int ball[]={8,4};
int ballvelocity[]={1,1};
int playerpoints[]={0,0};

void checkVelo();
int checkWin();
void playround();
void simulate();
void moveBall();


/*
Grid:
    00  01  02  03    
    10  11  12  13
    20  21  22  23
    30  31  32  33
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

void checkVelo(){
        if (ball[1]>=(MATRIXHEIGHT-1) || ball[1]<=0)  //Top or Bottom
    {
        ballvelocity[1] *= -1;
    }else if (ball[0]>=(MATRIXWIDTH-1) || ball[0]<=0)   //Right or Left
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
    while(checkWin()==0){
        Sleep(MSperStep); // Replace with delay(x)
        
        checkVelo();
    
        moveBall();

        simulate(); //Remove
        
    }

}

void simulate(){ //Remove
    /*
    * SIMULATION START
    */

   printf("\n Ball:  %d|%d\n",ball[0],ball[1]);
    for (int i = 0; i < MATRIXHEIGHT ; i++) //Go through Matrix rows
    {
        printf("\n"); //Start new row
        
        for (int  j = 0; j < MATRIXWIDTH ; j++)//Go through Matrix Collumns
        {
          
            if ((ball[0]==j) && (ball[1]==i)) //Is Ball in that position?
            {
                printf("O ");
            }else{
                printf("- ");
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
        playround();
      
    }

    scanf(("End"));

    

    return 0;
}
