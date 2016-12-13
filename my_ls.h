#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
//PATH=$PATH:$HOME/proiect/
// export PATH
// $PATH

#define SIZE 10
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main (int argc, char* argv[])
{
unsigned char isFile =0x8;
unsigned char isFolder =0x4;
DIR *dir;
struct dirent *ent;
int status;


if ((dir = opendir (".")) != NULL) {
  /* afiseaza toate folderele si fisierele */
  while ((ent = readdir (dir)) != NULL) {
		;

	if (ent->d_type == isFile) {
        printf (ANSI_COLOR_YELLOW "%s\n" ANSI_COLOR_RESET , ent->d_name );
    }
    
	if (ent->d_type == isFolder) {
        printf (ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET , ent->d_name );
    }




  }
  closedir (dir);
} 

else {
  /* nu poate deschide directorul*/
  perror ("");
  return EXIT_FAILURE;
}
}
