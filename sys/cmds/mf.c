#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_mf(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: mf <name>\n");
    printf("\tCreate a new file with the wished name.\n");
    return 1;
  }

  if (sizeof(args) > 0)
  {
    FILE *fp;
    char ch;
    if ((fp=fopen(args[1],"w")) != 0)
    {
      perror("sht");
    }
    fclose(fp);
  }
  else
  {
    printf("sht: To few arguments! %d", sizeof(args));
  }

  return 1;
}
