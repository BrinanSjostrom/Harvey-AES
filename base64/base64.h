#ifndef _BASE64_H_
#define _BASE64_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "base64Key.h"
#define BYTE 8

char *b64encode(char *str)
{

  int padding;
  char *buffer = (char*)malloc(9 * sizeof(char));
  int bytes = 1;
  char *binStr = (char*)malloc(1 * sizeof(char));
  strcpy(binStr, "");


  for(int i = 0; i < strlen(str); i++)
  {
    char *buffer = (char*)malloc(9 * sizeof(char));

    binStr = (char*)realloc(binStr, (BYTE * bytes + 1) * sizeof(char));
    bytes++;

    buffer = charTobin(*(str + i));
    strcat(binStr, buffer);

    free(buffer);
  }

  if(strlen(binStr) % 6 == 4)
  {
    padding = 1;
    binStr = (char*)realloc(binStr, (BYTE * bytes + 3) * sizeof(char));
    strcat(binStr, "00");
  }
  else if(strlen(binStr) % 6 == 2)
  {
    padding = 2;
    binStr = (char*)realloc(binStr, (BYTE * bytes + 5) * sizeof(char));
    strcat(binStr, "0000");
  }
  else
  {
    padding = 0;
  }

  int size = 1;
  char *base64Str = (char*)malloc(size * sizeof(char));
  strcpy(base64Str, "");
  for(int i = 0; i < strlen(binStr); i += 6)
  {
    char *buffer2 = (char*)malloc(7 * sizeof(char));
    *(buffer2 + 6) = '\0';
    for(int n = i; n < i + 6; n++)
    {
      *(buffer2 + (n-i)) = *(binStr + n);
    }
    size++;
    base64Str = (char*)realloc(base64Str, size * sizeof(char));
    char bufferStr[2] = {tob64(buffer2), '\0'};
    strcat(base64Str, bufferStr);
  }

  if(padding > 0)
  {
    size += padding;
    base64Str = (char*)realloc(base64Str, size * sizeof(char));
    for(int i = 0; i < padding; i++)
    {
      strcat(base64Str, "=");
    }
  }


return base64Str;
}

#endif
