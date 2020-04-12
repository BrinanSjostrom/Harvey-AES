#ifndef _BASE64_H_
#define _BASE64_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64Key.h"
#include "binary.h"
#include "parse.h"

char *b64encode(char *array, int size)
{
  char *buffer3 = (char*)malloc(25 * sizeof(char));
  int b64Size = 1;
  char *base64 = (char*)malloc(b64Size * sizeof(char));
  strcpy(base64 ,"");

 for(int i = 0; i < size; i++)
  {
    char *buffer8 = charTobin(*(array + i));

    strcat(buffer3, buffer8);
    free(buffer8);

    if((i + 1) % 3 == 0)
    {
      for(int n = 0; n < 24; n+=6)
      {
        char *buffer6 = parse(buffer3, n, n + 6);
        char ch = tob64(buffer6);
        free(buffer6);

        b64Size++;
        base64 = (char*)realloc(base64 ,b64Size * sizeof(char));
        char sch[2] = {ch, '\0'};
        strcat(base64, sch);

      }
      strcpy(buffer3, "");
    }

  }


  if(strlen(buffer3) != 0)
  {
    int padding = 3 - (strlen(buffer3)/8);
    if(padding == 1)
    {
      strcat(buffer3, "00");
      for(int i = 0; i < 18; i+=6)
      {
         char *buffer6 = parse(buffer3, i, i + 6);
         b64Size++;
         base64 = (char*)realloc(base64 ,b64Size * sizeof(char));
         char ch = tob64(buffer6);
         *(base64 + b64Size - 2) = ch;
         free(buffer6);
      }
      b64Size++;
      base64 = (char*)realloc(base64 ,b64Size * sizeof(char));
      *(base64 + b64Size - 2) = '=';
      *(base64 + b64Size - 1) = '\0';
    }
    else if(padding == 2)
    {
      for(int i = 0; i < 12; i+=6)
      {
         char *buffer6 = parse(buffer3, i, i + 6);
         b64Size++;
         base64 = (char*)realloc(base64 ,b64Size * sizeof(char));
         char ch = tob64(buffer6);
         *(base64 + b64Size - 2) = ch;
         free(buffer6);
      }
      b64Size += 2;
      base64 = (char*)realloc(base64 ,b64Size * sizeof(char));
      strcat(base64, "==");
    }
  }

  free(buffer3);
return base64;
}

#endif
