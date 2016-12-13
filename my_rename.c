#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main(int argc,char* argv[])
{
    int i = 3;
    int vCommand=0;
    int hCommand=0;
    int nCommand=0;
    char *firstName;
    char *secondName;
    if(argv[1]!=NULL)
    {
        firstName = malloc(sizeof(char)*strlen(argv[1])+1);
        strcpy(firstName,argv[1]);
    }
    else
    {
        printf("Not enough arguments!  ex: oldfile/dir newfile/dir\n");
        return 1;
    }
    if(argv[2]!=NULL)
    {
        secondName = malloc(sizeof(char)*strlen(argv[2])+1);
        strcpy(secondName,argv[2]);
    }
    else
    {
        printf("Not enough arguments!  ex: oldfile/dir newfile/dir\n");
        return 1;
    }
    while(i<argc)
    {

        if(strcmp(argv[i],"-v")==0)
        {
            vCommand = 1;
        }
        if(strcmp(argv[i],"-h") == 0)
        {
            hCommand = 1;
        }
        if(strcmp(argv[i],"-n") == 0)
        {
            nCommand = 1;
        }

        i++;
    }
    int ok = 0;
    if(hCommand!=0)
        ok++;
    if(nCommand!=0)
        ok++;
    if(vCommand!=0)
        ok++;
    if(ok>=2)
        printf("Too many arguments in the declaration !\n");
    else
    {
        if(nCommand ==0 && vCommand == 0 && hCommand ==0)
        {
              int succeded = MoveFile(firstName,secondName);
              if(succeded == 0)
                printf("File or directory not exist %s",firstName);
        }
        if(nCommand!=0)
        {
            int succeded = MoveFile(firstName,secondName);
            if(succeded != 0)
            {
                printf("File exist and it's ready to be modified.\n");
                MoveFile(secondName,firstName);
            }
            else
                printf("Couldn't find the specific file to modify!");
        }
        if(vCommand!=0)
        {
            int succeded = MoveFile(firstName,secondName);
            if(succeded == 0)
                printf("File or directory not exist %s",firstName);
            else
                printf("Succeded to rename, %s to %s",firstName,secondName);
        }
        if(hCommand!=0)
        {
            printf("The use of this command is to rename a certain file or directory.\nAn example: rename file1.txt file2.txt will rename the file1 into file2 \nThere are a few arguments that you can provide such as: -v,-n,-h, \n-h stands for help\n-v try to rename the file/directory and if succeded then prints the new file/directory\n\-n try to see if the user can rename the file but dont rename it.\n");
        }
    }
}
