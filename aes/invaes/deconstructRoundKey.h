#ifndef _DECONSTRUCTROUNDKEY_H_
#define _DECONSTRUCTROUNDKEY_H_

#include "cpyMatrix.h"
#include "../aes/aesSteps.h"

void deconstructRoundKey(unsigned char roundKey[4][4], unsigned char *out)
{
  unsigned char newRoundKey[4][4];

  unsigned char reRcon[] = {0x36, 0x1b, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
  static int reRconIndex = -1;
  reRconIndex++;

  unsigned char rotWord[4];

  for(int i = 3; i > 0; i--)
  {
    for(int n = 0; n < 4; n++)
    {
      newRoundKey[n][i] = roundKey[n][i] ^ roundKey[n][i-1];
      if(i == 3)
      {
        if(n == 0)
        {
          rotWord[3] = getrsboxIndex(newRoundKey[n][i]);
        }
        else
        {
          rotWord[n - 1] = getrsboxIndex(newRoundKey[n][i]);
        }
      }
    }
  }

  rotWord[0] = rotWord[0] ^ 0x01;

  for(int i = 0; i < 4; i++)
  {
    newRoundKey[i][0] = rotWord[i] ^ roundKey[i][0];
  }
  cpyMatrix(&newRoundKey[0][0], out);
return;
}


#endif
