#include "main.h"

extern char **environ;

void print_environ(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

int main()
{
	print_environ();

	return (0);
}
