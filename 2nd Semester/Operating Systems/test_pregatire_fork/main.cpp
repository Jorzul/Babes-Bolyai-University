#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2];
    pid_t pidA, pidB;

    // Create the pipe
    if (pipe(pipe_fd) == -1) {

    }

    return 0;
}
