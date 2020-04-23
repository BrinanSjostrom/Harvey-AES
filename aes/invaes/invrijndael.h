#ifndef _INVRIJNDAEL_H_
#define _INVRIJNDAEL_H_

#include <stdio.h>
#include "cpyMatrix.h"
#include "invaesSteps.h"
#include "deconstructRoundKey.h"
#include "../aes/aesSteps.h"
#include "../aes/constructRoundKey.h"

void invrijndael(unsigned char cipherText[4][4], unsigned char roundKey[4][4], unsigned char *out)
{

  unsigned char plainText[4][4];

  for(int i = 0; i < 10; i++)
  {
    constructRoundKey(roundKey, &roundKey[0][0]);
  }


  addRoundKey(cipherText, roundKey, &plainText[0][0]);
  deconstructRoundKey(roundKey, &roundKey[0][0]);
  invshiftRows(plainText, &plainText[0][0]);
  invsubBytes(plainText, &plainText[0][0]);

  for(int i = 0; i < 9; i++)
  {
    addRoundKey(plainText, roundKey, &plainText[0][0]);
    deconstructRoundKey(roundKey, &roundKey[0][0]);
    invmixColumns(plainText, &plainText[0][0]);
    invshiftRows(plainText, &plainText[0][0]);
    invsubBytes(plainText, &plainText[0][0]);
  }

  addRoundKey(plainText, roundKey, &plainText[0][0]);

  cpyMatrix(&plainText[0][0], out);
return;
}

#endif
