#ifndef MYSHELL_HEADER_H
#define MYSHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>

#define BUFSIZE 1024
#define DELIM " \t\n"

extern char **environ;

typedef struct BuiltinCommand {
    char *command_name;
    int (*command_function)(char **, int *);
} BuiltinCommand;

int shell_execute(char *args[], int *exit_status);
int shell_execute_commands(char *args[], int *exit_status);
char *validate_input(char *args[], char *argv[]);
int validate_only_spaces(char *input);
char **shell_tokenizer(char *input);
void *shell_realloc(void *ptr, size_t size);
void shell_free(char **args);
char *shell_getenv(char *name);
pid_t shell_fork();
void shell_waitpid(pid_t pid, int *status);
void shell_print_prompt();
void shell_fprintf(FILE *stream, const char *format, ...);
void shell_unsetenv(char *name);
int shell_setenv(char *args[], int *exit_status);
int shell_cd(char *args[], int *exit_status);
int shell_exit(char **args, int *exit_status);

#endif
