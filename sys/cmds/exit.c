
int sht_exit(char **args)
{
    if (args[1] == "-h" || args[1] == "--help")
    {
      printf("Usage: exit\n");
      printf("\tExit the shell.\n");
      return 1;
    }
  return 0;
}
