/****************************************************************************
This piece of code (main.c) pretty much just handles all of the CLI arguments
and envokes all of the other functions that's needed to run this code.
Code by: GRIM-OPS
License:
                      GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "file/fileRW.h"
#include "aes/aes/encrypt.h"
#include "aes/invaes/decrypt.h"
#include "input/getArgs.h"
#include "input/get_input.h"

int main(int argc, char *argv[])
{
  int argLoc = 0;
  
  if(argc == 1)
  {
    printf("-h or --help\t\tDisplay help menu\n");
    printf("-m or --mode\t\tSets mode: [e]ncrypt, [d]ecrypt\n");
    printf("-f or --file\t\tSets file input: <filepath>\n");
    return 0;
  }
  else if(getArgs('h', "--help", argc, argv))
  {
    printf("-h or --help\t\tDisplay help menu\n");
    printf("-m or --mode\t\tSets mode: [e]ncrypt, [d]ecrypt\n");
    printf("-f or --file\t\tSets file input: <filepath>\n");
    return 0;
  }


  unsigned char key[4][4];
	char *pKey;
	char *confirmedKey;
  while(1)
  {
    printf("[!] Password: ");
	  get_input(&pKey, 16);
	  printf("[!] Confirm Password: ");
	  get_input(&confirmedKey, 16);
	
	  if(strcmp(pKey, confirmedKey))
    {
      fprintf(stderr, "[!] Passwords are not the same!\n");
		  continue;
    }
		else if(strlen(pKey) > 16)
    {
      printf("[!] Password is greater than 16\n");
      continue;
    }
		else if(strlen(pKey) < 16)
    {
      for(int i = strlen(pKey); i < 16; i++)
      {
        pKey = (char*)realloc(pKey, i + 1);
        *(pKey + i) = 'v';
      }
      *(pKey + 16) = '\0';
    }
    int i = 0;
    for(int row = 0; row < 4; row++)
    {
      for(int column = 0; column < 4; column++)
      {
        key[row][column] = *(pKey + i);
        i++;
      } 
    }
	  break;
  }
  printf("[+] Generated key\n");



  unsigned char *filePath;
  argLoc = getArgs('f', "--file", argc, argv);
  if(argLoc)                                     // user sets file path
  {
    if(argLoc + 1 >= argc)
    {
      fprintf(stderr, "[!] Not a valid mode\n");
      return 1;
    }
    filePath = argv[argLoc + 1];
    printf("[+] File Path: %s\n", filePath);
  }
  else
  {
    fprintf(stderr, "[!] Need the file path to operate\n");
  }



  argLoc = getArgs('m', "--mode", argc, argv);
  if(argLoc)                                                      //This is the mode, either decrypt or encrypt
  {
    if(argLoc + 1 >= argc)
    {
      fprintf(stderr, "[!] Mode needs an option\n");
      return 1;
    }
    if(!strcmp(argv[argLoc + 1],"e")) //encrypt
    {
      printf("[+] Mode: Encrypt\n");
      size_t size;
      unsigned char *str = readFile(filePath, &size);
      printf("[+] Encrypting...\n");
      unsigned char *cipher = encrypt(str, key, size, &size);
      printf("[+] Encrypted!\n");
      free(str);
      printf("[+] Writing over file...\n");
      writeFile(filePath, size, cipher);
      printf("[+] File written!\n");
    }
    else if(!strcmp(argv[argLoc + 1],"d"))  //decrypt
    {
      printf("[+] Mode: Decrypt\n");
      size_t size;
      unsigned char *str = readFile(filePath, &size);
      printf("[+] Decrypting...\n");
      unsigned char *cipher = decrypt(str, key, size, &size);
      printf("[+] Decrypted!\n");
      free(str);
      printf("[+] Writing over file...\n");
      writeFile(filePath, size, cipher);
      printf("[+] File written!\n");
    }
    else
    {
      fprintf(stderr, "[!] %s is not a valid mode\n", argv[argLoc + 1]);
      return 1;
    }
  }
  else
  {
    fprintf(stderr, "[!] Need mode to operate\n");
    return 1;
  }

return 0;
}
