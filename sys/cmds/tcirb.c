#include <stdio.h>

//tcirb = this command is replaced by an other command, txpe in help to get help

int sht_tcirb(char **args)
{
  if (args[1] == "-h" || args[1] == "--help")
  {
    printf("Usage: XXX\n");
    printf("\tShows when a command is replaced or nedless.\n");
    return 1;
  }

  printf("sht: This command is nedless or has been replaced.\nsht: Type in \"help\" to get all commands!\n");
}
