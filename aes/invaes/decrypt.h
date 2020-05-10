#ifndef _DECRYPT_H_
#define _DECRYPT_H_

#include <stdio.h>
#include "invrijndael.h"
#include "cpyMatrix.h"
#include "../../base64/base64.h"

unsigned char *decrypt(unsigned char *cipher_text, unsigned char key[4][4], size_t in_size, size_t *out_size)
{
  unsigned char *base64_str = malloc(*out_size * sizeof(unsigned char));
  unsigned char buffer[4][4];
  unsigned char orgKey[4][4];
  cpyMatrix(&key[0][0], &orgKey[0][0]);

  for(int i = 0; i < in_size; i+=16)
  {
    int n = i;
    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        buffer[row][column] = *(cipher_text + n);
	n++;
      }
    }
    cpyMatrix(&orgKey[0][0], &key[0][0]);
    invrijndael(buffer, key, &buffer[0][0]);
    int r = n - 16;
    for(int column = 0; column < 4; column++)
    {
      for(int row = 0; row < 4; row++)
      {
        *(base64_str + r) = buffer[row][column];
	r++;
      }
    }
  }

  for(int i = in_size - 16; i < in_size; i++)
  {
    if(*(base64_str + i) == '-')
    {
      in_size = i;
    }
  }
  base64_str = (unsigned char*)realloc(base64_str, in_size * sizeof(unsigned char));
/*  for(int i = 0; i < in_size; i++)
  {
    printf("%c", *(base64_str + i));
  }*/
  unsigned char *out_str = base64_decode(base64_str, in_size, out_size);

return out_str;
}

#endif
