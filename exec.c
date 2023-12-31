#include "main.h"

/**
 * execute_command - executes a command.
 * Prototype: void execute_command(char *command, char *shellname);
 * @command: a string of characters (command + arguments)
 * @shellname: the name chosen at compilation.
 * (currently takes the exit command)
 * Return: void
 */
void execute_command(char *command, char *shellname) {
    char *token_list[20], *path;
    pid_t pid, wait_child;
    int executable, i;

    if (command == NULL) {
        perror("Command is NULL");
        exit(EXIT_FAILURE);
    } else if (*command == '\n') {
        /* Handle the case when command is newline */
    } else {
        token_list[0] = strtok(command, " \n");

       
        if (_strcmp(token_list[0], "exit") == 0) {
            free(command);
            exit(EXIT_SUCCESS);
        }

        pid = fork();

        /* It returns -1 if it fails */
        if (pid == -1) {
            free(command);
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        /* In the child process, fork returns 0 */
        if (pid == 0) {
            for (i = 1; token_list[i - 1] != NULL; i++) {
                token_list[i] = strtok(NULL, " \n");
            }

            /* Generate the path to the first command: file name before execution */
            path = get_path(token_list[0]);

            if (path == NULL) {
                /* Handle the case when path is NULL (executable not found) */
                putstr(shellname);
                putstr(": Command not found\n");
                free(command);
                exit(EXIT_FAILURE);
            }

            executable = execve(path, token_list, NULL);

            if (executable == -1) {
                putstr(shellname);
                putstr(": No such file or directory\n");
            }

            free(command);
            exit(EXIT_SUCCESS);
        }

        /* In the parent process, fork returns the pid */
        else {
            wait_child = wait(NULL);

            if (wait_child == -1) {
                free(command);
                perror("wait failed");
                exit(EXIT_FAILURE);
            }
        }
    }
}
