/*
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

#define ROW_9 2
#define ROW_10 3
#define ROW_11 4
#define ROW_12 5
#define ROW_13 6
#define ROW_14 7
#define ROW_15 8
#define ROW_16 9

#define COL_9 10
#define COL_10 11
#define COL_11 12
#define COL_12 13
#define COL_13 31
#define COL_14 33
#define COL_15 35
#define COL_16 37

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
*/

// The display buffer
// It's prefilled with a smiling face (1 = ON, 0 = OFF)
/*
byte ALL[] = { B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111 };
byte EX[] = { B00000000, B00010000, B00010000, B00010000, B00010000, B00000000, B00010000, B00000000 };
byte A[] = { B00000000, B00111100, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110 };
byte B[] = { B01111000, B01001000, B01001000, B01110000, B01001000, B01000100, B01000100, B01111100 };
byte C[] = { B00000000, B00011110, B00100000, B01000000, B01000000, B01000000, B00100000, B00011110 };
byte D[] = { B00000000, B00111000, B00100100, B00100010, B00100010, B00100100, B00111000, B00000000 };
byte E[] = { B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00111100, B00000000 };
byte F[] = { B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00100000, B00000000 };
byte G[] = { B00000000, B00111110, B00100000, B00100000, B00101110, B00100010, B00111110, B00000000 };
byte H[] = { B00000000, B00100100, B00100100, B00111100, B00100100, B00100100, B00100100, B00000000 };
byte I[] = { B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00111000, B00000000 };
byte J[] = { B00000000, B00011100, B00001000, B00001000, B00001000, B00101000, B00111000, B00000000 };
byte K[] = { B00000000, B00100100, B00101000, B00110000, B00101000, B00100100, B00100100, B00000000 };
byte L[] = { B00000000, B00100000, B00100000, B00100000, B00100000, B00100000, B00111100, B00000000 };
byte M[] = { B00000000, B00000000, B01000100, B10101010, B10010010, B10000010, B10000010, B00000000 };
byte N[] = { B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000, B00000000 };
byte O[] = { B00000000, B00111100, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000 };
byte P[] = { B00000000, B00111000, B00100100, B00100100, B00111000, B00100000, B00100000, B00000000 };
byte Q[] = { B00000000, B00111100, B01000010, B01000010, B01000010, B01000110, B00111110, B00000001 };
byte R[] = { B00000000, B00111000, B00100100, B00100100, B00111000, B00100100, B00100100, B00000000 };
byte S[] = { B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000 };
byte T[] = { B00000000, B01111100, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000 };
byte U[] = { B00000000, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00000000 };
byte V[] = { B00000000, B00100010, B00100010, B00100010, B00010100, B00010100, B00001000, B00000000 };
byte W[] = { B00000000, B10000010, B10010010, B01010100, B01010100, B00101000, B00000000, B00000000 };
byte X[] = { B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000 };
byte Y[] = { B00000000, B01000100, B00101000, B00010000, B00010000, B00010000, B00010000, B00000000 };
byte Z[] = { B00000000, B00111100, B00000100, B00001000, B00010000, B00100000, B00111100, B00000000 };
*/

byte ROW0[] = { B01111111, B01111111, B01111111, B01111111, B01111111, B01111111, B01111111, B01111111 };
byte ROW1[] = { B10111111, B10111111, B10111111, B10111111, B10111111, B10111111, B10111111, B10111111 };
byte ROW2[] = { B11011111, B11011111, B11011111, B11011111, B11011111, B11011111, B11011111, B11011111 };
byte ROW3[] = { B11101111, B11101111, B11101111, B11101111, B11101111, B11101111, B11101111, B11101111 };
byte ROW4[] = { B11110111, B11110111, B11110111, B11110111, B11110111, B11110111, B11110111, B11110111 };
byte ROW5[] = { B11111011, B11111011, B11111011, B11111011, B11111011, B11111011, B11111011, B11111011 };
byte ROW6[] = { B11111101, B11111101, B11111101, B11111101, B11111101, B11111101, B11111101, B11111101 };
byte ROW7[] = { B11111110, B11111110, B11111110, B11111110, B11111110, B11111110, B11111110, B11111110 };

float timeCount = 0;

void Drawsetup() {
  // Open serial port
  Serial.begin(9600);

  // Set all used pins to OUTPUT
  // This is very important! If the pins are set to input
  // the display will be very dim.
  for (byte i = 22; i <= 52; i += 2)
    pinMode(i, OUTPUT);
  for (byte i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  for (byte i = 31; i <= 37; i += 2)
    pinMode(i, OUTPUT);
}
/*
void loop() {
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW0, row1, col1);
    drawScreen(ROW0, row2, col2);
  }
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW1, row1, col1);
    drawScreen(ROW1, row2, col2);
  }
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW2, row1, col1);
    drawScreen(ROW2, row2, col2);
  }

  for(int i = 0; i < 100; i++){
    drawScreen(ROW3, row1, col1);
    drawScreen(ROW3, row2, col2);
  }
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW4, row1, col1);
    drawScreen(ROW4, row2, col2);
  }

  for(int i = 0; i < 100; i++){
    drawScreen(ROW5, row1, col1);
    drawScreen(ROW5, row2, col2);
  }
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW6, row1, col1);
    drawScreen(ROW6, row2, col2);
  }
  
  for(int i = 0; i < 100; i++){
    drawScreen(ROW7, row1, col1);
    drawScreen(ROW7, row2, col2);
  }
}
*/

/*
Prototyping, works for a single Display but has Issues with the second one,
technically irrelevant, cause in Order to draw multiple Pixels at once onto
the screen a bitmap is needed, so this is not useful, just for testing / debugging
purposes or to see wheather the display is connected properly
void drawPixel(byte posX, byte posY) {
  for (byte i = 0; i < 16; i++) {
    if (i == posX) {
      digitalWrite(rows[i], HIGH);
    }
    for (byte n = 0; n < 8; n++) {
      if (n == posY) {
        digitalWrite(col[n], LOW);
      }
    }
  }
}
*/

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
===============
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
===============
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

      delayMicroseconds(100);  // uncoment deley for diferent speed of display
      //delayMicroseconds(1000);
      //delay(10);
      //delay(100);

      digitalWrite(column[a], 1);  // reset whole column
    }
    digitalWrite(row[i], LOW);  // reset whole row
                                 // otherwise last row will intersect with next row
  }
}