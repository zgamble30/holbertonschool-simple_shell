#include "shell.h"
/**
* built_ins is the function selector
* returns the function name
*/

int find_builtins(char *args)
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

void exit_function(void)
{
	exit(0);
}

int env_function(void)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}


