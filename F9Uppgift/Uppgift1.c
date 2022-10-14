#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

int randomNumber(int randomArray[],int userArray[]);
int main(){

    int userArray[SIZE];
    int randomArray[SIZE];
    srand(time(NULL));
    randomNumber(randomArray,userArray);
    return 0;
} 

int randomNumber(int randomArray[],int userArray[]){
    int gistCorrect = 0;
    int round = 0;
    int ratt = 0;

        for(int i = 0; i < SIZE; i++){
            randomArray[i] = rand()% 9 + 1;
            //printf("%d", randomArray[i]);
    }   

    while (gistCorrect == 0){
        int ratt = 0;   
        round++;
        printf("\nGissa kodden: ");
        scanf("%d %d %d" , &userArray[0], &userArray[1], &userArray[2]);

        for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
        if (randomArray[i] == userArray[i]){
             ratt++;
             break;
         }
     }
}
        if (ratt == 3){
        gistCorrect = 1;
        printf("\nRatt kod. Du behovde %d gissningar", round);
            break;
        }
         printf("\nfel kod, du hade %d ratt.", ratt);
    }
}