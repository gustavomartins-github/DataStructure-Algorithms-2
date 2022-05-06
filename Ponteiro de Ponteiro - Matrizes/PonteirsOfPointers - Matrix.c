#include <stdio.h>
#include <stdlib.h>

/* 
This functin alocates memory for a matrix in the heap. 
This tye of matrix is dynamic and more slow than the static one.
*/
void createDinamicIntMatrix(int ***matrix, int rows, int columns) {
    int **m;
    m = (int **)malloc(sizeof(int *) * rows); // number of rows and 8 = number of bytes per row
    for (int i = 0; i < rows; i++) {
        m[i] =(int*) malloc(sizeof(int) * columns); // number of columns and 4 = number of bytes per column 
    }
    *matrix = m;
}

// this function prints the matrix
void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main (void){
    /* 
    This code bellow alocates memory for the matrix in the stack. 
    This type of matrix is static and more fast
    */
    int staticMatrix[2][2];
    staticMatrix[0][0] = 1;
    staticMatrix[0][1] = 2;
    staticMatrix[1][0] = 3;
    staticMatrix[1][1] = 4;
    printf("Static Matrix:\n");
    printf("%d\n", staticMatrix[0][0]);
    printf("%d\n", staticMatrix[0][1]);
    printf("%d\n", staticMatrix[1][0]);
    printf("%d\n", staticMatrix[1][1]);
    /*
    This code bellow alocates memory for the matrix in the heap.
    This type of matrix is dynamic and more slow
    */
    int **dynamicMatrix;
    createDinamicIntMatrix(&dynamicMatrix,4,4);
    dynamicMatrix[0][0] = 10;
    dynamicMatrix[0][1] = 20;
    dynamicMatrix[0][2] = 30;
    dynamicMatrix[0][3] = 40;
    dynamicMatrix[1][0] = 50;
    dynamicMatrix[1][1] = 60;
    dynamicMatrix[1][2] = 70;
    dynamicMatrix[1][3] = 80;
    dynamicMatrix[2][0] = 90;
    dynamicMatrix[2][1] = 10;
    dynamicMatrix[2][2] = 11;
    dynamicMatrix[2][3] = 12;
    dynamicMatrix[3][0] = 13;
    dynamicMatrix[3][1] = 14;
    dynamicMatrix[3][2] = 15;
    dynamicMatrix[3][3] = 16;
    printf("Dynamic Matrix:\n");
    printMatrix(dynamicMatrix,4,4);

    free(dynamicMatrix);
    free(staticMatrix);
    return 0;
}