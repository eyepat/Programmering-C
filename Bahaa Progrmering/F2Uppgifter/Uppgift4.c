#include <stdio.h>

int main()
{
int number,i,k,h;

printf("Enter a three-digit number");
scanf("%d", &number);
 
i = number / 100;     // 456 = 4
k = number % 10;      //  56 = 
h = (number / 10) % 10;
     

   
    




printf("The reversal is: %d%d%d" ,k,h,i);

    return 0;
}