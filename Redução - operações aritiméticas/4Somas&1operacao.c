#include <stdio.h>
/*
The program do 4 somes in just one step using pointers.
*/
int main (void){
    long long a,b;
    printf("%d\n",sizeof(a));
    short int *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8;
    
    n1 = &a;
    n2 = n1+1;
    n3 = n2+1;
    n4 = n3+1;
    
    n5 = &b;
    n6 = n5+1;
    n7 = n6+1;
    n8 = n7+1;

    *n1 = 1;
    *n2 = 2;
    *n3 = 3;
    *n4 = 4;
    *n5 = 5;
    *n6 = 6;
    *n7 = 7;
    *n8 = 8;

    a = a + b;
    printf("%lld\n",a);
    printf("n1 = %d\n",*n1);
    printf("n2 = %d\n",*n2);
    printf("n3 = %d\n",*n3);
    printf("n4 = %d\n",*n4);
    printf("n5 = %d\n",*n5);
    printf("n6 = %d\n",*n6);
    printf("n7 = %d\n",*n7);
    printf("n8 = %d\n",*n8);
    return 0;
}

int a(size_t penis){

}

