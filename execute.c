#include "shell.h"

/**
 * env_var - function that gets environment variable
 *
 * @token: token given to the function to display
 *
 * Return: Nothing
 */
void env_var(char *token)
{
	if (strcmp(token, "env") == 0)
	{
		int i;
		extern char **environ;

		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}
