#ifndef _FILERW_H_
#define _FILERW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../base64/binary.h"

char *readFile(char *fileName, int *fileSize)
{
  FILE *pFile = fopen(fileName, "rb");
  int ch;
  *fileSize = 0;
  char *fileStr = (char*)malloc(sizeof(char));

  while(1)
  {
    ch = fgetc(pFile);
    if(ch == EOF)
    {
      break;
    }
    (*fileSize) += 1;
    fileStr = (char*)realloc(fileStr, (*fileSize) * sizeof(char));
    *(fileStr + *fileSize - 1) = ch;
  }
  fclose(pFile);
return fileStr;
}

#endif
