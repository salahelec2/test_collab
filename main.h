#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);

#endif