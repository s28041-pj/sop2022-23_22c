#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, ppid;

    char input[100];
    pid = getpid();
    ppid = getppid();

    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);

    printf("Podaj dane:");

    fgets(input, sizeof(input), stdin);

    printf("Wprowadzono: %s", input);

    return 0;
}
