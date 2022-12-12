#include "shell.h"
/**
 * shell_exec - forks child processes.
 * @args: commands being passed.
 */

void shell_exec(char **args)
{	
	pid_t = child_pid;

	for (int i = 0; i < built_ins(); i++)
	{
		if (strcmp(args[0], built_ins[i].name) == 0)
		{
			built_ins[i].func(args);
			return (0);
		}
	}	

	child_pid = fork();

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
