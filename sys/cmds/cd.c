#include <dirent.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

int sht_cd(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: cd [directory]\n");
    printf("\tChange the current directory.\n");
    return 1;
  }

  if (args[1] == NULL)
  {
    fprintf(stderr, "sht: expected argument to \"cd\"\n");
  } else
  {
    if (chdir(args[1]) != 0)
    {
      perror("sht");
    }
  }
  return 1;
}
