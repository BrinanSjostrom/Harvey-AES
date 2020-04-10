#ifndef _BASE64KEY_H_
#define _BASE64KEY_H_


#include <stdlib.h>
#include <string.h>
#include "binary.h"

const char letters[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                          'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                          '0','1','2','3','4','5','6','7','8','9','+','/'};


char tob64(char *binStr)
{

  char *bit_8 = (char*)malloc(9 * sizeof(char));
  strcpy(bit_8, "00");
  strcat(bit_8, binStr);

  return letters[binTochar(bit_8)];
}



char *fromb64(char ch)
{
  int ifError = 1;
  char buffer;
  for(int i = 0; i < sizeof(letters)/sizeof(char); i++)
  {
    if(ch == letters[i])
    {
      buffer = i;
      ifError = 0;
      break;
    }
  }
  if(ifError == 1)
  {
    exit(1);
  }
  char *binStr = charTobin(buffer);
  char *base64ch = (char*)malloc(7 * sizeof(char));
  *(base64ch + 6) = '\0';
  for(int i = 2; i < 8; i++)
  {
    *(base64ch + i - 2) = *(binStr + i);
  }

return base64ch;
}


#endif
