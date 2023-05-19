#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int created_processes = 0;

void create_child(int process_name, pid_t parent_pid) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork error");
        exit(1);
    } else if (pid == 0) {

        printf("Proces %d - PID: %d, PPID: %d\n", process_name, getpid(), parent_pid);

        if (process_name == 1) {
            create_child(2, getpid());
            create_child(3, getpid());
        } else if (process_name == 2) {
            create_child(4, getpid());
            create_child(5, getpid());
        } else if (process_name == 3) {
            create_child(6, getpid());
            create_child(7, getpid());
        }

        exit(0);
    } else {
        created_processes++;
    }
}

int main() {
    printf("Proces glowny - PID: %d\n", getpid());

    create_child(1, getpid());

    while (created_processes > 0) {
        wait(NULL);
        created_processes--;
    }

    return 0;
}
