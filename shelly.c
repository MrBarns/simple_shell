#include "main.h"


/**
 * getadd - removes newline character from end of input
 * @lineptr: string from input stream
 *
 * Return: string without ending newline character
 */

char **getadd(char *lineptr)
{
	int ind, count = 0;
	char **argv, *arg;

	lineptr = strtok(lineptr, "\n");
	for (ind = 0; lineptr[ind]; ind++)
	{
		if ((ind) && (lineptr[ind] != ' ') && (lineptr[ind - 1] == ' '))
			count++;
	}
	argv = malloc(sizeof(char *) * (count + 2));
	if (!argv)
	{
		free(argv);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	for (arg = strtok(lineptr, " "), ind = 0; arg != NULL;
	     arg = strtok(NULL, " "))
	{
		argv[ind] = arg;
		ind++;
	}
	argv[ind] = arg;

	return (argv);
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
	char **argv, *lineptr = NULL;
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
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		argv = getadd(lineptr);
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, environ);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			lineptr = NULL;
			n = 0;
		}
	}
	free(lineptr);
	return (0);
}
