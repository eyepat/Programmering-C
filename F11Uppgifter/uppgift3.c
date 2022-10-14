#include <stdio.h>

int arrayLength(char myArray[], int i);

int main() {
    char myArray[] = "Sommar";
    int length;

    length =arrayLength(myArray, length);

    printf("%d\n", length);

    return 0;
}

int arrayLength(char myArray[], int i){
    for (i = 0; myArray[i] != '\0'; i++);
    return i;
}