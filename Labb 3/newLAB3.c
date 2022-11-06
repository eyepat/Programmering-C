#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 21
#define MAX 100
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

void printToFile(char fileName[], Varor reg[], int NrOfVaror);
void readFromFile(char fileName[], Varor reg[], int *NrOfVaror);
char regVaror(Varor reg[MAX],int NrOfVaror);
void printRegister(Varor reg[], int NrOfVaror);
char search(Varor reg[], int NrOfVaror);
char searchName(Varor reg[], int NrOfVaror);
int searchVaroNumber(Varor reg[], int NrOfVaror);
int searchStockBalance(Varor reg[], int NrOfVaror);
void Replace(Varor reg[], int NrOfVaror);
int Sortera(Varor reg[], int NrOfVaror);
void SorteraVNr(Varor reg[], int NrOfVaror);
void SorteraVSaldo(Varor reg[], int NrOfVaror);
void SorteraVName(Varor reg[], int NrOfVaror);
int DeleteVaror(Varor reg[], int NrOfVaror);

int main(){
    Varor reg[MAX];
    int menu;
    int NrOfVaror = 0;
    char fileName[FILENAME_MAX];

    printf("Vad heter filen du vill anvanda dig av? ");
    scanf("%s", fileName);
    readFromFile(fileName, reg, &NrOfVaror);
    
    do{
        printf("1)Registrera nya varor\n2)Skriva ut alla varor\n3)Soka efter varor\n4)Andra lagersaldot for varor\n5)Sortera varor\n6)Avregistrera varor\n0)Avsluta programmet\n ");
        printf("Ange(1-6)0)Avsluta: ");
        scanf(" %d", &menu);
        switch(menu){
            case 1:
            NrOfVaror = regVaror(reg, NrOfVaror);
            break;
            case 2:
            printRegister(reg, NrOfVaror);
            break;
            case 3:
            search(reg,NrOfVaror);
            break;
            case 4:
            Replace(reg,NrOfVaror);
            break;
            case 5:
            Sortera(reg, NrOfVaror);
            break;
            case 6:
            DeleteVaror(reg,NrOfVaror);
            break;
            case 0:
            printf("Exiting program\n");
            printToFile(fileName, reg, NrOfVaror);
                return 0;
            default:
                break;
 
        }
    }
    while(menu != 7);
    return 0;
 }      
 

char regVaror(Varor reg[MAX],int NrOfVaror){
    int check;
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance;
    do{
        check = 0;
        printf("Ange varunummer (0 for avslut):");
        scanf("%d",&itemNumber);
       
        if(itemNumber == 0){
            break;
            }
            for(int i = 0; i < NrOfVaror; i++){
                if(itemNumber == reg[i].itemNumber){
                    printf("Ej unikt varunummer!\n");
                    check=1;
                }
            }
            if(check!=1){
                printf("Ange namn:");
                scanf("%s%*c",&itemName);
                printf("Ange saldo:");
                scanf("%d%*c",&stockBalance);
                reg[NrOfVaror]= createVaror(itemNumber,itemName,stockBalance);
                (NrOfVaror)++;
            }
            if(NrOfVaror == MAX){
                break;
            }
        } while (NrOfVaror != 0);  
            return NrOfVaror;
    }

void printRegister(Varor reg[], int NrOfVaror){
    printf("Varunummer           Namn                  Lagersaldo     \n");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < NrOfVaror; i++){
        printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
        }
}


char search(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance;
    char chakeName[MAX];
    int menuSearch;
    int chakeNr;
    int chakeStock;
    int resultatet[NrOfVaror];
    
    do{
        printf("1)Sok for VaroNumber\n2)Sok for VaroName\n3)Sok efter VarorSaldo \n0)for avslut ");
         scanf(" %d", &menuSearch);
        switch(menuSearch){
            case 1:
            chakeNr = searchVaroNumber(reg, NrOfVaror);
            break;
            case 2:
            searchName(reg, NrOfVaror);
            break;
            case 3:
            chakeStock = searchStockBalance(reg,NrOfVaror);
            break;
            case 0:
            break;
        }
    }while(menuSearch != 0);
 
    
}
char searchName(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance;
    char chakeName[MAX];
    int oneTime = 0;
    while(NrOfVaror <= MAX){
       char *save;
        printf("enter what word you wanna search (0 for avslut) ");
        scanf("%s",chakeName);
       
        for (int i = 0; i < NrOfVaror; i++){
           save = strstr(reg[i].itemName,chakeName);
           if (save != NULL){
           
            printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }
            
        }
       
    }
}
    
int searchVaroNumber(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int resultatet[MAX];
    int itemNumber, stockBalance, chakeNr = 0, oneTime = 0;
    
    while(NrOfVaror <= MAX){
        printf("enter what Varonumber you wanna search (0 for avslut) ");
        scanf("%d",&chakeNr);
        if(chakeNr == 0){
            break;
        } 
        for (int i = 0; i != NrOfVaror; i++){
           if(chakeNr == reg[i].itemNumber){
            if(oneTime == 0){
                printf("Varunummer           Namn                  Lagersaldo     \n");
                printf("----------------------------------------------------------\n");
                oneTime = 1;
            }
            printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }  
        }     
    }    
}
    


int searchStockBalance(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance, chakeStock = 0, oneTime = 0;
    while(NrOfVaror <= MAX){
        printf("enter what Varonumber you wanna search (0 for avslut) ");
        scanf("%d",&chakeStock);
        if(chakeStock == 0){
            break;
        } 
        for (int i = 0; i != NrOfVaror; i++){
           if(chakeStock == reg[i].stockBalance){
            if(oneTime == 0){
                printf("Varunummer           Namn                  Lagersaldo     \n");
                printf("----------------------------------------------------------\n");
                oneTime = 1;
            }
            printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }  
              
        }
    }
}


void Replace(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int chackk = 0;
    int searchThis = 0;
    int more;
    int itemNumber, stockBalance;
    do{
        printRegister(reg, NrOfVaror);
        printf("vilken vara vill du andra saldo pa?(0) to exit ");
        scanf("%03d", &searchThis);
        if(searchThis == 0){
            break;
            }
        for (int i = 0; i != NrOfVaror; i++){
            if(searchThis == reg[i].itemNumber){
                printf("Varunummer           Namn                  Lagersaldo     \n");
                printf("----------------------------------------------------------\n");
                printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
                printf("hur manga? ");
                scanf("%d",&more);
                reg[i].stockBalance += more;
            }  
            if(reg[i].stockBalance < 0){
                printf("for inte anvanda minus siffra\n");
                printf("_________________________________________________\n");
                reg[i].stockBalance = 0;
                //chackk = 1;
            }
           /* if(chackk != 1){
             printf("Varor not found\n ");
                printf("_________________________________________________\n");
            }*/
        }
    }while(NrOfVaror != 0); 
 }
            
int Sortera(Varor reg[], int NrOfVaror){
    int itemNumber;
    Varor temp;
    int menuSortera;
    int kontrol;
    do{
        kontrol = 0;
        printf("1)Sortera po VaroNumber\n2)Sortera po VaroName\n3)Sortera po VarorSaldo \n0)for avslut ");
        scanf(" %d", &menuSortera);
        switch(menuSortera){
            case 1:
            SorteraVNr(reg,NrOfVaror);
            kontrol = 1;
            break;
            case 2:
            SorteraVName(reg,NrOfVaror);
            kontrol = 1;
            break;
            case 3:
            SorteraVSaldo(reg,NrOfVaror);
            kontrol = 1;
            break;
            case 0:
            break;
        }
    }while(kontrol != 1);
} 
      
void SorteraVNr(Varor reg[], int NrOfVaror){
    int itemNumber;
    Varor temp;
    for (int i = 0; i < NrOfVaror; i++) {     
        for (int j = i+1; j < NrOfVaror; j++) {     
           if(reg[i].itemNumber > reg[j].itemNumber){    
               temp = reg[i];    
               reg[i] = reg[j];    
               reg[j]= temp;  
            }  
        }
    }
    printf("________________________\n");
    printf("Sortera succeed\n");
    printf("------------------------\n");
}
void SorteraVSaldo(Varor reg[], int NrOfVaror){
    int itemNumber;
    Varor temp;
    for (int i = 0; i < NrOfVaror; i++) {     
        for (int j = i+1; j < NrOfVaror; j++) {     
           if(reg[i].stockBalance > reg[j].stockBalance){    
               temp = reg[i];    
               reg[i] = reg[j];    
               reg[j]= temp;  
            }  
        }
    }
    printf("________________________\n");
    printf("Sortera succeed\n");
    printf("------------------------\n");
}

void SorteraVName(Varor reg[], int NrOfVaror){
    int itemNumber;
    Varor temp;
    for (int i = 0; i < NrOfVaror; i++){     
        for (int j = i+1; j < NrOfVaror; j++) {     
           if(strcmp(reg[i].itemName ,reg[j].itemName) > 0){    
               temp = reg[i];    
               reg[i] = reg[j];    
               reg[j]= temp; 
            }
        }
    }
    printf("________________________\n");
    printf("Sortera succeed\n");
    printf("------------------------\n");
}

int DeleteVaror(Varor reg[], int NrOfVaror){
    char itemName[WORDLENGTH];
    int resultatet[MAX];
    int itemNumber, stockBalance, chakeNr = 0, oneTime = 0;
    int pos;
        searchVaroNumber(reg,NrOfVaror);
    

    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &pos);
    for ( int i = pos - 1; i < NrOfVaror - 1 ; i++ ) 
        reg[i] = reg[i+1];        
        
        printf("Resultant array is\n");
        
        for(int i = 0 ; i < NrOfVaror - 1 ; i++ )        
        printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);   
        return 0;     
    }    
    
    /*printf( " Define the position of the array element where you want to delete: \n ");  
    scanf (" %d", &pos);  
     for (int i = pos - 1; i < NrOfVaror -1; i++)  
        {  
            reg[i] = reg[i-1]; // assign arr[i+1] to arr[i]  
            
        }  
          
        printf("Varunummer           Namn                  Lagersaldo     \n");
        printf("----------------------------------------------------------\n");
          
        // display the final array  
        for (int i = 0; i< NrOfVaror - 1; i++)  
        {  
          printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
        }  */
       
void printToFile(char fileName[], Varor reg[], int NrOfVaror){
    FILE *fp;
    fp = fopen(fileName, "w");

    if (fp != NULL) {
        for (int i = 0; i < NrOfVaror; i++) {
            if (i == NrOfVaror - 1) {
            fprintf(fp, "%d %s %d", reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }
            else {
            fprintf(fp, "%d %s %d\n", reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }
        }
    }
    fclose(fp);
}

void readFromFile(char fileName[], Varor reg[], int *NrOfVaror){
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance;

    FILE *fp;
    fp = fopen(fileName, "r");
    
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %d", &itemNumber, itemName, &stockBalance) == 3){
            reg[*NrOfVaror] = createVaror(itemNumber,itemName,stockBalance);           
            (*NrOfVaror)++;
        }
        fclose(fp);
    }
}








