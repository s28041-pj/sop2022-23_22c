#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Otrzymano sygnal SIGUSR1");
        exit(0);
    }
}

int main() {
    printf("PID: %d\n", getpid());

    signal(SIGUSR1, signal_handler);

    while (1) {
      pause();
    }

    return 0;
}
