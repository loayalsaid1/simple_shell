#include "main.h"

unsigned int count_tokens(char *string, char *separators, unsigned int len)
{
	int i, temp_i, count = 0;

	i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (strchr(separators, string[i]) == NULL)
				break;

			i++;
		}

		temp_i = i;
		while (i < len)
		{
			if (strchr(separators, string[i]) != NULL)
				break;
			i++;
		}

		if (i > temp_i)
			count++;
	}
	 return (count);
}

char **split_string(char *string, char *separators)
{
	unsigned int i, j, token_index, count, len;
	char **tokens_array;
	char buffer[16384];

	len = strlen(string);
	count = count_tokens(string, separators, len);

	tokens_array = malloc(sizeof(char *) * (count + 1));
	i = 0;
	token_index = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (strchr(separators, string[i]) == NULL)
				break;
			i++;
		}

		j = 0;
		while (i < len)
		{
			if (strchr(separators, string[i]) != NULL)
				break;
			buffer[j] = string[i];
			i++;
			j++;
		}

		if (j > 0)
		{
			buffer[j] = '\0';

			tokens_array[token_index] = malloc(sizeof(char) *
							(strlen(buffer) + 1));

			strcpy(tokens_array[token_index], buffer);

			token_index++;
		}
	}
	tokens_array[token_index] = NULL;

	return (tokens_array);
}	
