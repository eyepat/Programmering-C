#include <stdio.h>

char addWords();
char view();
void clear();

int main(){

    char menu;
    do{
        printf("a) lagga till, b) skriva ut, c) ta bort, d) avsluta:");
        scanf("%c", &menu);
        switch (menu){
            case 'a':
            addWords();
            break;
            case 'b':
            view();
            break;
            case 'c':
            clear();
            case 'd':
            printf("avsluta");
            break;
        }
    }
    while(menu != 'd');
    return 0;
}