#include <stdio.h>

int main()
{
 float volume, rad, P;
P = 3.14159265359f;
 printf("Enter the Radius:");
 scanf("%f" ,&rad);

volume = 4.0f / 3.0f * P * (rad * rad * rad);
printf("The volume of a sphere is %.3f\n",  volume);

return 0;
}