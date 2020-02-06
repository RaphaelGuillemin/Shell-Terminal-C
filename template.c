#define true 1
#define false 0
#define bool int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {}

void shell() {
    int lineSize = 20;
    int character;
    int pos = 0;
    char* line = malloc(lineSize * sizeof(char));
    if (line == NULL){
        exit(-1);
    }
    do {
        character = getchar();

        //if line is longer than the lineSize
        if (pos >= lineSize){
            lineSize = lineSize * 2;
            line = realloc(line,lineSize);
        }

        //adds characters to the line while it's not \n
        if (character != 10 && character != EOF) {
            line[pos] = character;
            pos++;
        } else {
            line[pos] = '\0';
            printf("Line : %s \n", line); //CHANGE THAT TO READLINE CALL
            free(line);
            line = malloc(lineSize * sizeof(char));
            pos = 0;
        }

        // exit if user types exit
        if (strcmp(line,"exit") == 0){
            exit(1);
        }

    } while (1);
    printf("Line : %s", line);
}

/*
 * Dont change main!
 *
 * You may add unit tests here, but we will rip out main entirely when we grade your work.
 */
int main (void) {
    shell();
}