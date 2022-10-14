#include <stdio.h>

int main()
{
int n,i,k;

printf("Enter a two-digit number");
scanf("%d", &n);
i = n % 10;
k = n /10; 




printf("The reversal is: %d%d" ,i,k);

    return 0;
}