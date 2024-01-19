// bad example
#include<stdio.h>
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
int n;
printf("Enter n: ");
scanf("%d",&n);
printf("fibo of %d = %d", n ,fibo(n));
}