// 1.1 Write a program to read two numbers and compare the numbers using function call by 
// address.

#include<stdio.h>

int compair(int *a, int *b){
   if(*a>*b){
    printf("%d > %d",*a,*b);
    }
    else if(*a<*b){
        printf("%d < %d",*a,*b);
    }else{
        printf("%d = %d",*a,*b);
    }

}

int main(){
    int a, b;
    printf("enter a, b");

    scanf("%d%d",&a,&b);

    compair(&a,&b);
   return 0;

}