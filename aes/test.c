#include <stdio.h>
#include "aes.h"

int main()
{
/***********************************************************
  unsigned char str[4][4] = { {0x1, 0xe0, 0xb8, 0x1e},

                              {0x2, 0xb4, 0x41, 0x27},

                              {0x3, 0x52, 0x11, 0x98},

                              {0x4, 0xae, 0xf1, 0xe5} };

unsigned char *lol = &str[0][0];
for(int i = 0; i < 16; i++)
{
  printf("%i\t", *(lol + i));
  if((1 + i) % 4 == 0)
  {
    printf("\n");
  }
}
printf("\n\n");
unsigned char *table = mixColumns(str);
for(int i = 0; i < 16; i++)
{
  printf("%i\t", *(table + i));
  if((1 + i) % 4 == 0)
  {
    printf("\n");
  }
}
********************************************/


unsigned char a = 0xF0;
unsigned char b = 0x0F;

printf("XOR1: %i\n XOR2: %i\n", xor(a,b), a ^ b);

return 0;
}
