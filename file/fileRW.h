#ifndef _FILERW_H_
#define _FILERW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *readFile(char *fileName, size_t *fileSize)
{
  FILE *pFile = fopen(fileName, "rb");
  if(!pFile)
  {
    fprintf(stdin, "[!] Cannot open %s\n", fileName);
    exit(1);
  }
  int ch;
  *fileSize = 0;
  unsigned char *fileStr = (unsigned char*)malloc(sizeof(unsigned char));

  while(1)
  {
    ch = fgetc(pFile);
    if(ch == EOF)
    {
      break;
    }
    (*fileSize) += 1;
    fileStr = (unsigned char*)realloc(fileStr, (*fileSize) * sizeof(unsigned char));
    *(fileStr + *fileSize - 1) = ch;
  }
  fclose(pFile);
return fileStr;
}

int writeFile(char *fileName, size_t fileSize, unsigned char *fileContents)
{
  FILE *pFile = fopen(fileName, "wb+");
  if(!pFile)
  {
    fprintf(stdin, "[!] Cannot open %s\n", fileName);
    exit(1);
  }
  int ch = 0;

  for(int i = 0; i < fileSize; i++)
  {
    ch = *(fileContents + i);
    fputc(ch, pFile);
  }
  fclose(pFile);
return 0;
}


#endif
