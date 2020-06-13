#ifndef _RIJNDAEL_H_
#define _RIJNDAEL_H_

#include <stdio.h>
#include "aesSteps.h"
#include "constructRoundKey.h"
#include "cpyMatrix.h"

/*****************************************************
uses two four by four matricies to encrypt one of them
and uses the other as a key
*****************************************************/
void rijndael(unsigned char plainText[4][4], unsigned char roundKey[4][4], unsigned char *out)
{

  unsigned char cipherText[4][4];
  unsigned char *pcipherText = &cipherText[0][0];


  addRoundKey(plainText, roundKey, &cipherText[0][0]);
  constructRoundKey(roundKey, &roundKey[0][0]);

  for(int i = 0; i < 9; i++)
  {

    subBytes(cipherText, &cipherText[0][0]);
    shiftRows(cipherText, &cipherText[0][0]);
    mixColumns(cipherText, &cipherText[0][0]);
    addRoundKey(cipherText, roundKey, &cipherText[0][0]);
    constructRoundKey(roundKey, &roundKey[0][0]);
  }

  subBytes(cipherText, &cipherText[0][0]);
  shiftRows(cipherText, &cipherText[0][0]);
  addRoundKey(cipherText, roundKey, &cipherText[0][0]);

  cpyMatrix(pcipherText, out);

return;
}


#endif
