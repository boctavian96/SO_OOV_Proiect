#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

//PATH=$PATH:$HOME/proiect/
// export PATH
// $PATH

#define SIZE2 10

int my_ls(char** argv)
{
DIR *dir;
struct dirent *ent;
if ((dir = opendir (".")) != NULL) {
  /* afiseaza toate folderele si fisierele */
  while ((ent = readdir (dir)) != NULL) {

    printf ("%s\n", ent->d_name);
  }
  closedir(dir);
} else {
  /* nu se poate deschide directorul*/
  perror ("");
  return EXIT_FAILURE;
}
return 1;
}	
