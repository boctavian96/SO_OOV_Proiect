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

	if (argv[1]=="my_cal")
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

        return 0;
}
