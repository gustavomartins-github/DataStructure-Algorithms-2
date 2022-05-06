#include <stdio.h>
#include <stdlib.h>

/* 
This functin alocates memory for a matrix in the heap. 
This tye of matrix is dynamic and more slow than the static one.
*/
void createDinamicIntMatrix(int ***matrix, int rows, int columns) {
    int **m;
    m = malloc(sizeof(int *) * rows); // number of rows and 8 = number of bytes per row
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(sizeof(int) * columns); // number of columns and 4 = number of bytes per column 
    }
    matrix = &m;
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
    int **dinamicMatrix;
    createDinamicIntMatrix(&dinamicMatrix,2,2);
    dinamicMatrix[0][0] = 10;
    dinamicMatrix[0][1] = 20;
    dinamicMatrix[1][0] = 30;
    dinamicMatrix[1][1] = 40;
    printf("%d\n", dinamicMatrix[0][0]);
    printf("%d\n", dinamicMatrix[0][1]);
    printf("%d\n", dinamicMatrix[1][0]);
    printf("%d\n", dinamicMatrix[1][1]);
    return 0;
}