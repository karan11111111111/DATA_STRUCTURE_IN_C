//3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.
#include<stdio.h>
int main(){

    int row3073, column3073, nonZero3073;

printf("Enter sparse matrix in 3-tuple format (rows, column and non zeros: ");

scanf("%d%d%d",&row3073,&column3073,&nonZero3073);


int origin_matrix[nonZero3073 +1][3];
int transpose_matrix[nonZero3073 +1][3];

//orginal matrix

origin_matrix[0][0]=row3073;
origin_matrix[0][1]=column3073;
origin_matrix[0][2]=nonZero3073;

for(int i=1; i<=nonZero3073; i++){
scanf("%d%d%d", &origin_matrix[i][0], &origin_matrix[i][1], &origin_matrix[i][2]);
} 

//transpose matirx

transpose_matrix[0][0]=column3073;
transpose_matrix[0][1]=row3073;
transpose_matrix[0][2]=nonZero3073;


//transpose logic

for(int i=1; i<=nonZero3073; i++){
    transpose_matrix[i][0]=origin_matrix[i][1];
    transpose_matrix[i][1]=origin_matrix[i][0];
    transpose_matrix[i][2]=origin_matrix[i][2];

}

 printf("Transpose of sparse matrix:\n");
    printf("R\t\tC\t\tElement\n");

    for (int i = 0; i <= nonZero3073; i++) {
        printf("%d\t\t%d\t\t%d\n", transpose_matrix[i][0], transpose_matrix[i][1], transpose_matrix[i][2]);
    }

    return 0;


}