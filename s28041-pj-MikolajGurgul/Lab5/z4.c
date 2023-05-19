#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_child(int level) {
    pid_t pid = fork();

    if (level > 10) {
        return;
    }

    if (pid < 0) {
        perror("Fork error");
        exit(1);
    } else if (pid == 0) {

        printf("Proces potomny %d - PID: %d, PPID: %d\n", level, getpid(), getppid());

        wait(NULL);

        exit(0);
    } else {

        wait(NULL);

        printf("Proces rodzica %d - PID: %d, PPID: %d\n", level - 1, getpid(), getppid());

        create_child(level + 1);
    }
}

int main() {
    printf("Proces glowny - PID: %d\n", getpid());

    create_child(1);

    return 0;
}
