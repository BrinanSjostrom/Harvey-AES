#ifndef _INPUT_H_
#define _INPUT_H_
#include <stdio.h>
#include <stdlib.h>

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
