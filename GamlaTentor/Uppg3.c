#include <stdio.h>
#include <string.h>
#define MAX 21


typedef struct{
char engilsk[MAX];
char svenska[MAX];
}wordPair;

void printpair(wordPair ok);

int main(){
    wordPair wordPair1 ={"cat","katt"};
    printpair(wordPair1);
    return 0;
}


void printpair(wordPair ok){
    printf("%s-%s\n",ok.engilsk,ok.svenska);
}