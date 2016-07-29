#include <stdio.h>

int sht_clear(char **args)
{
    if (args[1] == "-h" || args[1] == "--help")
    {
      printf("Usage: clear\n");
      printf("\t Clear the terminal screen.\n");
      return 1;
    }
  //scrclr();
  printf("\e[1;1H\e[2J");
  return 1;
}
