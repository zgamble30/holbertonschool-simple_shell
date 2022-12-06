#include "shell.h"

/**
 * shell_split_line - function which tokenizes string.
 * @line: string input.
 * Return: tokenized input.
 */

char **shell_split_line(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimiters = " \n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}

/**
 * shell_read_line - function which read the user input.
 * Return: the user input.
 */

char *shell_read_line(void)
{
	int temp;
	char *line = NULL;
	size_t buflen = 0;

	temp = getline(&line, &buflen, stdin);
	if (temp == EOF)
	{
		exit(0);
	}
	return (line);
}

/**
 * shell_exec - forks child processes.
 * @args: commands being passed.
 */

void shell_exec(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error1");
		exit(1);
	}

	else if (child_pid > 0)
	{
		int status;

		wait(&status);
	}

	else
	{
		perror("Error2");
	}
}

/**
 * main - runs the shell.
 * Return: 0 always.
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	char *line;
	char **tokens;

	while (true)
	{
		printf("($) ");
		line = shell_read_line();
		if (line == NULL)
		{
			exit(0);
		}
		tokens = shell_split_line(line);

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);
		}

		free(tokens);
		free(line);
	}
	return (0);
}
