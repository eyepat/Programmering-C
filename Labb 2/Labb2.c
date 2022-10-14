#include <stdio.h>
#include <math.h>
#define SIZE 10

int enterNumber(int numbersArray[],int nrOfMeasurements);
void viewNumber(int numbersArray[],int nrOfMeasurements);
int computeNumber(int numbersArray[],int nrOfMeasurements);
int biggerNr(int numbersArray[],int nrOfMeasurements);
int smallerNr(int numbersArray[],int nrOfMeasurements);
float middleValue(int numbersArray[],int nrOfMeasurements);
void normalizValues(int numbersArray[],int nrOfMeasurements,int resultatet[]);

int main(){
    char type;
    int numbersArray[SIZE], nrOfMeasurements = 0;
    printf("Measurement tool 2.0\n");
    do{
        printf("VECRQ? ");
        scanf (" %c", &type);
        switch (type){
            case 'v':
                viewNumber(numbersArray,nrOfMeasurements);
                break;
            case 'e':
                nrOfMeasurements = enterNumber(numbersArray, nrOfMeasurements);
                break;
            case 'c':
                computeNumber(numbersArray,nrOfMeasurements);
                break;
            case 'r':
                nrOfMeasurements = 0;
                break;
            case 'q':
                printf("Exit measurement tool");
                break;

            default:
            printf("please enter only valid grades\n");
        }
    } 
        while(type != 'q');
        return 0;
} 
int enterNumber(int numbersArray[],int nrOfMeasurements){
     for(int i = nrOfMeasurements; i < SIZE; i++){
         printf("Enter measurement #%d ", i+1);
         int readInteger = scanf("%d",&numbersArray[i]); 
        if(readInteger){ 
            nrOfMeasurements++;              
        } 
        else{ 
        char tmp; 
        scanf(" %c",&tmp); 
         break;                      
        } 
    }
        return nrOfMeasurements; 
}
    
void viewNumber(int numbersArray[],int nrOfMeasurements){
            printf("[ ");
        for (int i = 0; i < nrOfMeasurements; i++){
            printf("%d ", numbersArray[i]);
        }
            printf("]\n");
}

int computeNumber(int numbersArray[],int nrOfMeasurements){
    if(nrOfMeasurements == 0){
        printf("No measurements\n");
    }
    else{
        int biggest, smallest;
        int resultatet[nrOfMeasurements];
        float mean;
        biggest = biggerNr(numbersArray,nrOfMeasurements);
        smallest = smallerNr(numbersArray,nrOfMeasurements);
        mean = middleValue(numbersArray,nrOfMeasurements);
        printf("max value: %d \n", biggest);
        printf("min value: %d \n", smallest);
        printf("avr value: %.2f \n", mean);
        normalizValues(numbersArray, nrOfMeasurements, resultatet);
        viewNumber(resultatet,nrOfMeasurements);
    }
}

int biggerNr(int numbersArray[],int nrOfMeasurements){
    int biggest = numbersArray[0];
    for(int i = 1; i< nrOfMeasurements; i++){
        if (biggest < numbersArray[i]){
            biggest = numbersArray[i]; 
        }
    }
        return biggest;
}

int smallerNr(int numbersArray[],int nrOfMeasurements){
    int smallest = numbersArray[0];
    for (int i = 1; i < nrOfMeasurements; i++){
        if (smallest > numbersArray[i]){
            smallest = numbersArray[i];
        }
    }
        return smallest;
}

float middleValue(int numbersArray[],int nrOfMeasurements){
    float resultat = 0.0;
    float mean = 0.0;
    for (int i = 0; i < nrOfMeasurements; i++){
        resultat = resultat + numbersArray[i];
        mean = resultat / nrOfMeasurements;
    }
           return mean;
}

void normalizValues(int numbersArray[],int nrOfMeasurements,int resultatet[]){
    for (int i = 0; i < nrOfMeasurements; i++){
        resultatet[i] =  numbersArray[i] - round(middleValue(numbersArray, nrOfMeasurements));
    }
       
}


     
