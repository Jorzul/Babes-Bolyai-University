//
// Created by User on 5/18/2023.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2];
    pid_t pidA, pidB;

    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed.");
        exit(1);
    }

    // Fork process A
    pidA = fork();
    if (pidA < 0)
    {
        perror("Forking process A failed.");
        exit(1);
    }
    else if (pidA == 0)
    {
        // Child process A
        close(pipe_fd[0]); // Close the read end of the pipe in A

        // Write data to the pipe
        char messageA[] = "Hello from Process A";
        write(pipe_fd[1], messageA, sizeof(messageA));
        close(pipe_fd[1]);

        printf("Process A has finished\n");

        exit(0);
    }

    pidB = fork();
    if (pidB < 0)
    {
        perror("Forking process B failed.");
        exit(1);
    }
    else if (pidB == 0)
    {
        // Child process B
        close(pipe_fd[1]); // Close the write end of the pipe in B

        char messageB[100];
        read(pipe_fd[0], messageB, sizeof(messageB));
        printf("Process B received message: %s\n", messageB);
        close(pipe_fd[0]); // Close the read end of the pipe in B

        printf("Process B has finished\n");

        exit(0);
    }

    // Parent process
    close(pipe_fd[0]); // Close both ends of the pipe in parent
    close(pipe_fd[1]);

    // Wait for the child processes to finish
    wait();
    wait();

    printf("Parent process has finished\n");

    return 0;
}
