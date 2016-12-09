#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

/*
Autor : Vasile Anisorac
*/

int main(int argc, char* argv[])
{
        int fd, bytesRead, i = 1;
        char* buff, my_cal;

        if (argc <= 1)
        {
                printf("introduceti numele comenzii dupa  %s !\n", argv[0]);
                return 1;
        }

	if (argv[1]=="my_cal")// afisarea pe linia de comanda a documentatiei pentru comanda my_cal
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
	
 	if (argv[1]== "-d" && argv[2]=="my_cal")// descrierea intr-un rand a comenzii my_cal
	{
		printf("displays a calendar and the date of Easter\n");
	}
 	if (argv[1]=="my_yes")// afisarea pe linia de comanda a documentatiei pentru comanda my_yes
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
	
	if (argv[1]== "--version" && argv[2]=="my_yes")// afisarea versiunii comenzii my_yes
	{
		printf("yes (GNU coreutils) 8.25 \n Copyright (C) 2016 Free Software Foundation, Inc.\n");
	}
	
	if (argv[1]=="my_rename")// afisarea pe linia de comanda a documentatiei pentru comanda my_rename
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
	
	if (argv[1]=="my_sort")// afisarea pe linia de comanda a documentatiei pentru comanda my_sort
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
	
	if (argv[1]=="my_ls")// afisarea pe linia de comanda a documentatiei pentru comanda my_ls
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
	
	if (argv[1]=="my_locate")// afisarea pe linia de comanda a documentatiei pentru comanda my_locate
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
	
        return 0;
}
