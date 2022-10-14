#include <stdio.h>

int main()
{
int m,d,y;

printf("Enter a date (mm/dd/yyyy)");
scanf("%d/%d/%d",&m,&d,&y);
printf("your entered the date %d%.2d%d\n\n", y,m,d);

//%d%.2d%.2d


    return 0;
}