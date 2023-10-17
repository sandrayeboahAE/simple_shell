#include "shell.h"
/**
 * main - Simple shell main function
 * @argc: Argument count
 * @argv: an array of strings generated from arg
 * Return: 0 Always (success).
 */
int main(int argc, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, idx = 0;
	(void) argc;

	while (1)
	{
		line = read_line();
		if (line == NULL) /* reached EOF ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		idx++;
		command = tokenizer(line);
		if (!command)
			continue;

		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else
		status = _execute(command, argv, idx);
	}
	return (0);

}
