#include "shell.h"

/**
 * main - runs the shell.
 * @ac: number of arguments.
 * @av: list of arguments.
 * Return: 0 always.
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	char *line;
	char **tokens;

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
		}
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
