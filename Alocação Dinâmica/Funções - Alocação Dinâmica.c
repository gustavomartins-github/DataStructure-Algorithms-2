#include <stdio.h>
#include <stdlib.h>
/*
    Existem 3 funções básicas para a alocação dinâmica de memória
    1) malloc()
    2) calloc()
    3) realloc()

    Contudo, ao alocar a memória dinamicamente, devemos desaloca-la no final do programa
    Isso pode ser feito usando a função free()

---> A função mallloc() retorna um ponteiro para void que aponta para a área de memória alocada na HEAP,
sem inicializar a área, possibilitando o acesso a eventuais lixos na memória. Contudo, recebe como parâmetro o tamanho da área a ser alocada.

    Sintaxe: void* ponteiro = malloc(size_t tamanho);

---> A função calloc() retorna um ponteiro para void que aponta para a área de memória alocada na HEAP,
contudo incializa essa área com 0. Sendo assim, recebe como parâmetro o número de áreas a serem alocadas e o tamanho de cada uma delas.

    Sintaxe: void* ponteiro = calloc(size_t numero_de_areas, size_t tamanho);

--> A função realloc() retorna um ponteiro para void que aponta para a área de memória alocada na HEAP,
contudo, altera o tamanho da área alocada. Recebe como parâmetro o ponteiro para a área a ser alterada e o tamanho da nova área.

    Sintaxe: void* ponteiro = realloc(void* ponteiro, size_t tamanho);

--> A função free() desaloca a memória alocada dinamicamente. Recebe como parâmetro o ponteiro para a área a ser desalocada.

Observações gerais:
    1) Se não houver espaço suficiente na memória, a função malloc(), calloc() e realloc() retornarão NULL.
    2) Cuidado com dupla alocação de memória em uma mesma variável.
    3) A função free() deve ser chamada para desalocar toda a memória alocada dinamicamente.
    4) Cuidado com "double free", isto é, desalocar uma área que já foi desalocada, podendo gerar erros.
*/
// função que aloca memória dinâmica para um vetor de inteiros pelo método de retorno
int * alocaMemoria(size_t qtd){
    int *p;
    p = malloc(qtd * sizeof(int));
    if (p == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    else {
        printf("Memoria alocada com sucesso\n");
        return p;
    }       
}

// a função aloca memória dinamicamente para um vetor de inteiros pelo metodo de ponteiro de ponteiro
void alocaMemoria2(size_t qtd, int **p){
    *p = malloc(qtd * sizeof(int));
    if (*p == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    else {
        printf("Memoria alocada com sucesso\n");
    }
}

// a função realoca a memória dinâmica para um vetor de inteiros usando o método de ponteiro para ponteiro
void realocaMemoria(size_t new_qtd, int **p){
    *p = realloc(*p, new_qtd * sizeof(int));
    if (*p == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    else {
        printf("Memoria alocada com sucesso\n");
    }
}

int main(void){
    
    int *point1; 
    int *point2; 
    int *point3;

    // testando alocação dinâmica de memória no escopo da main function
    point1 = malloc(sizeof(int));
    *point1 = 100;
    printf("%d\n", *point1);
    
    // testando alocação dinâmica de memória usando método de retorno de ponteiro
    point2 = alocaMemoria(4);
    point2[0] = 20; point2[1] = 30; point2[2] = 40; point2[3] = 50;
    printf("Testando alocacao dinamica de memoria usando metodo de retorno de ponteiro\n");
    printf("%d\n", point2[0]);
    printf("%d\n", point2[1]);
    printf("%d\n", point2[2]);
    printf("%d\n", point2[3]);

    // testando alocação dinâmica de memória usando método de ponteiro para ponteiro
    alocaMemoria2(2, &point3);
    point3[0] = 60; point3[1] = 70;
    printf("Testando alocacao dinamica de memoria usando metodo de ponteiro para ponteiro\n");
    printf("%d\n", point3[0]);
    printf("%d\n", point3[1]);

    // testando o realocamento de memória
    realocaMemoria(point1, 4);
    point1[0] = 80; point1[1] = 90; point1[2] = 100; point1[3] = 110;
    printf("Testando o realocamento de memoria\n");
    printf("%d\n", point1[0]);
    printf("%d\n", point1[1]);
    printf("%d\n", point1[2]);
    printf("%d\n", point1[3]);

}