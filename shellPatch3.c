#include <sys/wait.h> // waitpid()
#include <unistd.h> // fork(), exec(), pid
#include <stdio.h>
#include <stdlib.h> // exit(), execvp()
#include <string.h> //Pentru strtok()
#include <time.h> //Pentru randomize

#define BUFFSIZE 64
#define SEPARATOR " \t\r\n\a"
#define ALOC_ERR fprintf(stderr,"Allocation error !")

//Sort
#define SIZE 256
#define STR_SIZE 1024

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

/*---------------------------> Functii specifice comenzilor <---------------------------------------- */

//Sort
void mySort(char *str[], int n);
void mySortRandom(char *str[], int n);
void mySortPermanentSort(char *str[], char* fileName, int n);
void revSort(char* str[], int n);
void afisareLista(char *str[], int n);


//Lista de comenzi(String)
char *comenzi[] = {
  "my_help",
  "my_Version",
  "my_yes",
  "my_sort",
  "my_ls",
  "my_cal",
  "my_locate",
  "my_rename",
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
/**
@return : Numarul de comenzi pe care il stie terminalul
*/
int terminal_num_comenzi_construite()
{
  return sizeof(comenzi) / sizeof(char*);
}
/**
Main-ul
*/
int main(int argc, char* argv[])
{
  buclaPrincipala();
  return EXIT_SUCCESS;
}
/**
Citirea unei linii din terminal
*/
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
/**
@param : O linie care s-a citit din stdin
@return : Linia parsata cu strtok()
*/
char *parsareLinie(char *linie)
{
  int buffer = BUFFSIZE;
  int pozitie = 0;
  char **tokens = malloc(buffer * sizeof(char*));
  char *token;

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
/**
@param : Un string de tip array parsat
@return : Intotdeauna 1
*/
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
/**
@param : 
@return : Adresa unei functii definite (poate fi 0 sau 1)
*/
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
/**
Aceasta procedura grupeaza toate functiile scrise anterior si functioneaza
cat timp statusul este diferit de 0. Adica nu s-a activat comanda exit
*/
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
/**
@param :
@return :
*/
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
/**
@param : Argument primit de la linia de comanda
@return : Intotdeauna 0. Inchide terminalul
*/
int my_exit(char **argumente)
{
  return 0;
}
//OCTAVIAN
/**
@param : Argumente primite din linia de comanda
@exemple : my_yes [STRING] ; my_yes [NULL] ;
@return : Intotdeauna 1
*/
int my_yes(char **argumente)
{
  char *c;
  const char *ver = "Versiunea 1.0\nAutor:Octavian Bodnariu\nEmail:boctavian96@yahoo.com\n";
  int argc = sizeof(argumente)/sizeof(*argumente);
  int arglen = argc>1 ? strlen(argumente[1] + 1) : 0;
  int i = 1;
  char *argument = malloc(sizeof(char));

  if(argc > 1)
    while(i < argc)
    {
      argument = strcat(argument, argumente[i]);
      argument = strcat(argument, " ");
      i++;
    }

  if(argumente[1] != NULL)
  {
	  if(strcmp(argumente[1], "--version")==0) //Daca argumentul este exact "--version" atunci afiseaza versiunea
      //versiune(ver);
  	if(strcmp(argumente[1], "--help")==0) //Daca argumentul este exact "--help" atunci afiseaza help-ul
    {
      //help();
    }
  }
  //Verificam daca argumentul este null
  if(argumente[1] == NULL)
  {
    do
    {
      c = (char*) malloc(sizeof(char*));
      *c = 'y';
      printf("%s \n", c);
    }while(c != NULL);
  }
  else
  {
    if(strcmp(argumente[1],"--version") != 0 && strcmp(argumente[1],"--help") != 0)
      do
      {
        c = (char*)malloc(sizeof(char) * arglen);
        c = argument;
        printf("%s \n", c);
      }while(c != NULL);
  }
  return 1;
}
//OCTAVIAN
int my_sort(char **argumente)
{
  FILE *f; //Fila
  char buff[SIZE]; // Buffer
  char *strList[STR_SIZE]; //Lista cuvinte
  int n = 0; //Contor linii
  int i; //Contor

  //Citire din fisier
  f = fopen(argumente[1], "r");
          if(f == 0)
        {
            fprintf(stderr, "Eroare la deschiderea fisierului !\nConsultati \'--help\' pentru ajutor !\n");
            return -1;
        }

        while(!feof(f))
        {
            fgets(buff, SIZE, f); //Citire linie
            strList[n] = strdup(buff);
            n++;
        }
        strList[n] = NULL;
        n--;

        printf("Numar linii : %d\n", n);

    if(argumente[2])
    {	
    	if(strcmp(argumente[2], "-r") == 0)
        {
            mySortRandom(strList, n);
        }
    	if(strcmp(argumente[2], "-p") == 0)
        {
            mySortPermanentSort(strList, argumente[1], n);
        }
      if(strcmp(argumente[2], "-rev") == 0)
        {
            revSort(strList, n);
        }
    }
    else
    {
      mySort(strList, n);
    }

  afisareLista(strList, n);
  fclose(f);
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

void mySort(char *str[], int n)
{
  char *temp = malloc(sizeof(char)); //Variabila auxiliara
  int i, j; //Contoare

  for(i = 0; i < n; i++)
    for(j = 0; j < n-1; j++)
    {
      if(strcmp(str[j], str[j+1]) > 0)
      {
        strcpy(temp, str[j]);
        strcpy(str[j], str[j + 1]);
        strcpy(str[j + 1], temp);
      }
    }
  free(temp);
  //afisareLista(str, n);
}

void afisareLista(char* str[], int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%s", str[i]);
  }
}

void mySortRandom(char *str[], int n)
{
  int p1, p2;
  int i = 0;
  char* temp = malloc(sizeof(char));
  
  if(n > 1)
  {
    size_t i;
    for(i = 0; i < n - 1; i++)
    {
      size_t j = i + rand()/(RAND_MAX/(n-i)+1);
      strcpy(temp, str[i]);
      strcpy(str[i], str[j]);
      strcpy(str[j], temp);
    }
  }
  free(temp);
  //afisareLista(str, n);
}

void mySortPermanentSort(char *str[], char *fileName, int n)
{
  char *temp = malloc(sizeof(char)); //Variabila auxiliara
  int i, j; //Contoare

  for(i = 0; i < n; i++)
    for(j = 0; j < n-1; j++)
    {
      if(strcmp(str[j], str[j+1]) > 0)
      {
        strcpy(temp, str[j]);
        strcpy(str[j], str[j + 1]);
        strcpy(str[j + 1], temp);
      }
    }
  free(temp);

  FILE *f = fopen(fileName, "w");

    for(i = 0; i < n; i++)
    {
        fprintf(f, "%s", str[i]);
    }

    fclose(f);

}

void revSort(char* str[], int n)
{
  char *temp = malloc(sizeof(char)); //Variabila auxiliara
  int i, j; //Contoare

  for(i = 0; i < n; i++)
    for(j = 0; j < n-1; j++)
    {
      if(strcmp(str[j], str[j+1]) < 0)
      {
        strcpy(temp, str[j]);
        strcpy(str[j], str[j + 1]);
        strcpy(str[j + 1], temp);
      }
    }
  free(temp);

}
