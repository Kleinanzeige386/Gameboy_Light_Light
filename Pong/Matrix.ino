/*
 * Includes
 */
#include "Project.h"

/*
The following illustrates the 2 LED-Matrices that are connected to the Microcontroller side by side

1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1

drawBitOnMap() sets the Bit at the PositionX and PositionY so that it is turned on
  PosX is in range 0 to 15
  Posy is in range 0 to 7
*/

void DrawSetup(){
  for (int i = 22; i <= 52; i += 2){
        pinMode(i, OUTPUT);
    }
    for (int i = 23; i <= 53; i += 2){
        pinMode(i, OUTPUT);
    }
}

void drawBitOnMap(byte PosX, byte PosY, byte BITMAP[]){
  if(PosX > 7){
    BITMAP[PosY + 8] ^= (B00000001 << (PosX-8));

  }
  else{
    BITMAP[PosY] ^= (B00000001 << PosX);
  } 
}


// Fills an entire array with Bytes that are all 1 --> The default state of the LED-Matrices for 1 is off
void createBitMap(byte Bitmap[], int bitmap_Length){
  for(byte i = 0; i < bitmap_Length; i++){
    Bitmap[i] = B11111111;
  } 
}


void drawBitmapToScreen(byte BITMAP[]){
  byte Screen1[] = {BITMAP[0],BITMAP[1],BITMAP[2],BITMAP[3],BITMAP[4],BITMAP[5],BITMAP[6],BITMAP[7]};
  byte Screen2[] = {BITMAP[8],BITMAP[9],BITMAP[10],BITMAP[11],BITMAP[12],BITMAP[13],BITMAP[14],BITMAP[15]};

  drawScreen(Screen1, row1, col1);
  drawScreen(Screen2, row2, col2);

}

// Resets the entire display to 0
void resetDisplay() {
  for (byte i = 0; i < 16; i++) {
    digitalWrite(row1[i], LOW);
    digitalWrite(row2[i], LOW);
    for (byte n = 0; n < 16; n++) {
      digitalWrite(col2[n], HIGH);
      digitalWrite(col2[n], HIGH);
    }
  }
}

// sets the entire display to 1
void setDisplay() {
  for (byte i = 0; i < 16; i++) {
    digitalWrite(row1[i], LOW);
    digitalWrite(row2[i], LOW);
    for (byte n = 0; n < 16; n++) {
      digitalWrite(col2[n], HIGH);
      digitalWrite(col2[n], HIGH);
    }
  }
}

/*
Uses an 8 by 8 bitmap to draw Pixels onto the screen

1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1

This would be an example for the 8 by 8 bitmap that
could be drawn onto the display
*/
void drawScreen(byte buffer2[],  byte row[], byte column[]) {
  // Turn on each row in series
  for (byte i = 0; i < 8; i++)  // count next row
  {
    digitalWrite(row[i], HIGH);  //initiate whole row
    for (byte a = 0; a < 8; a++)  // count next row
    {
      // if You set (~buffer2[i] >> a) then You will have positive
      digitalWrite(column[a], (buffer2[i] >> a) & 0x01);  // initiate whole column

      delayMicroseconds(100);  // refresh rate of the display

      digitalWrite(column[a], 1);  // reset whole column
    }
    digitalWrite(row[i], LOW);  // reset whole row
                                 // otherwise last row will intersect with next row
  }
}
