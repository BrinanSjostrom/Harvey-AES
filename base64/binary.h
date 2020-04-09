#ifndef _BINARY_H_
#define _BINARY_H_


#include <stdio.h>
#include <stdlib.h>


char *charTobin(char ch)
{
  char *binStr = (char*)malloc(9 * sizeof(char));
  *(binStr + 8) = '\0';
  for(int i = 7; i >= 0; i--)
  {
    if(ch % 2 == 1)
    {
      *(binStr + i) = '1';
    }
    else
    {
      *(binStr + i) = '0';
    }
    ch >>= 1;
  }
return binStr;
}

char binTochar(char *binStr)
{
  char ch = 0;
  for(int i = 0; i <= 7; i++)
  {
    ch <<= 1;
    if(*(binStr + i) == '1')
    {
      ch += 1;
    }
  }
return ch;
}

#endif
