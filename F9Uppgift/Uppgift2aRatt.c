#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSize();
void view(int size, int randomArray[]);
void randomget(int size, int randomArray[]);

int main()
{
    int size;
    srand(time(0));
    size = getSize();
    int randomArray[size];
    randomget(size, randomArray);
    view(size, randomArray);
}

int getSize()
{
    int size = 0;
    while (size > 10000  || size < 1)
    {
        printf("Vilket ar det hogsta heltal du vill ha med (1-10000): ");
        scanf("%d", &size);

        if (size > 10000 || size < 1)
        {
            printf("Du maste valja mellan 1 och 10000! \n");
        }
    }
    return size;
}

void view(int size, int randomArray[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", randomArray[i]);
    }
}

void randomget(int size, int randomArray[])
{
    int seenNumbers;
    int randomNum;

    for (int i = 0; i < size; i++)
    {
        seenNumbers = 0;
        randomNum = rand() % size + 1;

        for (int j = 0; j < size; j++) 
        {
            if (randomArray[j] == randomNum) 
            {
                seenNumbers = 1;
                i--;
            }
        }
        if(!seenNumbers)
        {
            randomArray[i] = randomNum;
        }
    }
}

