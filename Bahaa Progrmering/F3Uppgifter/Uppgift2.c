#include <stdio.h>
int main ()
{
int sum;
for ( sum = 1; sum <= 10; sum++)
{
    printf(" %d", sum);
}


for ( sum = 10;  sum > 0;  sum-= 2 );
{

    printf(" %d ", sum);
}

for ( sum = 1;  sum <= 32;  sum *= 2 );
{

    printf(" %d ", sum);
}



    return 0;
}