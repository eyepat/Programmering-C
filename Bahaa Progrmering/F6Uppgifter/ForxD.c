#include <stdio.h>
#include <math.h>


float circleArea(float radius);

    int main()
{
    printf("En cirkel med radien 2 har arean: %.2f\n",circleArea(2));
    float r=4;
    printf("En cirkel med radien %.2f har arean: %.2f",r,circleArea(r));
    return 0;
 }
 
    float circleArea(float radius)
{
    float area;
    area = radius*radius*M_PI;
    return area;
}
