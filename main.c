#include "shell.h"

extern char **environ;

/**
 * main - Build a simple shell like sh
 *
 * Return: 0;
 */
int main(void)
{
	int foo;
	char *command = NULL;
	size_t len = 0;
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
		if (args[0] == NULL)
		{
			free(command);
			command = NULL;
			continue;
		}
		_execute(args, command);
		free_pointers_array(args);
	}
	free_pointers_array(args);
	free(command);
	return (0);
}

/**
 * _execute - execute the command
 * @args: the argv array
 * @command: the prompt the user typed
 * Return: nothing
 */
void _execute(char **args, char *command)
{
	int foo;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		free(command);
		command = NULL;
		free_pointers_array(args);
		perror("Fork");
		exit(errno);
	}
	else if (pid == 0)
	{
		foo = execve(args[0], args, environ);
		if (foo == -1)
		{
			free(command);
			free_pointers_array(args);
			perror("./hsh: 1");
			exit(errno);
		}
	}
	else
	{
		wait(NULL);
	}

}
