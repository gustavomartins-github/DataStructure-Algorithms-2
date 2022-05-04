#include <stdio.h>
#include <stdlib.h>

// esse código exemplifica a passagem de parâmetros por referência quando o assunto é vetores estáticos.

int main (void){
    int v[4];
    printf("Passando o vetor v de 4 elementos com parametro sem o operador &: \n");
    teste1(v,4); // o compilador interpreta como &v[0] automaticamente. 
    printf("Passando o subvetor v[2] de 2 elementos como parametro: \n");
    teste2(&v[2],2); // passa o endereço do deslocamento em duas vezes do vetor v.

    printf("Declarando os valores do vetor para realizar o teste 3...\n");
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    teste3(&v[0],&v[3]); // essa função é interessante pois lida com um vetor com extremos dentro do vetor v
    printf("O tamanho do vetor v e: %d\n", sizeof(v)/4); /* a função sizeof retorna o tamanho de uma variável em bytes. 
                                                            Como 1 int = 4bytes, basta dividir por 4 para saber o tamanho do vetor.*/
}

/*
    Para se referenciar ao endereço de "v" não foi preciso usar &, pois existe uma tabela de símbolos
    que armazena os nomes das variáveis em tempo de compilação que, no ato da formação de sua pilha, saberá
    que quando trata-se da variável "v", estamos falando do endereço de memória de v[0]. Sendo assim, é 
    uma tradução automática que o compilador realiza.
*/
 
void teste1(int *x, int tam){
    x[0] = 1; // poderia ser também: *x = 1;
    x[1] = 2; // poderia ser também: *(x+1) = 2;
    x[2] = 3; // poderia ser também: *(x+2) = 3;
    x[3] = 4; // poderia ser também: *(x+3) = 4;
    for (int i = 0; i < tam; i++){
        printf("%d\n", x[i]);
    }
}

void teste2(int *x, int tam){
    x[0] = 1;
    x[1] = 2;
    for (int i = 0; i < tam; i++){
        printf("%d\n", x[i]);
    }
}

void teste3(int *ini, int *fim){
    while (ini < fim){
        printf("%d\n", *ini);
        ini++;
    }
    //printing ini
    printf("%d\n", ini);
    //printing fim
    printf("%d\n", fim);
}

/* pergunta: se temos o valor de inicio e fim de um vetor, podemos 
percorre-lo por um while. Para percorre com um for, deveriamos saber o 
tamanho do vetor. Como saber o tamanho de um vetor sabendo seus extremos? 
E mais dificil doque o professor disse ma sugiro usar um contador em um while
pra saber quantos termos terá de apresentar. Dai teriamos uma noção de quantos
bytes, mas nao vale a pena pois realiza etapas a mais para o mesmo fim */