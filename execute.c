#include "shell.h"

/**
 * env_var - prints out environment variables
 *
 * @command: command to be executed
 *
 * Return: 0 (success)
 */
int env_var(const char *command)
{
	int i;

	if (strcmp(command, "env") == 0)
	{
		extern char **environ;

		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (0);
	}
}
