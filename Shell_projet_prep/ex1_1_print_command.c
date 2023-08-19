#include "main.h"

int main()
{
	char *input = NULL;
	long unsigned int input_len;
	
	printf("$ ");

	if ((getline(&input, &input_len, stdin)) == -1)
	{
		perror("Getline");
		exit(2);
	}
	
	printf("%s", input);
	
	free(input);
	return (0);
}
