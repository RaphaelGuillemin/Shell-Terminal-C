#define true 1
#define false 0
#define bool int
#define max_len 2000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// TODO : gérer le max_len. Est-ce qu'on retourne une erreur ou on alloue dynamiquement?
char* readLine() {
    char *allocated = (char *) malloc(max_len + 1);

    if (NULL == allocated) {
        return NULL;
    }

    size_t cc = 0;
    for(; cc < max_len; ++cc){
        int chr = getc(stdin);
        if (EOF == chr || '\n' == chr) {
            break;
        } else {
            allocated[cc] = (char) chr;
        }
    }
    if (cc == max_len) {
        free(allocated);
        printf("Argument list too long.");
    }
    allocated[cc] = '\0';
    return allocated;
}


char **parse(char *string) {
    int no_of_tokens = 0;

    // Copy original string
    unsigned long len = strlen(string);
    char *string_copy = (char *) malloc(len + 1);
    strcpy(string_copy, string);

    // Find number of tokens
    if (strtok(string_copy, " ") != NULL) {
        ++no_of_tokens;
        while(strtok(NULL, " ") != NULL) {
            ++no_of_tokens;
        }
    }
    free(string_copy);

    // Create tokens
    char **args = malloc(sizeof(char *) * no_of_tokens + 1);
    args[0] = strtok(string, " \n");
    int i = 1;
    while (i < no_of_tokens) {
        args[i] = strtok(NULL, " \n");
        ++i;
    }
    args[i] = NULL;
    printf("%i\n", no_of_tokens);
    return args;
}

void exec_command(char **args) {
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");

    // Child process
    } else if (pid == 0) {
        if (execvp(*args, args) < 0) {
            fprintf(stderr, "execvp failed.\n");
            exit(-1);
        }

    // Parent process
    } else {
        wait(NULL);
    }
}

void shell() {
    char *line;
    char **args;

    do {
        line = readLine();
        printf("Line : %s \n", line);

        args = parse(line);
        printf("First argument : %s\n", args[0]);
        printf("First argument : %s\n", args[1]);
        if (strcmp(args[0], "exit") == 0) {
            exit(1);
        }
        exec_command(args);

        free(line);
        free(args);

    } while (1);
}

/*
 * Dont change main!
 *
 * You may add unit tests here, but we will rip out main entirely when we grade your work.
 */
int main (void) {
    shell();
}