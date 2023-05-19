#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, ppid;
    int status;

    ppid = getpid();
    printf("Proces rodzica - PID: %d, PPID: %d\n", ppid, getppid());

    pid = fork();

    if (pid < 0) {
        perror("Fork error");
        exit(1);
    } else if (pid == 0) {

        pid_t child_pid = getpid();
        printf("Proces potomka - PID: %d, PPID: %d\n", child_pid, ppid);

        exit(0);
    } else {

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Proces dziecka zakonczony z kodem: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Proces dziecka zakonczony z sygnalemm: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
