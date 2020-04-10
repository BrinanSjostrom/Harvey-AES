#ifndef _GETARGS_H_
#define _GETARGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getArgs(char chArg, char *strArg, int argc, char *argv[])
{
  if(!(argc > 1))
  {
    return 0;
  }
  for(int i = 1; i < argc; i++)
  {
    if(argv[i][1] == chArg || strcmp(argv[i], strArg) == 0)
    {
      if(i + 1 == argc)
      {
        return 0;
      }
      return i + 1;
    }
  }
  return 0;
}

#endif