#include "shell.h"

/**
 * prompt - function that displays prompt of mini shell
 *
 * Return: Nothing
 */
void prompt(void)
{
	char *line_ptr = NULL;
	size_t buffer = 0;
	ssize_t read_input;

	if (isatty(fileno(stdin)))
	{
		printf("#cisfun$ ");
		fflush(stdout);
	}
}
