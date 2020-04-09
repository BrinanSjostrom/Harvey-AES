#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64.h"

int main(int argc, char *argv[])
{
  int in = b64encode("ruhyvfudysavfda");
  printf("%i\n", in);
return 0;
}
