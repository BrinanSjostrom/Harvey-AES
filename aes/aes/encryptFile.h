#ifndef _ENCRYPTFILE_H_
#define _ENCRYPTFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rijndael.h"


unsigned char *encryptFile(unsigned char *fileStr, unsigned char *key, size_t inSize, size_t *outSize)
{

  unsigned char *base64PlainText = base64_encode(fileStr, insize, outSize);
  size_t plusOutSize = ((*outSize % 16) - 16);
  base64PlainText = (unsigned char*)realloc(base64PlainText, ((*outSize) + plusOutSize) * sizeof(unsigned char));
  for(int i = 0; i < plusOutSize; i++)
  {
    *(base64PlainText + *outSize) = '-';
    (*outSize)++;
  }

  int strIndex = 0;
  int outStrIndex = 0;
  unsigned char roundKey[4][4];
  unsigned char *outStr = malloc((*outSize) * sizeof(unsigned char))

  for(int revs = 0; revs < (*outSize) % 16; revs++)
  {
    unsigned char buffer[4][4];
    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        if(revs = 0)roundKey[row][column] = *(key + strIndex);
        buffer[row][column] = *(fileStr + strIndex);
        strIndex++;
      }
    }

    rijndael(buffer, roundKey, &buffer[0][0]);

    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        *(outStr + outStrIndex) = buffer[row][column];
        outStrIndex++;
      }
    }
  }

return ret_str;
}


#endif
