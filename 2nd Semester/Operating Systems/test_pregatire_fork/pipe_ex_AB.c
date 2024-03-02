//
// Created by User on 5/18/2023.
//
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2], n = 60, n_B;
    pid_t pidA, pidB;

    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed.");
        exit(1);
    }

    while (n <= 5)
    {

        // Fork process A

        pidA = fork();
        if (pidA < 0)
        {
            perror("Forking process A failed");
            exit(1);
        }
        else if (pidA == 0)
        {
            // Child process A

            printf("A->%d\n", n);

            close(pipe_fd[0]); // Close the read end

            write(pipe_fd[1], &n, sizeof(n));
            close(pipe_fd[1]);

            pidB = fork();
            if (pidB < 0)
            {
                perror("Forking process B failed.");
                exit(1);
            }
            else if (pidB == 0)
            {
                // Child process B

                close(pipe_fd[1]); // Close the write end

                read(pipe_fd[0], &n_B, sizeof(n));

                close(pipe_fd[0]);
                n_B = n_B / 3;
                printf("B->%d\n", n_B);

                exit(0);

            } else {

                // Parent process of B

                wait(NULL);
                close(pipe_fd[0]); // Close the read end of parent B

                write(pipe_fd[1], &n_B, sizeof(n));
                close(pipe_fd[1]); // Close the write end of parent B

                exit(0);
            }
        } else {

            // Parent process of A

            wait(NULL);

            close(pipe_fd[1]);

            read(pipe_fd[0], &n, sizeof(n));
            close(pipe_fd[0]);

            if (n <= 5) {
                break;
            } else {
                int i = 0;
                while (i < 3) {
                    if ((n + i) % 3 == 0) {
                        n = n + 3;
                        i = 3;
                    }
                    i++;
                }
            }
        }
    }

    return 0;
}