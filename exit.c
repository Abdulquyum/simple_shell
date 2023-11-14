#include "shell.h"

/**
 * exit_shell - function that quit shell
 *
 * @token: the command given to shell to quit
 *
 * Return: Nothing
 */
void exit_shell(char *token)
{
	if (strcmp(token, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
