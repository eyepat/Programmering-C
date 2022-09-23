#include <stdio.h>
int main()
{
int Number, i;
printf("Enter a wind speed(in knots) :");
scanf("%d" , &Number);
if (Number < 1 ){

    printf("Calm");
}
else if (Number >= 1 && Number <= 3){

    printf("Light air");
}
else if (Number >= 4 && Number <= 27){

    printf("Gale");
}
else if (Number >= 48 && Number <= 63){

    printf("Storm");
}
else if (Number >= 64){

    printf("Hurricane");
}


    return 0;
}