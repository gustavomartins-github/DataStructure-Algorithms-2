#include <stdio.h>
#include <stdlib.h>

int main (void){
    int x = 0;
    printf("antes da funcao referencia: %d\n", x);
    /* 
    o endereço de conteúdo de x é passado para a função por cópia e 
    seu cónteúdo é alterado por referência. Sendo assim, modifica o valor 
    de "x" mesmo estando fora do escopo da função
    */
    referencia(&x);
    printf("depois da funcao referencia: %d\n", x);  
    x = 0; // reseta o valor de x
    /*
    O valor do conteúdo de x não é alterado pois a passagem é por cópia 
    */
    printf("resetando o valor de x...\n");
    printf("antes da funcao copia: %d\n", x);
    copia(x);
    printf("depois da funcao copia: %d\n", x);

}

// passagem de parâmetro por referência
void referencia(int *p){
    *p = *p + 1; // aqui ocorre a desrreferenciação de p para poder acessar o conteúdo da variável referenciada no parâmetro
}

// passagem de parâmetro por cópia
void copia(int x){
    x = x + 2;
}