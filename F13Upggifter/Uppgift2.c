#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAX 3
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
void Replace(Car reg[], int nrOfCars){
    
    int searchThis;
    int more;
    printRegister(reg, nrOfCars);
    printf("vilken bil vill du andra mil pa? ");
    scanf("%d", &searchThis);
    printf("hur manga mil? ");
    scanf("%d",&more);
    reg[searchThis-1].milage += more;
    
}

void print_to_file(char file_name[], Car reg[], int nrOfCars)
{
    FILE *fp;
    fp = fopen(file_name, "w");

    if (fp != NULL) {
        for (int i = 0; i < nrOfCars; i++) {
            if (i == nrOfCars - 1) {
            fprintf(fp, "%s %d %d", reg[i].model, reg[i].year, reg[i].milage);
            }
            else {
            fprintf(fp, "%s %d %d\n", reg[i].model, reg[i].year, reg[i].milage);
            }
        }
    }
    fclose(fp);
}

int main(){
    
    Car carRegister[MAX];
    Car reg[MAX];
    int nrOfCars=0;
    int menu;
    int value;
    int newValue;
    do{
        printf(" (1)Registrera bilar\n (2)Skriv ut alla bilar\n (3)Oka mil\n (4)Avsluta\n");
        scanf(" %d", &menu);

        switch(menu){
            case 1:
            regCars(carRegister,&nrOfCars);
            break;
            case 2:
            printRegister(carRegister, nrOfCars);
            break;
            case 3:
            Replace(carRegister , nrOfCars);
            break;
            case 4: 
            printf("Exiting program\n");
            print_to_file("minabilar.txt", carRegister, nrOfCars);
                return 0;
            default:
                break;
        }
    }
    while(menu != 4);
    return 0;
}




