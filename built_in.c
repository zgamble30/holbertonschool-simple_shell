#include "shell.h"

/**
 * find_builtins - the function selector.
 * @args: user input.
 * Return: the function name or NULL for no match.
 */

int (*find_builtins(char *args))()
{
	int i;

	built_ins b_selector[] = {
	{"exit", exit_function},
	{"env", env_function},
	{NULL, NULL}
	};

	i = 0;

	while (b_selector[i].name)
	{
		if (*(b_selector[i].name) == *args)
			return (b_selector[i].func);
		i++;
	}
	return (NULL);
}

/**
 * exit_function - exit program.
 * Return: 0.
 */

int exit_function(void)
{
	exit(0);
	return (0);
}

/**
 * env_function - prints current environment variables.
 * Return: 0.
 */

int env_function(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}


