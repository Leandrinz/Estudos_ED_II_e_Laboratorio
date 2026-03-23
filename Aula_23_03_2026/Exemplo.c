#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fib(int);


int main(int argc, char *argv[]){
    clock_t start, end;
    double cpu_time_used = 0;
    int x = 0;
    int N = 100;
    for (size_t i = 0; i < N; i++){
        start = clock();
        fib(atoi(argv[1]));
        end = clock();
        cpu_time_used = (double)(end - start);
    }

    cpu_time_used = cpu_time_used / N;
    cpu_time_used = cpu_time_used / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
    return 0;
}

int fib(int n){
    if (n <= 1){
        return n;
    }
    else{
        return fib(n - 1) + fib(n - 2);
    }
}