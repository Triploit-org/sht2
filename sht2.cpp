#include "sys/shtsys.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  // Load config files, if any.

  sht_loop();
  printf("exit: %d\n", EXIT_SUCCESS);
  return EXIT_SUCCESS;
}
