#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "size.h"
//#include <windows.h>


int determinedaycode(int );
int determineleapyear(int);
int zile_luna[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void afisareCalendar(int daycode, int luna);
int my_cal(char **argv)
{
    int argc = arg_size(argv);
    int LUNA = 0;
    int ANUL = 0;
    int HIGHLIGHT = 1;
    int COUNT = 1;
    while(COUNT<argc)
    {
        if(strcmp(argv[COUNT],"-h")==0)
            HIGHLIGHT = 0;
        if(strcmp(argv[COUNT],"-m")==0)
        {
            LUNA = atoi(argv[COUNT+1]);
            printf("Month is: %d\n",LUNA);
            if(LUNA <=0 || LUNA > 12)
            {
                printf("Error on assigment, -m can only be between (1,12)\n");
                LUNA = 0;
            }
        }
        if(strcmp(argv[COUNT],"-y")==0)
        {
            ANUL = atoi(argv[COUNT+1]);
            printf("ANUL IS: %d\n",ANUL);
            if(ANUL <=1700 || ANUL >= 2099)
            {
                printf("Error on assigmend, -y can only be between(1700,2099)\n");
                ANUL = 0;
            }
        }
        COUNT++;
    }


    time_t t = time(NULL);
    struct tm gmt = *gmtime(&t);
    struct tm localt = *localtime(&t);
    int luna = gmt.tm_mon+1;
    int anul = gmt.tm_year+1900;
    if(LUNA != 0)
    {
        luna = LUNA;
        if(luna != gmt.tm_mon+1)
            HIGHLIGHT = 0;
    }
    if(ANUL != 0)
    {
        anul = ANUL;
        if(ANUL != gmt.tm_year+1900)
            HIGHLIGHT = 0;
    }
    char* firstLine = malloc(sizeof(char)*20);
    char* secondLine = malloc(sizeof(char)*1024);
    strcpy(secondLine,"");
    strcat(secondLine,"Du   Lu   Ma   Mi   Jo   Vi   Sa");
    strcpy(firstLine,"       ");
    switch(luna)
    {
    case 1:
        strcat(firstLine,"Ianuarie");
        break;
    case 2:
        strcat(firstLine,"Februarie");
        break;
    case 3:
        strcat(firstLine,"Martie");
        break;
    case 4:
        strcat(firstLine,"Aprilie");
        break;
    case 5:
        strcat(firstLine,"Mai");
        break;
    case 6:
        strcat(firstLine,"Iunie");
        break;
    case 7:
        strcat(firstLine,"Iulie");
        break;
    case 8:
        strcat(firstLine,"August");
        break;
    case 9:
        strcat(firstLine,"Septembrie");
        break;
    case 10:
        strcat(firstLine,"Octombrie");
        break;
    case 11:
        strcat(firstLine,"Noiembrie");
        break;
    case 12:
        strcat(firstLine,"Decembrie");
        break;
    default:
        strcat(firstLine,"Unknow month");
    };
    char *day = malloc(sizeof(char)*10);
   // itoa(gmt.tm_mday,day,10);
    snprintf(day,10,"%d",gmt.tm_mday);
    strcat(firstLine,"  ");


    char*tempBuff = malloc(sizeof(char)*10);
    //printf("bufF:%s",buff);
 snprintf(tempBuff,5,"%d",anul);
//    itoa(anul,tempBuff,10);
    strcat(firstLine,day);
    strcat(firstLine," - ");
    strcat(firstLine,tempBuff);
    printf("\n%s\n\n%s\n\n",firstLine,secondLine);
    
   // free(firstLine);
   // free(secondLine);
   // free(day);

//    HANDLE hConsole;
//  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    int daycode = determinedaycode(anul);
    int days,i;
    determineleapyear(anul);

    for(i=1;i<=luna-1;i++)              // doar modificare in args, daca e -m sa puna valoarea de argc[2], ce e dupa ala si meree
        daycode = ( daycode + zile_luna[i] ) % 7;
    for ( days = 1; days <= 1 + daycode * 5; days++ )
    {
        printf(" ");
    }
    for ( days = 1; days <= zile_luna[luna]; days++ )
    {
//        if(gmt.tm_mday == days && /*HIGHLIGHT == 1)
//            SetConsoleTextAttribute(hConsole, 12);
  //      else
//            SetConsoleTextAttribute(hConsole, 15);
        printf("%2d", days );
        if ( ( days + daycode ) % 7 > 0 )
            printf("   " );
        else
            printf("\n " );
    }
	printf("\n");
	return 1;

}
int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1)/ 4;
    d2 = (year - 1)/ 100;
    d3 = (year - 1)/ 400;
    daycode = (year + d1 - d2 + d3) %7;
    return daycode;
}
int determineleapyear(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	{
		zile_luna[2] = 29;
		return 1;
	}
	else
	{
		zile_luna[2] = 28;
		return 0;
	}
}
