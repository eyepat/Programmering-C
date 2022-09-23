#include <stdio.h>
int main()
{
int distance,speed,time;

printf("Hur lang tid?");
scanf("%d" , &time);
printf("Hur fort?");
scanf("%d" , &speed);

distance = speed * time;
printf("med %d km/h kommer du att fardas %d km \n" ,speed,distance);
printf("lycka till pa farden");

    return 0;
}  
