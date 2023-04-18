#include "PIC.h"

#define PIN_B1  22//R1
#define PIN_R1  23//G1
#define PIN_G1  21//B1
#define PIN_B2  18//R2
#define PIN_R2  19//G2
#define PIN_G2   5//B2
#define PIN__A   4
#define PIN__B  25
#define PIN__C  14
#define PIN__D  33
#define PIN_CK  27
#define PIN_LT  32
#define PIN_OE  26


inline void SET_RGB1( int r1, int g1, int b1, int j ) {
  digitalWrite( PIN_R1, (j < r1));
  digitalWrite( PIN_G1, (j < g1));
  digitalWrite( PIN_B1, (j < b1));
}

inline void SET_RGB2( int r2, int g2, int b2, int j ) {
  digitalWrite( PIN_R2, (j < r2));
  digitalWrite( PIN_G2, (j < g2));
  digitalWrite( PIN_B2, (j < b2));
}

void setup()
{
  pinMode( PIN_R1, OUTPUT );
  pinMode( PIN_G1, OUTPUT );
  pinMode( PIN_B1, OUTPUT );
  pinMode( PIN_R2, OUTPUT );
  pinMode( PIN_G2, OUTPUT );
  pinMode( PIN_B2, OUTPUT );
  pinMode( PIN__A, OUTPUT );
  pinMode( PIN__B, OUTPUT );
  pinMode( PIN__C, OUTPUT );
  pinMode( PIN__D, OUTPUT );
  pinMode( PIN_CK, OUTPUT );
  pinMode( PIN_LT, OUTPUT );
  pinMode( PIN_OE, OUTPUT );

  digitalWrite( PIN_R1, 0 );
  digitalWrite( PIN_G1, 0 );
  digitalWrite( PIN_B1, 0 );
  digitalWrite( PIN_R2, 0 );
  digitalWrite( PIN_G2, 0 );
  digitalWrite( PIN_B2, 0 );
  digitalWrite( PIN__A, 0 );
  digitalWrite( PIN__B, 0 );
  digitalWrite( PIN__C, 0 );
  digitalWrite( PIN__D, 0 );
  digitalWrite( PIN_CK, 0 );
  digitalWrite( PIN_LT, 0 );
  digitalWrite( PIN_OE, 1 );//OEのみ1でOFF
}

int cctt1 = 0;
int cctt2 = 0;

void loop()
{
  cctt1++;
  if (50 <= cctt1) {
    cctt2++;
    cctt1 = 0;
  }
  if (2 <= cctt2) {
    cctt2 = 0;
  }
  int i = 0;
  int j = 0;
  int d = 0;
  for (j = 0; j < 6; j++) {
    for ( d = 0; d < 16; d++ ) {
      digitalWrite( PIN_LT, 1 );

      for (int x = 0; x < 64; x++) {
        digitalWrite( PIN_CK, 0 );
        int col1 = PIC[cctt2][d + 00][x];
        int col2 = PIC[cctt2][d + 16][x];
        int r1 = col1 / 256;
        int g1 = (col1 % 256) / 16;
        int b1 = col1 % 16;
        int r2 = col2 / 256;
        int g2 = (col2 % 256) / 16;
        int b2 = col2 % 16;
        SET_RGB1(r1, g1, b1, j);
        SET_RGB2(r2, g2, b2, j);
        digitalWrite( PIN_CK, 1 );
      }
      digitalWrite( PIN_OE, 1 );
      digitalWrite( PIN__A, ( d & 1 ) );
      digitalWrite( PIN__B, ( d & 2 ) >> 1);
      digitalWrite( PIN__C, ( d & 4 ) >> 2);
      digitalWrite( PIN__D, ( d & 8 ) >> 3);
      digitalWrite( PIN_LT, 0 );
      digitalWrite( PIN_OE, 0 );
    }
  }
}
