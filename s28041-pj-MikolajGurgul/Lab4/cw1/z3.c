#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int wysokosc;
    int i, j, k;

    if (argc != 2) {
        printf("Podaj wysokosc choinki: \n");
        return 1;
    }

    wysokosc = atoi(argv[1]);

    if (wysokosc <= 0) {
        printf("Wysokosc choinki nie moze byc ujemna \n");
        return 1;
    }

    for (i = 1; i <= wysokosc; i++) {
        for (j = 0; j < wysokosc - i; j++) {
            printf(" ");
        }

        for (k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
