// bad example
#include<stdio.h>
int F[51];
int fibo(int n){
    if(n<=1){
        return n;
    }
    if(F[n] != -1){
        return F[n];
    }
     F[n] = fibo(n-1)+fibo(n-2);
     return F[n];
}
int main(){
    for(int i=0; i<51; i++){
        F[i] = -1;
    }
    F[0] = 0; F[1]=1;
int n;
printf("Enter n: ");
scanf("%d",&n);
printf("fibo of %d = %d", n ,fibo(n));
}