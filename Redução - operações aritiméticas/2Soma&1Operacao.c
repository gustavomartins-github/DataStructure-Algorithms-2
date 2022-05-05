#include <stdio.h>

int main (void){
    /*
        Esse programa exemplifica uma forma de realizar 2 somas em 1 só. Para isso, devemos relembrar
    que o tipo inteiro reserva 4 bytes de memória, ou seja, 32 bits, enquanto o tipo short integer
    reserva 2 bytes de memória, ou seja, 16 bits.
        Para isso, devemos criar 4 ponteiros para short int, pois em 1 enteiro cabe 2 short ints. Dai
    apontamos de forma sequencial e 2 a 2, os ponteiros. Ex.:

    int a; --> espaço na memória = 4bits = [][][][]
    
    short int *c = a --> a = [][][c][c]
    short int *d = c + 1 ou short int *d = &c[1]; --> a = [d][d][c][c]
    
    Obs.: cada [] é um byte, ou seja, 8 bits. Assim cada short int ocupa 2 [] dentro de uma variavel int de 4 bytes
    */

    //declarei a variável a e b
    int a,b;
    //declarei 4 ponteiros para short int
    short int *c, *d, *e, *f;

    c = &a;
    d = &c[1];

    e = &b;
    f = e + 1;

    
    // por enquanto c = 3 e d = 2;
    *c = 3;
    *d = 2; 
    *e = 5;
    *f = 4;
    printf("Antes da soma\n");
    printf("c:%d\n", *c);
    printf("d:%d\n", *d);
    printf("e:%d\n", *e);
    printf("f:%d\n", *f);  
    printf("a:\n", a);
    printf("b:\n", b);

    /* 
    Ao realizar a soma abaixo, "c = c + e", e "d = d + f". O valores de c e d serão 7
    Agora as variávei "e" e "f" permanecem 5 e 4, pois a soma será armazenada na variável a
    */
    a = a + b;
    
    /* 
    Ao realizar a soma abaixo, "e = c + e", e "d = d + f". O valores de e e f serão 7
    Agora as variávei "c" e "d" permanecem 3 e 2, pois a soma será armazenada na variável b
    DESCOMENTE O COMENTÁRIO A BAIXO PARA TESTAR*/
    // b = a + b; 
   
    printf("Depois da soma\n");
    printf("a:%d\n", a);  
    printf("b:%d\n", b);  
    printf("c:%d\n", *c); 
    printf("d:%d\n", *d); 
    printf("e:%d\n", *e); 
    printf("f:%d\n", *f);   
}

