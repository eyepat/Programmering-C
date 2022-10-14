#include <stdio.h>

int main()
{
int Number, i;

printf("Enter a number:");
scanf( "%d", &Number);

if (Number > 0 && Number < 10){
i = 1;
printf("The number %d  has %d digits" ,Number ,i);
}

else if ( Number >= 10 && Number < 100){
i = 2;
printf("The number %d  has %d digits" ,Number ,i);
}

else if (Number >= 100 && Number < 1000){
 i = 3;
printf("The number %d  has %d digits" ,Number ,i);

}
else if (Number >=1000){
i= 4;
printf("The number %d  has %d digits" ,Number ,i);
}


    return 0;
}