#include <stdio.h>


int main()
{
float NpOffCds, Price;
Price = 9.90;

printf("How many Cds you wanna shop?");
scanf("%f" ,&NpOffCds);

if (NpOffCds < 11){
Price = NpOffCds * 9.90;
}

else if (NpOffCds < 51){
Price = NpOffCds * 9.90 *0.95; 
}

else if (NpOffCds > 51){
Price = NpOffCds * 9.90 * 0.9;
}

printf("Price is %.1f Kr", Price);

    return 0;
}