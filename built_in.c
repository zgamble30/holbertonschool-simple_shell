#include "shell.h"
/**
* built_ins is the function selector
* returns the function name
*/

built_ins builtins[] =
{
	{"exit", exit_function},
	{"env", env_function},
	{NULL, NULL}
};


void exit_function(char **args)
{
exit(0);
}

int env_function(int ac, char **av, char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}


