#include "main.h"


/**
 * getadd - removes newline character from end of input
 * @lineptr: string from input stream
 *
 * Return: string without ending newline character
 */

char *getadd(char *lineptr)
{
	int count;

	for (count = 0; lineptr[count]; count++)
	{
		if (lineptr[count] == '\n')
			lineptr[count] = 0;
	}

	return (lineptr);
}


/**
 * main - entry function
 *
 * @ac: number of args
 * @av: arguments vector
 *
 * Return: 0 on success, error otherwise.
 */


int main(int ac, char *av[])
{
	pid_t child_pid;
	int status;
	char *argv[2] = {NULL, NULL}, *lineptr = NULL;
	ssize_t ret;
	size_t n = 0;

	(void) ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, ":) ", 3);
		ret = getline(&lineptr, &n, stdin);
		if (ret == -1)
		{
			free(lineptr);
			write(STDOUT_FILENO, "logout\n", 7);
			return (1);
		}
		argv[0] = getadd(lineptr);
		argv[1] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, environ);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}

	free(lineptr);
	return (0);
}
