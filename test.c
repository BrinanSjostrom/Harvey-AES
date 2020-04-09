#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64Key.h"
#include "binary.h"

int main(int argc, char *argv[])
{

  char ch = tob64("000001");

  printf("%i\n", binTochar("00000001"));
return 0;
}
