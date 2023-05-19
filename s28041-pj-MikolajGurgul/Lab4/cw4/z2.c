#include <stdio.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int suma(int a, int b) {
    return a + b;
}

int forAll(int *array, int size, int (*func)(int, int)) {
    int i;
    int result = array[0];
    for (i = 1; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

int main() {
    int array[] = {9, 12, 88, 333, 21};
    int size = sizeof(array) / sizeof(array[0]);

    int result = forAll(array, size, maximum);
    printf("Maksimum: %d\n", result);

    result = forAll(array, size, minimum);
    printf("Minimum: %d\n", result);

    result = forAll(array, size, suma);
    printf("Suma: %d\n", result);

    return 0;
}
