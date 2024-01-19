// good example
#include<stdio.h>

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n* factorial(n-1);
    
    
}

int main(){
int n;

printf("Enter N: ");
scanf("%d",&n);

printf("%d",factorial(n));
}