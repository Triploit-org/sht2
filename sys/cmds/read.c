#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_read(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: read <file>\n");
    printf("\tReads all the text from a file (also binaries, but not effecient).\n");
    return 1;
  }

  int c;
  FILE *file;
  file = fopen(args[1], "r");
  if (file) {
      while ((c = getc(file)) != EOF)
          putchar(c);
      fclose(file);
  }
  else
  {
    printf("sht: File not found!\n");
  }

  return 1;
}
