#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "size.h"

#define SIZE2 10

int my_help(char** argv)
{
        int fd, bytesRead, i = 1;
        char* buff, my_cal;
	int argc = arg_size(argv);

        if (argc <= 1)
        {
                printf("introduceti numele comenzii dupa  %s !\n", argv[0]);
                return 1;
        }

	if (strcmp (argv[1],"my_cal")==0)// afisarea pe linia de comanda a documentatiei pentru comanda cal
	{


		fd = open("my_cal.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (argv[1]== "-d" && argv[2]=="my_cal")// descrierea intr-un rand a comenzii cal
		{
		printf("displays a calendar and the date of Easter\n");
		}

   if (strcmp (argv[1],"my_yes")==0)// afisarea pe linia de comanda a documentatiei pentru comanda yes
	{


		fd = open("my_yes.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (strcmp (argv[1],"-version")==0 && strcmp (argv[2],"my_yes")==0)// afisarea versiunii comenzii yes

		{
		printf("yes (GNU coreutils) 8.25 \n Copyright (C) 2016 Free Software Foundation, Inc.\n");
		}

	if (strcmp (argv[1],"my_rename")==0)// afisarea pe linia de comanda a documentatiei pentru comanda my_rename
	{


		fd = open("my_rename.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (strcmp (argv[1],"my_sort")==0)// afisarea pe linia de comanda a documentatiei pentru comanda my_sort
	{


		fd = open("my_sort.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (strcmp (argv[1],"my_ls")==0)// afisarea pe linia de comanda a documentatiei pentru comanda my_ls
	{


		fd = open("my_ls.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (strcmp (argv[1],"my_locate")==0)// afisarea pe linia de comanda a documentatiei pentru comanda my_locate
	{


		fd = open("my_locate.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

	if (strcmp (argv[1],"my_help")==0)// afisarea pe linia de comanda a documentatiei pentru comanda my_help
	{

		fd = open("my_help.txt", O_RDONLY);

		 buff = malloc(sizeof(char *) * SIZE);
                        while ((bytesRead = read(fd, buff, SIZE)) > 0)
                        {
                                buff[bytesRead] = '\0';
                                printf("%s", buff);
                        }
                        free(buff);
		close(fd);
	
	}

        return 1;
}
