#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int suma(int a, int b) {
    return a + b;
}

int main() {
    int (*functions[3])(int, int) = {maximum, minimum, suma};
    int functionId, elementCount;
    int i, v;
    int *numbers;

    printf("Podaj numer funkcji (0 - maksimum, 1 - minimum, 2 - suma): ");
    scanf("%d", &functionId);

    printf("Podaj liczbe elementow: ");
    scanf("%d", &elementCount);

    numbers = (int *)malloc(elementCount * sizeof(int));

    if (numbers == NULL) {
        printf("Blad alokacji pamieci");
        return 1;
    }

    printf("Podaj kolejne liczby:\n");

    for (i = 0; i < elementCount; i++) {
        scanf("%d", &numbers[i]);
    }

    v = numbers[0];
    for (i = 1; i < elementCount; i++) {
        v = functions[functionId](v, numbers[i]);
    }

    printf("Wynik: %d\n", v);

    free(numbers);

    return 0;
}
