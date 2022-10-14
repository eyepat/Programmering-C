#include <stdio.h>
int main()
{
int a,b,c,d,s1,l1,s2,l2,largest,smallest;
printf("Enter four integers:");
scanf( "%d %d %d %d" ,&a ,&b ,&c ,&d);
if( a > b){
    s1 = b;
    l1 = a;
}
else {
    s1 = a;
    l1 = b;
}

if ( c > d){
    s2 = d;
    l2 = c;
}

else {
    s2 = c;
    l2 = d;
}

if(l1 > l2){
    largest = l1;
}
else {
    largest = l2;
}
if(s1 > s2){
    smallest = s2;
}
else{
    smallest = s1;
    
}

printf("largest: %d \n" , largest);
printf("smallest: %d \n", smallest);


    return 0;
}