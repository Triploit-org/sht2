#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_tfd(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: tfd <arg1> <...>\n");
    printf("\tA experimental command to test beta-cmds.\n");
    return 1;
  }

  printf("sht: Nothing to see here in official versions!\n");
  return 1;
}
