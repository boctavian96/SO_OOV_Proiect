#include <sys/wait.h> // waitpid()
#include <unistd.h> // fork(), exec(), pid
#include <stdio.h>
#include <stdlib.h> // exit(), execvp()
#include <string.h> //Pentru strtok()

#define BUFFSIZE 64
#define SEPARATOR " \t\r\n\a"
#define ALOC_ERR fprintf(stderr,"Allocation error !")

/*
Basic loop :
  1.Citim comanda din stdin
  2.Parsare, separam stringul in comanda si argumente
  3.Executam comanda parsata
*/

/*
Info:

Autor : Octavian Bodnariu
Implementari: Shell, yes, sort

Autor : Vasile Anisorac
Implementari: ls, help + documentatie

Autor : Ovidiu Andrasesc
Implementari: cal, rename, locate


Versiune 1.2.5

*/
//Functii specifice shell-ului
char *citireLinie();
char *parsareLinie(char *linie);
int lansare(char **argumente);
int executa(char **argumente);
void buclaPrincipala();
//Functii implementate
int my_help(char **argumente);
int my_version(char **argumente);
int my_exit(char **argumente);
int my_yes(char **argumente);
int my_sort(char **argumente);
int my_ls(char **argumente);
int my_cal(char **argumente);
int my_rename(char **argumente);
int my_locate(char **argumente);
//Lista de comenzi(String)
char *comenzi[] = {
  "myHelp",
  "myVersion",
  "myYes",
  "mySort",
  "myLs",
  "myCal",
  "myLocate",
  "myRename",
  "exit"
};
//Lista in care vor intra functiile cu comenzile construite
int (*comenzi_construite[])(char**) = {
  &my_help,
  &my_version,
  &my_yes,
  &my_sort,
  &my_cal,
  &my_ls,
  &my_locate,
  &my_rename,
  &my_exit
};

int terminal_num_comenzi_construite()
{
  return sizeof(comenzi) / sizeof(char*);
}

int main(int argc, char* argv[])
{
  buclaPrincipala();
  return EXIT_SUCCESS;
}

char *citireLinie()
{
  int bufsize = BUFFSIZE;
  int pozitie = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if(!buffer)
    {
        ALOC_ERR;
    }
    while(1)
    {
        c = getchar();

        if(c == EOF || c== '\n')
        {
            buffer[pozitie] = '\0';
            return buffer;
        }
        else
        {
            buffer[pozitie] = c;
        }
        pozitie++;

        if(pozitie >= bufsize)
        {
            bufsize += BUFFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer)
            {
                ALOC_ERR;
                exit(EXIT_FAILURE);
            }
        }
    }
}

char *parsareLinie(char *linie)
{
  int buffer = BUFFSIZE;
  int pozitie = 0;
  char **tokens = malloc(buffer * sizeof(char*));
  char *token, **tokens_backup;

  if(!tokens)
  {
    ALOC_ERR;
    exit(EXIT_FAILURE);
  }

  token = strtok(linie, SEPARATOR);
  while(token != NULL)
  {
    tokens[pozitie] = token;
    pozitie++;

    if(pozitie >= buffer)
    {
      buffer+= BUFFSIZE;
      tokens = realloc(tokens, BUFFSIZE * sizeof(char*));
      if(!tokens)
      {
        ALOC_ERR;
        exit(EXIT_FAILURE);
      }
    }

  token = strtok(NULL, SEPARATOR);
  }
  tokens[pozitie] = NULL;
  return tokens;
}

int lansare(char **argumente)
{
  pid_t pid;
  int status;

  pid = fork();

  if(pid == 0)
  {
    //Proces copil
    if(execvp(argumente[0], argumente) == -1)
    {
      perror("LNS");
    }
    exit(EXIT_FAILURE);
  }
  else if(pid < 0)
  {
    //EROARE LA FORK() !!!
    perror("LNS-fork");
  }
  else
  {
    do
    {
      waitpid(pid, &status, WUNTRACED);
    }while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
int executa(char **argumente)
{
    int i;

    if(argumente[0] == NULL)
    {
        return 1;
    }
    for(i = 0; i < terminal_num_comenzi_construite(); i++)
    {
        if(strcmp(argumente[0], comenzi[i]) == 0)
            return (*comenzi_construite[i])(argumente);
    }
}
void buclaPrincipala()
{
  char *linie;
  char **argumente;
  int status;

  do
  {
    printf("%s$> ", "Octavian");
    linie = citireLinie();
    argumente = parsareLinie(linie);
    status = executa(argumente);

    free(linie);
    free(argumente);
  }while(status);

}
//VASILE
int my_help(char **argumente)
{
  int i; //Contor
  printf("Proiect Sisteme de operare\n");
  printf("Scrieti numele programului si argumentele si apasa ENTER\n");
  printf("Urmatorele instructiuni sunt construite: \n");

  for(i = 0; i < terminal_num_comenzi_construite(); i++)
  {
    printf(" %s\n", comenzi[i]);
  }

  printf("Folositi help si numele programului pentru mai mult ajutor\n");
  return 1;
}
//VASILE
int my_version(char **argumente)
{
  return 1;
}
//Iesirea
int my_exit(char **argumente)
{
  return 0;
}
//OCTAVIAN
int my_yes(char **argumente)
{
  return 1;
}
//OCTAVIAN
int my_sort(char **argumente)
{
  return 1;
}
//VASILE
int my_ls(char **argumente)
{
  return 1;
}
//OVIDIU
int my_cal(char **argumente)
{
  return 1;
}
//OVIDIU
int my_rename(char **argumente)
{
  return 1;
}
//OVIDIU
int my_locate(char **argumente)
{
  return 1;
}
