#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "shell.h"

/**
 * shell_prompt - command to prints the shell prompt
 *
 * Return: exit
 */

char *prompt = "Shell$ ";

void shell_prompt()
{
	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * execute_command - function that accepts and execute a command
 * @command: command to execute
 *
 * Return: Sucess
 */

int execute_command(const char *command)
{
	pid_t child_pid;
	int status;
	int i;

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
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
			execlp(command, command, (char *)NULL);
			fprintf(stderr, "%s: command not found\n", command);
			_exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
			{
				return (WEXITSTATUS(status));
			}
			else
			{
				return (-1);
			}
		}
	}
}
