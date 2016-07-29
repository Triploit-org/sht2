#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_help(char **args)
{
  int i;
  printf("\e[1;33mThese commands are included:\e[00m\n");

  for (i = 0; i < sht_num_builtins(); i++) {
    printf("\e[1;36m  %s - %s\e[00m\n", builtin_str[i], builtin_hlp[i]);
  }

  printf("\e[1;33mUse the \"man <command>\" command for information on other programs.\nOr Use the \"-h\" parameter on the included commands.\n");
  return 1;
}
