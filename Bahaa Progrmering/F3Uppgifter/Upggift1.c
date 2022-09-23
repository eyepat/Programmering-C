#include <stdio.h>
 
 int main()
 {
int num;
num = 1;
    while ( num <= 10)
    {
        printf("%d " ,num);
        num = num + 1;
    }

    num = 10;
    while(num >= 0)
    {
      printf("  %d  " ,num);
      num = num - 2;
    }

    num = 1;
    while( num <= 32)
    {
    printf( " %d" , num);
    
    num = num * 2;

}
    return 0;
 }