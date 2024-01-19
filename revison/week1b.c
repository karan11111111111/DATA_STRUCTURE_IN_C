// 1.2 Write a program to create an array of n elements using dynamic memory allocation. 
// Calculate sum of all the prime elements of the array using function and de-allocate the memory 
// of the array after its use.

#include<stdio.h>
int calcPrime(int n){
    int i, sum=0;
    if(i<2){
        return 0;
    }
    for( i =2; i<=n; i++){
        if(n%i == 1){
       sum = sum + i;
        }
    }
    printf("sum = %d", sum);
}
int main(){
int n;
printf("enter n : ");
scanf("%d",&n);
calcPrime(n);

}