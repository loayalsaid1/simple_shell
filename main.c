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

		get_prompt(&command, &len);
		args = split_string(command, " ");
		_execute(args, command);
		free_pointers_array(args);
		free(command);
		command = NULL;
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

/**
 * get_prompt - Read the prompt from the user
 * @buffer_address: the adress of where to store the prompt
 * @len_pointer: A pointer to the len variable
 * Return - void
 */
void get_prompt(char **buffer_address, int *len_poiter)
{
 	foo = getline(buffer_address, len_address, stdin);
	if (foo == -1)
	{
		free(buffer_address);
		exit(0);
	}
	buffer_address[foo - 1] = '\0';
}
