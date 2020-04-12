#ifndef _PARSE_H_
#define _PARSE_H_

#include <stdlib.h>

char *parse(char *str, int index1, int index2)
{
  if(index1 >= index2)
  {
    exit(1);
  }
  int size = index2 - index1;
  char *retStr = (char*)malloc(size * sizeof(char));
  *(retStr + size - 1) = '\0';
  for(int i = index1; i < index2; i++)
  {
    *(retStr + i - index1) = *(str + i);
  }
return retStr;
}

#endif
