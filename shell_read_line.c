#include "shell.h"
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
		free(line);
		exit(0);
	}
	return (line);
}
