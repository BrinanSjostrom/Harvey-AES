#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#define BYTE 8

int b64encode(char *str)
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
  }
  else if(strlen(binStr) % 6 == 2)
  {
    padding = 2;
  }
  else
  {
    padding = 0;
  }

return padding;
}
