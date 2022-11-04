#include <stdio.h>
#include <string.h>
#define MAX 10

int Choose(int vikt[MAX],int nrOfKg);
void view(int vikt[MAX],int nrOfKg);
int main(){
   int vikt[MAX];
   int nrOfKg;
    Choose(vikt,nrOfKg);
    view(vikt,nrOfKg);


    return 0;
}
int Choose(int vikt[MAX],int nrOfKg){
    int santKg;
    do{
        printf("Ange ladstorlek (1-10kg):");
        scanf("%d",&nrOfKg); 
        if(nrOfKg < 1 || nrOfKg > 10){
            printf("Felaktig inmatning\n");
        }
    }
    while(nrOfKg < 1 || nrOfKg > 10);
    do{
        printf("Ange vara (1-%dkg) eller 0 for att avsluta:",nrOfKg);
        scanf("%d",&santKg);
        if(santKg < 1 || santKg > nrOfKg){
            printf("Felaktig inmatning\n");
           }
        else if(santKg != 0){
            vikt[nrOfKg]=santKg;
            (nrOfKg)++;
    
       }
        while(santKg != 0 && nrOfKg > MAX);
    }
      
void view(int vikt[MAX],int nrOfKg){
    for(int i = 0; i < nrOfKg; i++){
        printf("%d", vikt[i]);
    }
    printf("\n");
}
        
    
