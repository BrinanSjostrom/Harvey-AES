#ifndef _CONSTRUCTROUNDKEY_H_
#define _CONSTRUCTROUNDKEY_H_
#include "aesSteps.h"
#include "cpyMatrix.h"

void constructRoundKey(unsigned char roundKey[4][4], unsigned char *proundKey)
{

  unsigned char newRoundKey[4][4];

  unsigned char Rcon[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

  static int RconIndex = -1;
  RconIndex++;
  if(RconIndex == 10)
  {
    RconIndex = 0;
  }
  unsigned char buffer[4];

  unsigned char rotWord[4];
  for(int i = 0; i < 4; i++)
  {
    if(i == 0)
    {
      rotWord[3] = getrsboxIndex(roundKey[i][3]);
    }
    else
    {
      rotWord[i - 1] = getrsboxIndex(roundKey[i][3]);
    }
  }


  for(int n = 0; n < 4; n++)
  {
    for(int i = 0; i < 4; i++)
    {
      buffer[i] = roundKey[i][n];
    }
    if(n == 0)
    {
      for(int i = 0; i < 4; i++)
      {
        newRoundKey[i][n] = buffer[i] ^ rotWord[i];
      }
      newRoundKey[0][0] ^= Rcon[RconIndex];
    }
    else
    {
      for(int i = 0; i < 4; i++)
      {
        newRoundKey[i][n] = buffer[i] ^ newRoundKey[i][n - 1];
      }
    }
  }
  unsigned char *pnewRoundKey = &newRoundKey[0][0];
  cpyMatrix(pnewRoundKey, proundKey);
return;
}

#endif
