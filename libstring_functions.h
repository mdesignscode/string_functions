#ifndef _LIBSTRING_FUNCTIONS_H_
#define _LIBSTRING_FUNCTIONS_H_

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdarg.h>


int wrdcnt(char *str, char *token);
int *before_delim(char *str, char *token);
char **strsplt(char *str, char *token, char new_delim);
size_t **strings_count(char **strings);
int *f_line_count(char *filename, char *sub);
int *f_letter_count(char *filename);


#endif
