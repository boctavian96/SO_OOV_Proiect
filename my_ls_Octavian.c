#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

#DEFINE PATH_SIZE 1024

typedef struct optiuni_intrare optiuni
{
  bool folosind_a;
  bool folosind_d;
}

struct optiuni_intrare obtine_optiuni(int count, char* args[])
{
  optiuni_intrare oi;
  initializare_Optiuni(&oi);
  int opt;

  while((opt = getopt(count, args, "adhilpQRStU")) != 1)
  {
    switch(opt)
    {
      case 'a': oi.folosind_a = true; break;
      case 'd': oi.folosind_d = true; break;
    }

  return oi;
}

void initializare_Optiuni(opriuni* o);
void scrie_Permisiuni(mode_t mode);
void scrie_Tip_Fisier(mode_t mode);

int main(int argc, char* argv[])
{
  return 0;
}

void scrie_Permisiuni(mode_t mode)
{
  putchar((mode & S_IRUSR) ? 'r' : '-');
  putchar((mode & S_IWUSR) ? 'w' : '-');
  putchar((mode & S_IXUSR) ? 'x' : '-');
  putchar((mode & S_IRGRP) ? 'r' : '-');
  putchar((mode & S_IWGRP) ? 'w' : '-');
  putchar((mode & S_IXGRP) ? 'x' : '-');
  putchar((mode & S_IROTH) ? 'r' : '-');
  putchar((mode & S_IWOTH) ? 'w' : '-');
  putchar((mode & S_IXOTH) ? 'w' : '-');
}

void scrie_Tip_Fisier(mode_t mode)
{
  switch(mode & S_IFMT)
  {
    case S_IFREG: putchar('-'); break;
    case S_IFDIR: putchar('d'); break;
    case S_IFLNK: putchar('l'); break;
    case S_IFCHR: putchar('c'); break;
    case S_IFBLK: putchar('b'); break;
    case S_IFSOCK: putchar('s'); break;
    case S_IFIFO: putchar('f'); break;
  }
}
