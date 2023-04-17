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

int fst = 128;        //最初の空白ドット数
int lst = 128;        //最後の空白ドット数
int dst = 2;          //文字ごとの感覚
int dly = 5;         //流れる感覚
String  msg = "ACFA IS THE BEST ROBOT GAME.";     //表示したい文字
String output[36] = {""};
#include "FONT.h"
#include "ADDCHAR.h"
#include "MAKEDATA.h"

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
  makedata();
}
int dlyct = 0;
int count = 0;
int data_size = fst + (msg.length() * (5 + dst)) + lst - 128;

void loop()
{

  int i = 0;
  int d = 0;
  dlyct++;
  if (dly <= dlyct) {
    count++;
    dlyct = 0;
  }
  if (data_size <= count) {
    count = 0;
  }
  for ( d = 0; d < 16; d++ ) {
    digitalWrite( PIN_LT, 1 );

    for (int x = 0; x < 128; x++) {
      digitalWrite( PIN_CK, 0 );
      char c1 = output[0 + d].charAt(x + count);
      switch (c1) {
        case 'R':
          digitalWrite( PIN_R1, 1 );
          digitalWrite( PIN_G1, 0 );
          digitalWrite( PIN_B1, 0 );
          break;
        case 'G':
          digitalWrite( PIN_R1, 0 );
          digitalWrite( PIN_G1, 1 );
          digitalWrite( PIN_B1, 0 );
          break;
        case 'B':
          digitalWrite( PIN_R1, 0 );
          digitalWrite( PIN_G1, 0 );
          digitalWrite( PIN_B1, 1 );
          break;
        case 'C':
          digitalWrite( PIN_R1, 0 );
          digitalWrite( PIN_G1, 1 );
          digitalWrite( PIN_B1, 1 );
          break;
        case 'M':
          digitalWrite( PIN_R1, 1 );
          digitalWrite( PIN_G1, 0 );
          digitalWrite( PIN_B1, 1 );
          break;
        case 'Y':
          digitalWrite( PIN_R1, 1 );
          digitalWrite( PIN_G1, 1 );
          digitalWrite( PIN_B1, 0 );
          break;
        case 'K':
          digitalWrite( PIN_R1, 0 );
          digitalWrite( PIN_G1, 0 );
          digitalWrite( PIN_B1, 0 );
          break;
        case 'W':
          digitalWrite( PIN_R1, 1 );
          digitalWrite( PIN_G1, 1 );
          digitalWrite( PIN_B1, 1 );
          break;
      }
      char c2 = output[16 + d][x + count];
      switch (c2) {
        case 'R':
          digitalWrite( PIN_R2, 1 );
          digitalWrite( PIN_G2, 0 );
          digitalWrite( PIN_B2, 0 );
          break;
        case 'G':
          digitalWrite( PIN_R2, 0 );
          digitalWrite( PIN_G2, 1 );
          digitalWrite( PIN_B2, 0 );
          break;
        case 'B':
          digitalWrite( PIN_R2, 0 );
          digitalWrite( PIN_G2, 0 );
          digitalWrite( PIN_B2, 1 );
          break;
        case 'C':
          digitalWrite( PIN_R2, 0 );
          digitalWrite( PIN_G2, 1 );
          digitalWrite( PIN_B2, 1 );
          break;
        case 'M':
          digitalWrite( PIN_R2, 1 );
          digitalWrite( PIN_G2, 0 );
          digitalWrite( PIN_B2, 1 );
          break;
        case 'Y':
          digitalWrite( PIN_R2, 1 );
          digitalWrite( PIN_G2, 1 );
          digitalWrite( PIN_B2, 0 );
          break;
        case 'K':
          digitalWrite( PIN_R2, 0 );
          digitalWrite( PIN_G2, 0 );
          digitalWrite( PIN_B2, 0 );
          break;
        case 'W':
          digitalWrite( PIN_R2, 1 );
          digitalWrite( PIN_G2, 1 );
          digitalWrite( PIN_B2, 1 );
          break;
      }

      digitalWrite( PIN_CK, 1 );
    }
    digitalWrite( PIN_OE, 1 );
    digitalWrite( PIN__A, ( d & 1 ) );
    digitalWrite( PIN__B, ( d & 2 ) >> 1);
    digitalWrite( PIN__C, ( d & 4 ) >> 2);
    digitalWrite( PIN__D, ( d & 8 ) >> 3);
    digitalWrite( PIN_LT, 0 );
    digitalWrite( PIN_OE,  0 );
  }
}
