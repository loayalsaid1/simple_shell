#include "shell.h" 

int main()
{
	int foo;
	char *command = NULL;
	size_t len = 0;
	pid_t pid;
	char *args[] = {NULL, NULL};

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		foo = getline(&command, &len, stdin);
		if (foo == -1)
		{
			exit(0);
		}
		command[foo - 1] = '\0';
		args[0] = command;

		pid = fork();
		if (pid == -1)
		{
			free(command);
			perror("Fork");
			exit(2);
		}
		else if (pid == 0)
		{
			foo = execve(args[0], args, NULL);
			if (foo == -1)
			{
				free(command);
				perror("Execve");
				exit(3);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(command);
	return (0);
}
