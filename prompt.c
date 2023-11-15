#include "shell.h"

/**
 * shell_prompt - command to prints the shell prompt
 *
 * Return: exit
 */

void shell_prompt(void)
{
	char *prompt = "cisfun$ ";

	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
}
