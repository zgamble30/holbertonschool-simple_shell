#include "shell.h"

/**
 * shell_split_line - function which tokenizes string.
 * @line: string input.
 * Return: tokenized input.
 */

char **shell_split_line(char *line)
{
	int length = 0;
	int capacity = 32;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimiters = " \n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}
