#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*
Autor: Octavian Bodnariu
Versiune: 1.1
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
