#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>


int sht_fod(char **args)
{

  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: fod <name>\n");
    printf("\tCheck if the name is a file or a directory.\n");
    return 1;
  }

    struct stat s;
    int err = stat(args[1], &s);

    if(-1 == err)
    {
        if(ENOENT == errno)
        {
            printf("sht: A mysterial error: File not found?\n");
        } else {
            perror("sht: list");
        }
    }
    else
    {
        printf("0 = Direcory\n-1 = File\n");

        if(S_ISDIR(s.st_mode))
        {
            printf("\tYour input is: 0\n");
        } else
        {
            printf("\tYour input is: -1\n");
        }
    }

    return 1;
}
