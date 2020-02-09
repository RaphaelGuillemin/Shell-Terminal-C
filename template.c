#define true 1
#define false 0
#define bool int
#define max_len 2000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void shell() {
    do {
        char *line = readLine();
        printf("Line : %s \n", line);

        if (strcmp(line, "exit") == 0) {
            exit(1);
        }

        free(line);

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