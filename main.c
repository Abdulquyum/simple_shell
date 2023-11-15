#include "shell.h"

/**
 * main - Entry point that carries out all attached functions
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return : Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *line_ptr = NULL, *token;
	size_t buffer = 0;
	ssize_t read_input;
	pid_t wstatus;
	int exec_ret;

	while (1)
	{
		prompt();
		
		read_input = getline(&line_ptr, &buffer, stdin);		

		if (read_input == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				printf("%s: No such file or directory\n", argv[0]);
				free(line_ptr);
				_exit(EXIT_FAILURE);
			}
		}

		token = strtok(line_ptr, " \t\n");
		char *arg[] = {token, NULL};

		if (token == NULL)
	       	{
		         continue;
		}
		
		exit_shell(token);
		env_var(token);

		if (token == NULL)
	       	{
		       printf("%s: No such file or directory\n", argv[0]);
		       continue;
		}

		pid_t child_pid = fork();
		
		if (child_pid == -1)
		{
			perror("Error");
			_exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			exec_ret = execve(token, arg, NULL);

			if (exec_ret == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
				free(line_ptr);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
             		wait(&wstatus);
		}
	}

	free(line_ptr);
	_exit(EXIT_SUCCESS);

	return (0);
}
