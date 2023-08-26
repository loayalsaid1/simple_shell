#include "shell.h"

int handle_path(char **args)
{
	char *path = getenv("PATH"), **paths =NULL, *pathname = NULL;
	int i, buffer_size;
	struct stat file_info;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], X_OK) == 0)
			return (0);
		else
		{
			perror(NULL);
			args[0] = NULL;
			dprintf(2, "./hsh: 1: %s: not found", args[0]);
			return (-1);
		}
	}
	else
	{
		paths = split_string(path, ":");
		for (i = 0; paths[i] != NULL; i++)
		{
			buffer_size = strlen(paths[i]) + 1 + strlen(args[0]) + 1;
			pathname = malloc(sizeof(char) * buffer_size);

			strcpy(pathname, paths[i]);
			strcat(pathname, "/");
			strcat(pathname, args[0]);
			
			if (stat(pathname, &file_info) == 0)
			{
				free(args[0]);
				args[0] = strdup(pathname);
				free(pathname);
				free(paths);
				return(0);
			}
			free(pathname);
		}
		free(paths);
		free(args[0]);
		args[0] = NULL;
		dprintf(2, "./hsh: 1: %s: not found", args[0]);
		return (-2);
	}
}

