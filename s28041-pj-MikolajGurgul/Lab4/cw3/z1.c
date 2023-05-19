#include <stdio.h>

void printHexViewer(FILE *file) {
    unsigned int count = 0;
    unsigned int byte;
    unsigned int spaces;
    unsigned int i;

    while ((byte = fgetc(file)) != EOF) {
        if (count % 16 == 0) {
            printf("%08X ", count);
        }

        printf("%02X ", byte);

        if (count % 16 == 7 || count % 16 == 15) {
            printf(" ");
        }

        count++;

        if (count % 16 == 0) {
            printf("\n");
        }
    }

    if (count % 16 != 0) {
        spaces = (16 - count % 16) * 3;

        if (count % 16 <= 7) {
            spaces += 1;
        }

        for (i = 0; i < spaces; i++) {
            printf(" ");
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Podaj nazwe pliku jako argument programu");
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Nie mozna otworzyc pliku");
        return 1;
    }

    printf("Ladowanie pliku: %s\n", argv[1]);

    printHexViewer(file);

    printf("Zamykanie pliku: %s\n", argv[1]);

    fclose(file);

    return 0;
}
