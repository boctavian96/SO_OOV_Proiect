#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SIZE 256
#define STR_SIZE 1024

void mySort(char *str[], int n);
void afisareLista(char *str[], int n);

int main(int argc, char* argv[])
{
  FILE *f; //Fila 
  char buff[SIZE]; // Buffer
  char *strList[STR_SIZE]; //Lista cuvinte
  int n = 0; //Contor linii
  int i; //Contor

  //Citire din fisier
  f = fopen(argv[1], "r");

  if(f == 0)
  {
    fprintf(stderr, "Eroare la deschiderea fisierului !!!");
  }

  while(!feof(f))
  {
    fgets(buff, SIZE, f); //Citire linie
    strList[n] = strdup(buff); 
    n++;
  }

  printf("Numar linii : %d\n", n);

  //afisareLista(strList, n);

  mySort(strList, n);

  afisareLista(strList, n);

  fclose(f);

  return 0;
}

void mySort(char *str[], int n)
{
  char *temp; //Variabila auxiliara
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
}


void afisareLista(char* str[], int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%s", str[i]);
  }
}
