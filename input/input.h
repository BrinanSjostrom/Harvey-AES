#ifndef _INPUT_H_
#define _INPUT_H_
#include <stdio.h>
#include <stdlib.h>



/******************************
Function will get input of
unknown length from user. The
way this works is by extending
the str variable until the
input stream is empty.
******************************/
char *input()
{
   int size = 1;
   char ch;
   char *str = malloc(size * sizeof(char));
   if(!str)
   {
     exit(1);
   }
     while(1)
     {
       ch = fgetc(stdin);
       if(ch == EOF || ch == '\n')
       {
         *(str + size - 1) = '\0';
         break;
       }
       size++;
       str = realloc(str, size * sizeof(char));
       if(!str)
       {
         exit(1);
       }
       *(str + size - 2) = ch;
     }
return str;
}

#endif
