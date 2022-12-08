#include "shell.h"
/**
 * shell_exec - forks child processes.
 * @args: commands being passed.
 */

void shell_exec(char **args)
{
	pid_t child_pid;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
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
