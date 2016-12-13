#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int my_echo(char** argv)
{
    int argc = arg_size(argv);
    int i=1;
    int decision = 0;
    char buff[1024];
    strcpy(buff,"");

    if(argc>1)
    {
        while(i<argc)
        {
            if(strcmp(argv[i],"-e")==0)
            {
                decision = 1;    // deci ramane totul asa cum ii, si afiseaza textul
            }
            else if(strcmp(argv[i],"-E")==0)
            {
                decision = 2;   // anuleaza toate  \a,\b\c..
            }
            else if(strcmp(argv[i],"-n")==0)
            {
                decision = 3;   // nu afiseaza \n
            }
            else
            {
                strcat(buff,argv[i]);
                strcat(buff," ");
            }
            i++;
        }
    }
    else
    {
        printf("No arguments provided,by default only this message prints.\n");
        exit(0);
    }
    if(decision!=0)
    {
        switch(decision)
        {
        case 1:
            for(i=0; i<strlen(buff); i++)
            {
                if(buff[i]=='\\' && buff[i+1] =='a')
                {
                    printf("\a");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='b')
                {
                    printf("\b");
                    i++;
                }

                else if(buff[i]=='\\' && buff[i+1] =='e')
                {
                    printf("\e");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='f')
                {
                    printf("\f");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='n')
                {
                    printf("\n");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='r')
                {
                    printf("\r");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='t')
                {
                    printf("\t");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='v')
                {
                    printf("\v");
                    i++;
                }
                else if(buff[i]=='\\' && buff[i+1] =='\\')
                {
                    printf("\\");
                    i++;
                }
                else
                    printf("%c",buff[i]);
            }
            break;
        case 2:
            for(i=0; i<strlen(buff); i++)
            {
                if(buff[i]=='\\'&&(buff[i+1]=='a' || buff[i+1]=='b' || buff[i+1]=='e'|| buff[i+1]=='f'|| buff[i+1]=='n'|| buff[i+1]=='r' || buff[i+1]=='t' || buff[i+1]=='v'|| buff[i+1]=='\\'))
                {
                    i++;
                }
                else
                    printf("%c",buff[i]);
            }
            break;
        case 3:
            for(i=0; i<strlen(buff); i++)
            {
                if(buff[i]=='\\'&& buff[i] =='n')
                {
                    i++;
                }
                else if(buff[i]=='\\'&&(buff[i+1]=='a' || buff[i+1]=='b' || buff[i+1]=='e'|| buff[i+1]=='f'|| buff[i+1]=='r' || buff[i+1]=='t' || buff[i+1]=='v'|| buff[i+1]=='\\'))
                {
                    // parantezaaa
                    if(buff[i]=='\\' && buff[i+1] =='a')
                    {
                        printf("\a");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='b')
                    {
                        printf("\b");
                        i++;
                    }

                    else if(buff[i]=='\\' && buff[i+1] =='e')
                    {
                        printf("\e");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='f')
                    {
                        printf("\f");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='r')
                    {
                        printf("\r");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='t')
                    {
                        printf("\t");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='v')
                    {
                        printf("\v");
                        i++;
                    }
                    else if(buff[i]=='\\' && buff[i+1] =='\\')
                    {
                        printf("\\");
                        i++;

                    }
                }
                else
                    printf("%c",buff[i]);
            }

            break;
        }
    }
        else
        {
            printf("%s",buff);
        }
        printf("\n");
        return 1;


}


