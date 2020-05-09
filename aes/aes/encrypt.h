#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rijndael.h"
#include "cpyMatrix.h"
#include "../../base64/base64.h"

char *encrypt(unsigned char *str, unsigned char key[4][4], size_t inSize, size_t *outSize)
{

  unsigned char orgKey[4][4];
  cpyMatrix(&key[0][0], &orgKey[0][0]);
  size_t base64_size;
  unsigned char *base64_str = base64_encode(str, inSize, &base64_size);
  *outSize = base64_size + (16 - (base64_size % 16));
  base64_str = (unsigned char*)realloc(base64_str, (*outSize) * sizeof(unsigned char));

  for(int i = base64_size; i < *outSize; i++)
  {
    *(base64_str + i) = '-';
  }

  unsigned char *outStr = (unsigned char*)malloc(*outSize * sizeof(unsigned char));

  unsigned char buffer[4][4];
  for(int i = 0; i < *outSize; i+=16)
  {
    int n = i;
    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        buffer[row][column] = *(base64_str + n);
	n++;
      }
    }

    cpyMatrix(&orgKey[0][0], &key[0][0]);
    rijndael(buffer, key, &buffer[0][0]);
    int r = n - 16;
    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        *(outStr + r) = buffer[row][column];
	r++;
      }
    }
  }

return outStr;
}

#endif
