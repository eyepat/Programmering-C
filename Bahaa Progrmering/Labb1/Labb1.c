#include <stdio.h>
int main ()
{
    int Time, Throttle;
    float Height, Velocity;

    Velocity = -25;
    Height = 250;
    Time = 0;

    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m.\nEach turn represent 1-seconf decent time.\n");
    printf("Set the throttle for each turn (0-100) \nTime  Height  Velocity  Throttle?\n");

    while (Height > 0)
    {
            
        printf("%3d   %5.1f    %.1f    ", Time,Height,Velocity);
        scanf("  %d",&Throttle);

        Height = Height + Velocity + (0.1 * Throttle - 1.5)/2;
        Velocity = Velocity +(0.1 * Throttle - 1.5);
        Time++;
    }
    if(Velocity < -2)
    {
        printf( "FAILED! Crach landing at %.1f m/s", Velocity);
    }
    else
    {
        printf("Congrats! you stayed alive!!!");
    }
    return 0;
}
