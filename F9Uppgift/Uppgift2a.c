#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

int random(int randomArray[],int n);
void view(int randomArray[],int n);

int main(){
int randomArray[SIZE];
int n = SIZE;
    srand(time(NULL));
    do{
    printf("Vilket ar det hogsta heltal du vill ha med (1-10000): ");
    scanf("%d", &n);

    if ( n > 10000 || n < 1){
        printf("Du maste valja mellan 1 och 10000!\n");
    }  
    }
    while(n > 10000 || n < 1);

    random(randomArray,n);

    view(randomArray,n);
        /*for(int i = 0; i < n; i++){

            randomArray[i] = rand()% n + 1;
            printf("%d,", randomArray[i]);
    }*/
   
    return 0;
    }

    void view(int randomArray[],int n){
        for (int i = 0; i < n; i++){
            printf("%d,",randomArray[i]);
        }
    }
   
    int random(int randomArray[],int n){
        int seenNumber;
        int randomNum;
         for(int i = 0; i < n; i++){
            randomNum = rand()% n + 1;
            for(int j = 0; j < n; j++){
            if(randomArray[j] == randomNum){
                seenNumber = 1;
                i--;
            }
            if(!seenNumber){
                randomArray[i] = randomNum;
            }
            }
         } 
    }




    
    
