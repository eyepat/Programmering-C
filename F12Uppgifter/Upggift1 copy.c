#include <stdio.h>
#include <string.h>
define MAX = 20

void regCars(Car reg[], int *pNrOfCars);
void printRegister(Car reg[], int *pNrOfCars);
int main(){
Car carRegister[MAX];
int nrOfCars=0;
regCars(carRegister,&nrOfCars);
printCar(carRegister[0]); 
return 0;
}

void regCars(Car reg[], int *pNrOfCars)
{
    char again[WORDLENGTH] = "ja", model[WORDLENGTH];
    int year, milage;
    while (strcmp(again, "ja") == 0)
    { 
        printf("Ange model:");
        scanf("%s%*c", model);
        printf("Ange year:");
        scanf("%d%*c", &year);
        printf("Ange milage:");
        scanf("%d%*c", &milage);
        reg[*pNrOfCars] = createCar(model, year, milage);
        (*pNrOfCars)++;
        printf("Vill du fortsatta? (ja/nej)");
        scanf("%s%*c", again);
    }
}
void printRegister(Car reg[], int *pNrOfCars)
{
    for (int i = 0; i < *pNrOfCars; i++)
    {
        printf("%d. Bil: %s, Arsmodell: %d, Mil: %d\n", i+1, reg[i].model, reg[i].year, reg[i].milage);
    }
}

int main(){
Car carRegister[MAX];
int nrOfCars=0;
regCars(carRegister,&nrOfCars);
printCar(carRegister[0]); 
return 0;
}