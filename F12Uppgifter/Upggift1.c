#include <stdio.h>
#include <string.h>


struct bankaccount{
    char ownerName[30];
    int funds;
 } account1, account2;

char createAccount(char ownerName[30],int funds);
char printAccount(char ownerName[30],int funds);
int transfer(int *first, int *second);
int main(){

    struct bankaccount;
    char ownerName[30];
    int funds;
    createAccount(ownerName,funds);
    printAccount(ownerName, funds);
    return 0;
}

char createAccount(char ownerName[30],int funds){

    strcpy(account1.ownerName,"Simran Singh");
    account1.funds = 3210;

    strcpy(account2.ownerName,"Mark Asplund");
    account2.funds = 210;
  
}
char printAccount(char ownerName[30],int funds){

    printf("%s %d kr\n", account1.ownerName, account1.funds);
    printf("%s %d kr\n", account2.ownerName, account2.funds);
    transfer(&account2.funds, &account1.funds);
    printf("%s %d kr\n",account1.ownerName, account2.funds);
    printf("%s %d kr\n",account2.ownerName, account1.funds);

}

int transfer(int *first, int *second){
    int totalt = *first;
    *first = 0;
    *second = *second + totalt;
}
