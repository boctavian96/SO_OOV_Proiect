#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int my_ls(char** argumente)
{

DIR *dir;
struct dirent *ent;
if ((dir = opendir (".")) != NULL) {
  /* afiseaza toate folderele si fisierele */
  while ((ent = readdir (dir)) != NULL) {

    printf (ANSI_COLOR_YELLOW "%s\n" ANSI_COLOR_RESET , ent->d_name );
  }
  closedir(dir);
} else {
  /* nu se poate deschide directorul*/
  perror ("");
  return EXIT_FAILURE;
}
return 1;
}	
