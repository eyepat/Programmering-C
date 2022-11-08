#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define WORDLENGTH 21
#define MAX 100
typedef struct{
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

void printToFile(char fileName[], Varor reg[], int NrOfVaror);                  //klart
void readFromFile(char fileName[], Varor reg[], int *NrOfVaror);                //klart
char regVaror(Varor reg[MAX],int NrOfVaror);                                    //klart
void printRegister(Varor reg[], int NrOfVaror);                                 //klart
char search(Varor reg[], int NrOfVaror,int *goBack);                                        //klart
char searchName(Varor reg[], int NrOfVaror);                                    //klart
int searchVaroNumber(Varor reg[], int NrOfVaror,int *goBack);                               //klart
int searchStockBalance(Varor reg[], int NrOfVaror);                             //klart
void Replace(Varor reg[], int NrOfVaror,int *goBack);                                       //klart 
int Sortera(Varor reg[], int NrOfVaror);                                        //klart    
void SorteraVNr(Varor reg[], int NrOfVaror);                                    //klart
void SorteraVSaldo(Varor reg[], int NrOfVaror);                                 //klart
void SorteraVName(Varor reg[], int NrOfVaror);                                  //klart
int DeleteVaror(Varor reg[], int NrOfVaror,int *goBack);                                    //klart

int main(){
    Varor reg[MAX];
    int menu ,goBack ,NrOfVaror = 0;
    char fileName[WORDLENGTH];
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
            search(reg,NrOfVaror,&goBack);
            break;
            case 4:
            Replace(reg,NrOfVaror,&goBack);
            break;
            case 5:
            Sortera(reg, NrOfVaror);
            break;
            case 6:
            NrOfVaror = DeleteVaror(reg,NrOfVaror,&goBack);
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
 
char regVaror(Varor reg[MAX],int NrOfVaror){                                      //klart
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
                printf("Not enough space\n");
                break;
            }
            
        } while (NrOfVaror != 0);  
            return NrOfVaror;
}

void printRegister(Varor reg[], int NrOfVaror){                                             //klart
    printf("Varunummer           Namn                  Lagersaldo     \n");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < NrOfVaror; i++){
        printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
    }
}

char search(Varor reg[], int NrOfVaror, int *goBack){                                               //klart
    char itemName[WORDLENGTH];
    int itemNumber,stockBalance,menuSearch,chakeNr,chakeStock;
    char chakeName[MAX];
    
    do{
        printf("1)Sok for VaroNumber\n2)Sok for VaroName\n3)Sok efter VarorSaldo \n0)for avslut ");
         scanf(" %d", &menuSearch);
        switch(menuSearch){
            case 1:
            chakeNr = searchVaroNumber(reg, NrOfVaror,goBack);
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
    int itemNumber, stockBalance,oneTime = 0 ,check;
    char chakeName[MAX];
   
    while(NrOfVaror <= MAX){
        check = 0;
       char *save;
        printf("enter what word you wanna search (0 for avslut) ");    //klart
        scanf("%s",chakeName);
       if(chakeName[0] == '0' && chakeName[1] == '\0'){
        break;
       }
        for (int i = 0; i < NrOfVaror; i++){
           save = strstr(reg[i].itemName,chakeName);
           if (save != NULL){
            printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }
            else{
                check++;
            } 
        }
            if(check == NrOfVaror){
                printf("Not found, Try again\n");
            }
    }
}
    
int searchVaroNumber(Varor reg[], int NrOfVaror,int *goBack){                                //klart
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance, chakeNr = 0, oneTime = 0,check1,check2;
    
    while(1){
        check2= 0;
        printf("enter what Varonumber you wanna search (0 for avslut) ");
        scanf("%d",&chakeNr);
        if(chakeNr == 0){
            return 1;
        } 
        for (int i = 0; i < NrOfVaror; i++){
           if(chakeNr == reg[i].itemNumber){
            *goBack = i;
            if(oneTime == 0){
                printf("Varunummer           Namn                  Lagersaldo     \n");
                printf("----------------------------------------------------------\n");
                oneTime = 1;
            }
            printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            return 0; 
            } 
            else{
                check2++;
            } 
        } 
        if(check2 == NrOfVaror){
                printf("Not found, Try again\n");
            }
    }  
     
}
    


int searchStockBalance(Varor reg[], int NrOfVaror){                                    //klart
    char itemName[WORDLENGTH];
    int itemNumber, stockBalance, chakeStock = 0, oneTime = 0,check2;
    while(NrOfVaror <= MAX){
        check2 = 0;
        printf("enter what Saldonumber you wanna search (0 for avslut) ");
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
            else{
                check2++;
            } 
              
        }
        if(check2 == NrOfVaror){
                printf("Not found, Try again\n");
            }
    }
}


void Replace(Varor reg[], int NrOfVaror, int *goBack){    
    char itemName[WORDLENGTH];
   
    int searchThis = 0;
    int more;
    int itemNumber, stockBalance, ControlSearch = 0, control1,ValueSearch;
    do{
        if(ControlSearch == 0){
    ValueSearch = search(reg,NrOfVaror,goBack);
        ControlSearch = 1;
        }
        if(ControlSearch ==1){
        printf("vilken vara vill du andra saldo pa?(0) to exit ");
        scanf("%03d", &searchThis);
        }
        if(searchThis == 0){
            break;
            }

        for (int i = 0; i != NrOfVaror; i++){
            if(searchThis == reg[i].itemNumber){
                printf("Varunummer           Namn                  Lagersaldo     \n");
                printf("----------------------------------------------------------\n");
                printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);

                printf("how much? ");
                scanf("%d",&more);
                reg[i].stockBalance += more; 
                printf("Edit sucseed!\n");
                if(control1 == 0){
                    printf("Varunummer           Namn                  Lagersaldo     \n");
                    printf("----------------------------------------------------------\n");
                    printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);     
                    control1 = 1;
                }                               
            } 
            if(reg[i].stockBalance < 0){
                printf("\nfor inte anvanda minus siffra\n");
                reg[i].stockBalance = 0;
                printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);
            }
            
           
        }
    }while(NrOfVaror != 0); 
 }
            
int Sortera(Varor reg[], int NrOfVaror){                                            //klart
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
      
void SorteraVNr(Varor reg[], int NrOfVaror){                                          //klart
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
void SorteraVSaldo(Varor reg[], int NrOfVaror){                                               //klart
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

void SorteraVName(Varor reg[], int NrOfVaror){                                                    //klart
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

int DeleteVaror(Varor reg[], int NrOfVaror,int *goBack){ 
    char itemName[WORDLENGTH];
    int resultatet[MAX];
    int itemNumber ,stockBalance ,deleteThis, check;        
    
    search(reg,NrOfVaror,goBack);
        
    do{
        check = 0;
       
        printf("what u wanna delete");
        scanf("%d",&deleteThis);
        for (int i = 0; i < NrOfVaror; i++){
            if (deleteThis == reg[i].itemNumber){
                deleteThis = i;
                check = 1;
            }
        }
        if(check == 0){
            printf("Not found! try again\n");
        }
        if (check == 1)
        {
            for (int i = deleteThis; i < NrOfVaror; i++){
                reg[i] = reg[i+1];        
                }
                NrOfVaror--;
                printf("Delete sucssed!\n");
            
            for(int i = 0 ; i < NrOfVaror; i++){       
                printf(" %03d                %-25s    %-14d\n",reg[i].itemNumber, reg[i].itemName, reg[i].stockBalance);  
            }
            return NrOfVaror;       
        }
    }while(NrOfVaror != 0);
    
}    

           
void printToFile(char fileName[], Varor reg[], int NrOfVaror){                 //klart
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

void readFromFile(char fileName[], Varor reg[], int *NrOfVaror){                       //klart
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







