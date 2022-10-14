#include <stdio.h>

int main()
{ 
float r1,r2,rtot; 
printf("Resistans hos R1 (ohm) : "); 
scanf("%f",&r1); 
printf("Resistans hos R2 (ohm) : "); 
scanf("%f",&r2);
rtot = r1*r2/(r1+r2); 
printf("Parallellkoppling: %6.5f ohm\n",rtot);

return 0;
} 


