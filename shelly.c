#include "main.h"



/**
 * getav - removes newline character from end of input
 *
 * @lineptr: string from input stream
 * @environ: environment vector
 *
 * Return: string without ending newline character
 */

char **getav(char *lineptr, char **environ)
{
	int ind, count = 0;
	char **argv, *arg;

	(void) environ;

	arg = strtok(lineptr, "\n");
	for (ind = 0; arg[ind]; ind++)
	{
		if ((ind) && (arg[ind] != ' ') && (arg[ind - 1] == ' '))
			count++;
	}
	argv = malloc(sizeof(char *) * (count + 2));
	if (!argv)
	{
		free(argv);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	arg = strtok(arg, " ");
	/*
	 *getadd(arg, environ);
	 */
	for (ind = 0; ind < 1; ind++)
	{
		argv[ind] = arg;
	}
	argv[ind] = NULL;

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
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (*lineptr != '\n')
		{
			argv = getav(lineptr, environ);
			child_pid = fork();
			if (child_pid == 0)
			{
				execve(argv[0], argv, environ);
				perror(av[0]);
				exit(EXIT_FAILURE);
			} else
			{
				wait(&status);
				free(lineptr);
				free(argv);
				n = 0;
			}
		} else
			write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
