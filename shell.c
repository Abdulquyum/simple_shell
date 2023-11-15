#include "shell.h"

/**
 * execute_command - accepts and execute shell command
 *
 * @command: command to be executed
 *
 * Return: Sucess
 */

int execute_command(const char *command)
{
	pid_t child_pid;
	int status, i;

	if (strcmp(command, "exit") == 0)
	{
		_exit(EXIT_SUCCESS);
	}
	else if (strcmp(command, "env") == 0)
	{
		extern char **environ;

		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (0);
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return (-1);
		}
		else if (child_pid == 0)
		{
			execlp(command, command, NULL);
			fprintf(stderr, "%s: command not found\n", command);
			_exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			else
				return (-1);
		}
	}
}
