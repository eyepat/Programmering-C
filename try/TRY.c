#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

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
        for(int i = 0; i < n; i++){

            randomArray[i] = rand()% n;
            randomArray[i] <= n;
            printf("%d,", randomArray[i]);
    }
   
    return 0;
    }
   
    
    
