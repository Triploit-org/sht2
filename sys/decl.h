int sht_cd(char **args);
int sht_help(char **args);
int sht_exit(char **args);
int sht_fod(char **args);
int sht_list(char **args);
int sht_md(char **args);
int sht_mf(char **args);
int sht_read(char **args);
int sht_clear(char **args);
int sht_tfd(char **args);
int sht_copy(char **args);
int sht_mov(char **args);
int sht_kill(char **args);
int sht_tget(char **args);

int sht_tcirb(char **args);

char *builtin_str[] = {
  "cd",
  "help",
  "clear",
  "list",
  "fod",
  "md",
  "mf",
  "read",
  "tfd",
  "mov",
  "copy",
  "tget",

  "exit",

  "ls",
  "dir"
};

char *builtin_hlp[] = {
  "Change the directory",
  "Shows this page",
  "Clears the screen",
  "List all files and folders",
  "Shows if the argument is a file or a directory",
  "Create a directory",
  "Create a file",
  "Puts the text from a file on screen",
  "Little testing",
  "Move a file WARN: Some error-help is useless",
  "Copy files",
  "Download a file",

  "Exit the shell\n",

  "Command replaced by \"list\"",
  "Command replaced by \"list\""
};

int (*builtin_func[]) (char **) = {
  &sht_cd,
  &sht_help,
  &sht_clear,
  &sht_list,
  &sht_fod,
  &sht_md,
  &sht_mf,
  &sht_read,
  &sht_tfd,
  &sht_mov,
  &sht_copy,
  &sht_tget,

  &sht_exit,

  &sht_tcirb,
  &sht_tcirb
};

int sht_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
