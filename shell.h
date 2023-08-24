#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

char **split_string(char *string, char *separators);
unsigned int count_tokens(char *string, char *separators, unsigned int len);
void free_pointers_array(char **array);
void _execute(char **, char *);

#endif /*_SHELL_H_*/
