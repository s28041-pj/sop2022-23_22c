#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

int main() {

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Blad podczas tworzenia gniazda");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(90811);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Blad podczas nawiazywania polaczenia z serwerem");
        exit(1);
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("Podaj nazwe pliku do pobrania: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    size_t filename_length = strlen(filename);
    if (send(client_socket, &filename_length, sizeof(size_t), 0) == -1) {
        perror("Blad podczas wysylania dlugosci nazwy pliku");
        exit(1);
    }
    if (send(client_socket, filename, filename_length, 0) == -1) {
        perror("Blad podczas wysylania nazwy pliku");
        exit(1);
    }

    ssize_t file_size;
    if (recv(client_socket, &file_size, sizeof(ssize_t), 0) == -1) {
        perror("Blad podczas odbierania wielkosci pliku");
        exit(1);
    }

    if (file_size == -1) {
        printf("Plik '%s' nie istnieje na serwerze", filename);
        close(client_socket);
        exit(0);
    }


    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Blad podczas otwierania pliku do zapisu");
        close(client_socket);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t received_bytes, total_bytes = 0;
    while (total_bytes < file_size) {
        received_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (received_bytes == -1) {
            perror("Blad podczas odbierania danych pliku");
            fclose(file);
            close(client_socket);
            exit(1);
        }
        fwrite(buffer, 1, received_bytes, file);
        total_bytes += received_bytes;
    }

    printf("Pobieranie pliku '%s' zakonczone", filename);

    fclose(file);
    close(client_socket);

    return 0;
}
