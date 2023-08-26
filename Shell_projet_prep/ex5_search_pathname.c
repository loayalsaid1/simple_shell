/******************************************************************************
 * ********************* HOT NOTE: MORE EFFECIENT WAY *************************
 *
 * TOKENIZE THE PATH ONLY ONCE, AND FOR EVERYONE, SEARCH FOR ALL OF THE
 * FILENAMES, AND IF ANY WAS FOUND, SOMEHOW, EXECLUDED FROM YOUR SEARCH
 */
#include "main.h"

int main(int argc, char *argv[])
{
	int i = 1, buffer_size;
	struct stat file_info;
	char *path, *pathcpy, *pathname, *token;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: ./_which <filename_1> ...\n");
		exit(1);
	}

	path = getenv("PATH");

	while (argv[i])
	{
		pathcpy = strdup(path);

		token = strtok(pathcpy, ":");
		while (token)
		{
			buffer_size = strlen(token) + 1 + strlen(argv[i]) + 1;
			pathname = malloc(sizeof(char) * buffer_size);
			if (pathname == NULL)
			{
				fprintf(stderr, "Allocation error\n");
				exit(2);
			}

			strcpy(pathname, token);
			strcat(pathname, "/");
			strcat(pathname, argv[i]);

			if ((stat(pathname, &file_info) == 0))
			{
				free(pathname);
				pathname = NULL;
				printf("%s: Found\n", argv[i]);
				break;
			}
			
			free(pathname);
			pathname = NULL;

			token = strtok(NULL, ":");
		}
		if (token == NULL)
			printf("%s: Not found\n", argv[i]);
		free(pathcpy);	
		i++;
	}

	return (0);
}
