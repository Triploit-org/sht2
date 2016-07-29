#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

int sht_list(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: ls\n");
    printf("\tShows ALL direcotries and files in current direcotry.\n");
    return 1;
  }

  DIR *d;
  struct dirent *dir;
  d = opendir("./");

  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      struct stat s;
      int serr = stat(dir->d_name, &s);

      if(-1 == serr)
      {
          if(ENOENT == errno)
          {
              printf("sht: A mysterial error!");
          } else {
              perror("sht: list");
              exit(1);
          }
      }
      else
      {
          if(S_ISDIR(s.st_mode))
          {
              printf("\e[33mDIR > %s\n", dir->d_name);
          } else
          {
              printf("\e[36mFIL > %s\n", dir->d_name);
          }
      }

      /*if (chdir(dir->d_name) == 0 && dir->d_name != "..")
      {
        printf("DIR > %s\n", dir->d_name);
      }
      else
        printf("FIL > %s\n", dir->d_name);*/
    }

    closedir(d);
  }
  return 1;
}
