#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SIZE 256
#define STR_SIZE 1024

void mySort(char* str[], int n);
void afisareLista(char* str[], int n);
void revSort(char* str[], int n);
void mySortRandom(char *str[], int n);
void mySortPermanentSort(char *str[], char *fileName, int n);
int my_sort(char**);

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

