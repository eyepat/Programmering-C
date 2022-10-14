#include <stdio.h>

int main ()
{
int a, b; 
    printf("Ange a: "); 
    scanf("%d",&a); 
    printf("Ange b: "); 
    scanf("%d",&b); 
    
    int tmp = a;
    a = b;
    b = tmp;

    printf("a: %d, b: %d",a,b); 



    return 0;
}




