#include <stdio.h>
int main()
{
float number, largest;
largest = 0.0f;
   do {
     printf("Enter the number (Enter 0 to end):");
      scanf(" %f" ,&number);
  if (number > largest)
       largest = number;
     }
     while (number > 0.0f);

   printf("\nThe largest number entered was %.2f", largest);

    return 0;
}