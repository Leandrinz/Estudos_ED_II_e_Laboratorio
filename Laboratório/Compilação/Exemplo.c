#include <stdio.h>
#include <stdlib.h>

int fib(int a){
    if (a < 2){
        return a;
    }
    else{
        return fib(a-1) + fib(a-2);
    }
}



/*
argc: Quantidade de parâmetros passados + nome do algoritmo
argv[]: Os parâmetros em formato de string (char*)
*/


int main(int argc, char *argv[]){
    int x = atoi(argv[1]);
    printf("Fib(%d) = %d\n", x, fib(x));
    return 0;
}