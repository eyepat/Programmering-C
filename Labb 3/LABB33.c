#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 21
#define MAX 3
typedef struct {
    char itemName[WORDLENGTH];
    int itemNumber; 
    int stockBalance;
} Varor;

Varor createVaror(int itemNumber,char itemName[],int stockBalance){
    Varor a;
    strcpy(a.itemName,itemName);
    a.itemNumber = itemNumber;
    a.stockBalance = stockBalance;
    return a;
}


char regVaror(Varor reg[MAX],int *pNrOfVaror);
int printRegister(Varor reg[], int NrOfVaror);




int main(){
    Varor varRegister[MAX];
    Varor reg[MAX];
    int menu;
    int NrOfVaror = 0;
    do{
        printf("1)Registrera nya varor\n2)Skriva ut alla varor\n3)Soka efter varor\n4)Andra lagersaldot for varor\n5)Sortera varor\n6)Avregistrera varor\n7)Avsluta programmet ");
        scanf(" %d", &menu);
        switch(menu){
            case 1:
             regVaror(varRegister, &NrOfVaror);
            break;
            case 2:
             printRegister(varRegister, NrOfVaror);
            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
            
            break;
            case 6:

            break;
            case 7:
            printf("Exiting program\n");
           
                return 0;
            default:
                break;
        }
    }
    while(menu != 7);
    return 0;
 }      
 

char regVaror(Varor reg[],int *pNrOfVaror){
    char itemName[WORDLENGTH];
    int itemNumber,stockBalance;
    int check=0;
        
    do{
        printf("Ange varunummer (0 for avslut):");
        scanf("%d",&itemNumber);
        if(itemNumber == 0){
            break;
        }
        for(int i = 0; i<=(*pNrOfVaror); i++){
            if(itemNumber == reg[i].itemNumber){
                printf("Ej unikt varunummer!\n");
                regVaror(reg, &*pNrOfVaror);
                check=1;
            }
        }
        if(check!=1){
            printf("Ange namn:");
            scanf("%s%*c",itemName);
            printf("Ange saldo:");
            scanf("%d%*c",&stockBalance);
            reg[*pNrOfVaror]= createVaror(itemNumber,itemName,stockBalance);
            (*pNrOfVaror)++;
        }
        
    } while (itemNumber != 0);  

}


int printRegister(Varor reg[], int NrOfVaror){
    printf("Varunummer           Namn                  Lagersaldo     \n");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < NrOfVaror; i++){
    printf(" %-14d    %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
    }
}









