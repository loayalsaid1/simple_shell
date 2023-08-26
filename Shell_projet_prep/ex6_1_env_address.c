#include "main.h"

extern char **environ;

int main(int argc, char *argv[], char **env)
{
	printf("Environ adress: %p\nMain env address: %p\n", &environ, &env);

	return (0);
}
