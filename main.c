#include "shell.h" 

int main(void)
{
	int foo;
	char *command = NULL;
	size_t len = 0;
	pid_t pid;
	char **args = NULL;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		foo = getline(&command, &len, stdin);
		if (foo == -1)
		{
			free(command);
			exit(0);
		}
		command[foo - 1] = '\0';
		args = split_string(command, " ");

		pid = fork();
		if (pid == -1)
		{
			free(command);
			command = NULL;
			free_pointers_array(args);
			perror("Fork");
			exit(2);
		}
		else if (pid == 0)
		{
			foo = execve(args[0], args, NULL);
			if (foo == -1)
			{

				free(command);
				free_pointers_array(args);
				perror("Execve");
				exit(3);
			}
		}
		else
		{
			wait(NULL);
		}
		free_pointers_array(args);
	}
	free_pointers_array(args);
	free(command);
	return (0);
}
