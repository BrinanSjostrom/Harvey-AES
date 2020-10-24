#ifndef _GET_INPUT_H_
#define _GET_INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_input(char **input, const size_t buffer_size)
{

  char buffer[buffer_size + 1];

  size_t size_of_input = 1;
  *input = (char*)malloc(sizeof(char) * size_of_input);
  strcpy(*input, "");

  while(1)
  {
    memset(buffer, 0, sizeof(buffer));
    for(int i = 0; i < buffer_size; i++)
    {
      buffer[i] = fgetc(stdin);
      if(buffer[i] == '\n' || buffer[i] == EOF || buffer[i] == '\0'){
        buffer[i] = '\0';
        break;
      }
    }
    size_of_input+=strlen(buffer);
    *input = (char*)realloc(*input, sizeof(char) * size_of_input);
    strcat(*input, buffer);
    if(strlen(buffer) != buffer_size)
      return size_of_input - 1;
  }

}
#endif
