#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rijndael.h"
#include "../../base64/base64.h"

char *encrypt(unsigned char *str, unsigned char key[4][4], size_t inSize, size_t *outSize)
{
  size_t base64_size;
  unsigned char *base64_str = base64_encode(str, inSize, &base64_size);
  *outSize = base64_size + (16 - (base64_size % 16));
  base64_str = (unsigned char*)realloc(base64_str, (*outSize) * sizeof(unsigned char));

  for(int i = base64_size; i < *outSize; i++)
  {
    *(base64_str + i) = '-';
  }

  unsigned char buffer[16];


return base64_str;
}

#endif
