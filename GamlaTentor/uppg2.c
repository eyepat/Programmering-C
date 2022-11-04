#include <stdio.h>
#include <string.h>
#define MAX 10
#define WORDSIZE 31


int EnterWords(char words[][WORDSIZE],int nrOfWords);
void view(char words[][WORDSIZE],int nrOfWords);
int delete(char words[][WORDSIZE],int nrOfWords);

int main(){
    char menu; 
    char control = 'q';
    char words[MAX][WORDSIZE];
    int nrOfWords = 0;
    do{
        printf("a) lagga till, b) skriva ut, c) ta bort, d) avsluta: ");
        scanf(" %c", &menu);
        switch(menu){
            case 'a':
              nrOfWords = EnterWords(words,nrOfWords);
                break;
            case 'b':
                view(words,nrOfWords);
                break;
            case 'c':
               nrOfWords = delete(words, nrOfWords);
                break;
            case 'd':
             printf("avsluta");
                break;
           default:printf("Felaktigt val\n");
            break;
        }
    }
    while(menu != 'd');
    return 0;
}

int EnterWords(char words[][WORDSIZE],int nrOfWords){
    char control[WORDSIZE];
    for(int i = nrOfWords; i < MAX; i++){
        printf("ange ord (q for avslut):");
          scanf("%s", control);
        if(strcmp(control,"q")== 0){
            break;
            }
            else{
               strcpy(words[i],control);
               nrOfWords++;
            }
    }
        return nrOfWords; 
}

void view(char words[][WORDSIZE],int nrOfWords){
    for(int i = 0; i < nrOfWords; i++){
        printf("%s, ",words[i]);
    }
        printf("\n");
}
int delete(char words[][WORDSIZE],int nrOfWords){
    char searching[WORDSIZE];
    for(int i = 0; i < nrOfWords; i++){
        printf("Ange ord att radera (q for avslut):");
        scanf("%s", searching);
        if(strcmp(searching,words[i])==0){
           for(int j = i; j < nrOfWords; j++){
               strcpy(words[j],words[i+1]);  
            }
            nrOfWords--;
            break;
        }
    }
    return nrOfWords;
}
