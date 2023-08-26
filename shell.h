#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


char **split_string(char *string, char *separators);
unsigned int count_tokens(char *string, char *separators, unsigned int len);
void free_pointers_array(char **array);
void _execute(char **, char *);
int handle_path(char **args);

#endif /*_SHELL_H_*/
