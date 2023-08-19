#include "main.h"

int main()
{
	int i, foo;
	pid_t pid;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork");
			exit(1);
		}
		else if (pid == 0)
		{
			foo = execve(args[0], args, NULL);
			if (foo == -1)
			{
				perror("Execve");
				exit(2);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
