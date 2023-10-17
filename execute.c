#include "shell.h"

int _execute(char **command, char **argv);
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		freearray2D(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if execve((full_cmd, command, environ) == -1)
		{
			free(full_cmd);
			freearray2D(command);
			exit(EXIT_FAILURE);
		}
	}
	else if (child < 0)
	{
		perror("Fork failed")
	}
	else
	{
		waitpid(child, &status, 0);
		freearray2D(command);
		free(full_cmd);
	}
	return (WEXITSTATUS(status));
}
