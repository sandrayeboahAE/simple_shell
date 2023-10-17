#include "shell.h"

char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int  i;
	struct stat st;
	/* if the command is path already */
	for (i = 0, command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0) /* if path exists */
				return (_strdup(command));
			return (NULL);
		}
	}
	/* if the user redirected paths (can't find directories) */
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	/* attempt to handle the path */
	dir = strtok(path_env, ":");
	while (dir)
	{
		/* size = len(directory) + len(command) + 2 ('/' and '\0') */
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
