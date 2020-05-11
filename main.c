#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "file/fileRW.h"
#include "aes/invaes/decrypt.h"
#include "input/getArgs.h"

int main(int argc, char *argv[])
{

  
  if(getArgs('h', "--help", argc, argv))
  {
    printf("-h or --help\t\tDisplay help menu\n");
    printf("-m or --mode\t\tSets mode: [e]ncrypt, [d]ecrypt\n");
    printf("-f or --file\t\tSets file input: <filepath>\n");
    printf("-k or --key \t\tSets path to key: <filepath> Needs file to hold 128bit(16 byte) sequence\n");
    printf("-g or --gen \t\tGenerates 128 bit key and stores in key.txt file\n");
    return 0;
  }
  if(getArgs('g', "--gen", argc, argv))
  {
    unsigned char genKey[16];
    srand(time(0));
    for(int i = 0; i < 16; i++)
    {
      genKey[i] = rand() % 256;
    }
    writeFile("key.txt", 16, &genKey[0]);
    return 0;
  }
  unsigned char *key;
  if(int loc = getArgs('k', "--key", argc, argv))
  {
    int size;
    key = readFile(argv[loc + 1], &size);
    if(size != 16)
    {
      fprintf(stderr, "[!]key size is too big or too small\n");
      return 1;
    }
  }
return 0;
}
