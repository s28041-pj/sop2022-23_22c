#include <stdio.h>

int main() {
    int n, liczba, suma = 0;
    int i;
    printf("Podaj ilosc elementow");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Podaj liczbe %d: ", i);
        scanf("%d", &liczba);
        suma += liczba;
    }

    printf("Suma liczb: %d\n", suma);

    return 0;
}
