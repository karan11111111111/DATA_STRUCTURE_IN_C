// 1.1 Write a program to read two numbers and compare the numbers using function call by address.
// #include<stdio.h>
void compareNum(int *x, int *y){
    if(*x > *y){
        printf("%d is greater than %d \n",*x,*y);
    }else if(*y>*x){
        printf("%d is greater than %d \n",*y,*x);
    }else{
        printf("%d and %d both are equal \n",*x,*y );
    }
}
int main(){

int a , b;
printf("Enter a and b: \n");
scanf("%d%d",&a,&b);
compareNum(&a,&b);
    
}