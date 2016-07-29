#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_md(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: md <name>\n");
    printf("\tCreate a directory with the wished name.\n");
    return 1;
  }
  if (sizeof(args) > 0)
  {
    if ((mkdir(args[1], 755)) != 0)
    {
      perror("sht");
    }
  }
  else
  {
    printf("sht: To few arguments! %d", sizeof(args));
  }

  return 1;
}
