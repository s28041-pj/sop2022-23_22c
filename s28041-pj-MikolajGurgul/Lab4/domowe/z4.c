#include <stdio.h>
#include <stdlib.h>

void fibonacciIterative(int n) {
    int i;
    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    printf("Ciag Fibonacciego iteracyjnie: ");

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (i = 0; i <= n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    free(fib);
}

int main() {
    int n;

    printf("Podaj liczbe n: ");
    scanf("%d", &n);

    fibonacciIterative(n);

    return 0;
}
