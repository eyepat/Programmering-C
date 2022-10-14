/*#include <stdio.h>
#define SIZE 6 
    int main()
{
    int i, draw;
    int a[SIZE];
    draw = a[0];
    
    printf("Enter a number %d :" ,i);
        scanf("%d", &a[i]);

        draw = 0;
     for(i=1; i<SIZE; i++ )
     {
        if(a[i] = a[draw])
        draw = i;

     }

     printf("max digit in your phone number is %d", i);
    


    return 0;
}
*/

#include <stdio.h>
#define SIZE 6
main()
{
   int num[SIZE];
   int i=0, j=0;

   printf("Enter a number %d :" ,i);
        scanf("%d", &num[i]);

   for (i=0; i < SIZE; i++ ){
       for (j=i+1; j < SIZE; j++){
            if((num[i]^ num[j]) == 0){
                printf("Repeated digit(s): %d\n", num[i]);
                break;
            }
       }
   }
   return 0;
}   