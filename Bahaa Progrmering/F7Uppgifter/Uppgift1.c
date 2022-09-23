#include <stdio.h>
#include <math.h>

 int num(int m, int n)
{
    
    int gcd;
    while (n != 0)
{
        int gcd = m % n;
        m = n;
        n = gcd;
}
return gcd;
}
int main()
{
    printf("Enter two numbers: ");
    scanf("%d%d", &num);
    printf("Greatest comon divisor: %d \n",num);


    return 0;
}


