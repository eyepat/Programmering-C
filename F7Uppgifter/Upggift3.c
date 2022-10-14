#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int funktion1(int *num, int number);
int funktion2(int *num, int number);
int funktion3(int *num, int number);

int main ()
{
  int number;
    printf("Enter the integer: ");
    scanf("%d" ,&number);
  int num[number];

    funktion2(num, number);
    funktion1(num, number); 
    funktion3(num, number);
    printf("\n");
    funktion1(num, number);
   return 0;
}

int funktion1(int *num, int number)
{

    for (int i = 0; i < number ; i++)
  {
    printf("%d  ",num[i]);
  }
} 

  int funktion2(int *num, int number)
{
  int lower = -10, upper = 10;
   int randomN;
   srand(time(0));
  
  for (int i = 0; i < number ; i++)
  {
   
    randomN = (rand() % (upper - lower + 1)) + lower;
      num[i]=randomN;
  }
}

int funktion3(int *num,int number)
{
       int differens;
       for (int i = 0; i < number; i++)
        {
          for (int t = i+1; t < number ; t++)
          {
          if(num[i] > num[t])
        {
            differens= num[i];
            num[i] = num[t];
            num[t] = differens;  
        }
      }
    }
 }



