#include <stdio.h>
#include <string.h>
#define MAX 21



char enterChar(char charArray[][MAX],char charArray2[][MAX],int nrOfMeasurements);
char viewChar(char charArray[][MAX],char charArray2[][MAX],int nrOfMeasurements);


int main(){

char charArray[MAX][MAX];
char charArray2[MAX][MAX];
int menu;
int nrOfMeasurements = 0;   
do{
    printf("(1) Skriva in (2) Skriva ut (3) Radera (4)Avsluta: ");
    scanf (" %d", &menu);
switch (menu){
        case 1:
        nrOfMeasurements =  enterChar(charArray,charArray2, nrOfMeasurements);
        break;
        case 2:
         viewChar(charArray,charArray2,nrOfMeasurements);
        break;
        case 3:
          nrOfMeasurements = 0;
        break;
        case 4:
        printf("Avslutar");
        break;
    }
   } 
        while(menu != 4);
        return 0;
    } 
    
char enterChar(char charArray[][MAX],char charArray2[][MAX],int nrOfMeasurements){
   char words[MAX];
   char exit[2] = {"q"};
   
   for(int i = nrOfMeasurements; i < MAX; i++){
        printf("svenska: ");
         scanf("%s",words);
          if(strcmp(words,exit) == 0){
            break;
         } 
        strcpy(charArray[i], words);
        printf("Engelska: ");
        scanf("%s",words);
         if(strcmp(words,exit) == 0){
            break;
         } 
        strcpy(charArray2[i], words);
     nrOfMeasurements++;
    }
       return nrOfMeasurements; 
} 

char viewChar(char charArray[][MAX],char charArray2[][MAX],int nrOfMeasurements){
       
      if(nrOfMeasurements == 0){
        printf("Gloslistan ar tom\n");
      }
      else{
       for(int i = 0; i < nrOfMeasurements; i++){
        
         printf("%s - %s\n", charArray[i],charArray2[i]);
       }
      }
}



