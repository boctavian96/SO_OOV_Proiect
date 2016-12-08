#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*
Autor: Octavian Bodnariu
Versiune: 1.0
*/

void versiune(const char* v);
void help();
int main(int argc, char* argv[])
{
  char *c;
  const char *ver = "Versiunea 1.0\nAutor:Octavian Bodnariu\nEmail:boctavian96@yahoo.com\n";
  
  if(argv[1] != NULL)
  {
	  if(strcmp(argv[1], "--version")==0) //Daca argumentul este exact "--version" atunci afiseaza versiunea
      versiune(ver);
  	if(strcmp(argv[1], "--help")==0) //Daca argumentul este exact "--help" atunci afiseaza help-ul
      help();
  }
  //Verificam daca argumentul este null
  if(argv[1] == NULL)
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
    if(strcmp(argv[1],"--version") != 0 && strcmp(argv[1],"--help") != 0)
      do
      {
        c = malloc(sizeof(char*));
        c = argv[1];
        printf("%s \n", c);
      }while(c != NULL);
  }
  return 0;
}

//Alte functii
void versiune(const char *v)
{
  printf("%s", v);
}

void help()
{
  printf("Comanda myes va scrie \'y\' in consola sau orice are ca argument urmat de o linie noua\nProcesul se repeta pana cand procesul este ucis(Ctrl + C)\n");
}
