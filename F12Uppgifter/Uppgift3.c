#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAX 100
struct car{
    char model[WORDLENGTH];
    int year;
    int milage;
};
typedef struct car Car;

    Car createCar(char model[],int year, int milage){
    Car c;
    strcpy(c.model,model);
    c.year=year;
    c.milage=milage;
    return c;
}

char regCars(Car reg[],int *pNrOfCars){
    char again[WORDLENGTH] = "ja", model[WORDLENGTH];
    int year,milage;
while(strcmp(again,"ja")==0){ 
    printf("Ange model:");
    scanf("%s%*c",model);
    printf("Ange year:");
    scanf("%d%*c",&year);
    printf("Ange milage:");
    scanf("%d%*c",&milage);
    reg[*pNrOfCars]=createCar(model,year,milage);
    (*pNrOfCars)++;
    printf("Vill du fortsatta? (ja/nej)");
    scanf("%s%*c",again);
    }
}

int printRegister(Car reg[], int nrOfCars){
    for(int i= 0; i < nrOfCars; i++){
    printf("%d. Bil:%s, Arsmodell:%d, Mil:%d\n", i+1, reg[i].model, reg[i].year, reg[i].milage);
    }
}

int main(){
    
    Car carRegister[MAX];
    Car reg[MAX];
    int nrOfCars=0;
    int menu;
    do{
        printf(" (1)Registrera bilar\n (2)Skriv ut alla bilar\n (3)Avsluta\n");
        scanf(" %d", &menu);

    switch(menu){
        case 1:
         regCars(carRegister,&nrOfCars);
        break;
        case 2:
        printRegister(carRegister, nrOfCars);
        break;
        case 3: 
        nrOfCars = 0;
      
        break;
        }
    }
    while(menu != 3);
    return 0;
}


