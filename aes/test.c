#include <stdio.h>
#include "aes.h"

int main()
{

  unsigned char matrix[4][4] = {{0xd4, 0xe0, 0xb8, 0x1e},
                                {0xbf, 0xb4, 0x41, 0x27},
                                {0x5d, 0x52, 0x11, 0x98},
                                {0x30, 0xae, 0xf1, 0xe5}};


  unsigned char *pmatrix = &matrix[0][0];
  for(int i = 0; i < 16; i++)
  {
    printf("%i\t", *(pmatrix + i));
    if((i + 1) % 4 == 0)
    {
      printf("\n");
    }
  }
  printf("\n\n");

  pmatrix = mixColumns(matrix);

  for(int i = 0; i < 16; i++)
  {
    printf("%i\t", *(pmatrix + i));
    if((i + 1) % 4 == 0)
    {
      printf("\n");
    }
  }


return 0;
}
