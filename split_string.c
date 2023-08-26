#include "shell.h"

/**
 * count_tokens - Count substirngs in a string
 * @string: the string
 * @separators: the separatros
 * @len: the length of the whole string
 * Return: the count
 */
unsigned int count_tokens( *string, char *separators, unsigned int len)
{
	unsigned int i, temp_i, count = 0;

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

/**
 * split_string - simulate strtok, but do the whole tokenizing all at once
 * @string: the string
 * @separators: the separatros
 * Return: array of substrings
 */
char **split_string(char *string, char *separators)
{
	unsigned int i, j, token_index, count, len = strlen(string);
	char **tokens_array;
	char buffer[16384];

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
