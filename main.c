#include "main.h"

/**
 * main - simple shell
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *buffer;

	/*unused parameter*/
	(void)argc;

	/*for interactive mode*/
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			putstr("Cash$ ");
			fflush(stdout);
			buffer = take_command();
			execute_command(buffer, argv[0]);
			free(buffer);
		}
	}
	/*for non-interactive mode*/
	else
	{
		buffer = take_command();
		execute_command(buffer, argv[0]);
		free(buffer);
	}
	
	exit(EXIT_SUCCESS);
}

/**
 * putstr - prints a string to standard output
 * (basically a _putchar for strings)
 * Prototype: void putstr(char *str);
 * @str: the string to print
 * Return: void
 */

void putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
}


/**
 * take_command - takes a command line from standard input using getline
 * Prototype: char *take_command(void);
 * Return: the command line.
 */

char *take_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		perror("Can't read command");
		exit(EXIT_FAILURE);
	}

	return (command);
}
