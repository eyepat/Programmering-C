#include <stdio.h>
int main()
{
int amount,n20,n10,n5,n1;

printf("Enter a dollar amount:");
scanf("%d", &amount);

n20 = amount /20;
amount = amount - (n20 * 20);
printf("$20 bills: %d \n", n20);

n10 = amount /10;
amount = amount - (n10 * 10);
printf("$10 bills: %d \n", n10);

n5 = amount /5;
amount = amount - (n5 * 5);
printf("$5 bills: %d \n", n5);

n1 = amount /1;
amount = amount - (n1 * 1);
printf("$1 bills: %d \n", n1);


    return 0;
}

