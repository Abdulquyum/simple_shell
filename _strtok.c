#include <stdio.h>
#include <string.h>

/**
 * _strtok - custom strtok function
 *
 * @str: string to be tokenized
 * @delim: parameter for delimeter
 *
 * Return: tokenized string
 */
char *_strtok(char *str, const char *delim)
{
	int i;
	char *token = NULL;
	char *ptr = NULL;

	while (str != NULL)
	{
		ptr = str;

		for (i = 0; str[i] != '\0'; i++)
		{
			if (str != delim)
			{
				token[i++] = str[i++];
			}
			else
				return (token);
		}
	}

		ptr = str;
		str[i] = '\0';
		str = ptr;
	}
	if (str[i] == NULL)
	{
		if (str != delim)
		{
			token[i] = str[i++];
			ptr = str;
			str[i] = '\0';
			str = ptr;
		}
		return (token);
	}
}
