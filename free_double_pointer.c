#include "shell.h"

void free_pointers_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
	array = NULL;
}
