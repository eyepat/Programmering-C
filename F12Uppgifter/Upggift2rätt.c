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
void regCars(Car reg[],int *pNrOfCars){
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
void printRegister(Car reg[], int nrOfCars){
    for(int i= 0; i < nrOfCars; i++){
    printf("%d. Bil:%s, Arsmodell:%d, Mil:%d\n", i+1, reg[i].model, reg[i].year, reg[i].milage);
    }
   
}

int main(){
    Car carRegister[MAX];
    int nrOfCars=0;
    regCars(carRegister,&nrOfCars);
    printRegister(carRegister, nrOfCars);
return 0;
}