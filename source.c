#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Success
 */

int main(void)
{
	char *line_ptr = NULL;
	size_t buffer = 0;
	ssize_t read_input;
	char *token;
	char *args[100];
	int arg_count;
	pid_t wstatus, child_pid;

	while (1)
	{
		shell_prompt();

		read_input = getline(&line_ptr, &buffer, stdin);
		if (read_input == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(line_ptr, " \t\n");
		arg_count = 0;

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " \t\n");
		}
		if (arg_count == 0)
		{
			continue;
		}
		args[arg_count] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			free(line_ptr);
			exit(EXIT_SUCCESS);
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			_exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execvp(args[0], args);
			fprintf(stderr, "%s: No such file or directory\n", args[0]);
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(&wstatus);
		}
		free(line_ptr);
	}
	_exit(EXIT_SUCCESS);
}
