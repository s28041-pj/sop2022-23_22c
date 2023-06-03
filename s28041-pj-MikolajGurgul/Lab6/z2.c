#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LOCK_FILE_PATH "/tmp/lock"

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Wykryto probe uruchomienia drugiej instancji programu");
    }
}

void cleanup() {
    remove(LOCK_FILE_PATH);
}

int main() {
    FILE* lock_file = fopen(LOCK_FILE_PATH, "r");
    if (lock_file) {
        pid_t pid;
        fscanf(lock_file, "%d", &pid);
        fclose(lock_file);

        kill(pid, SIGUSR1);
        return 0;
    }

    lock_file = fopen(LOCK_FILE_PATH, "w");
    if (!lock_file) {
        printf("Nie mozna utworzyc pliku blokady");
        return 1;
    }

    fprintf(lock_file, "%d", getpid());
    fclose(lock_file);

    signal(SIGUSR1, signal_handler);
    signal(SIGINT, cleanup);

   while (1) {
        sleep(1);
    }

    return 0;
}
