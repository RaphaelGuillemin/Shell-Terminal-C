// Travail de Laura Bégin et Raphaël Guillemin

#define true 1
#define false 0
#define bool int
#define max_len 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Reads a line entered in the shell
// Returns the line as a char*
char *readLine() {
    int curr_max_len = max_len;
    char *allocated = (char *) malloc(curr_max_len + 1);

    if (NULL == allocated) {
        return NULL;
    }

    size_t cc = 0;
    while (cc < curr_max_len) {
        int chr = getc(stdin);
        if (EOF == chr || '\n' == chr) {
            break;
        } else {
            allocated[cc] = (char) chr;
        }
        ++cc;
        if (cc == curr_max_len) {
            curr_max_len += curr_max_len;
            allocated = realloc(allocated, curr_max_len);
        }
    }
    allocated[cc] = '\0';
    return allocated;
}

// Checks if a line has no commands, only empty characters
bool isEmpty(const char *line){
    while (*line != '\0'){
        if (*line != 32 && *line != '\n'){
            return false;
        }
        ++line;
    }
    return true;
}

// Find the number of commands in a line
int find_no_of_cmds(const char *line) {
    int no_of_cmds = 0;
    char *return_ptr;
    char *line_copy = strdup(line); // Copy original line

    if ((return_ptr = strtok(line_copy, "&&||")) != NULL && !isEmpty(return_ptr)) {
        ++no_of_cmds;
        while(strtok(NULL, "&&||") != NULL) {
            ++no_of_cmds;
        }
    }
    free(line_copy);
    return no_of_cmds;
}

// Find the operator separating 2 commands
// Returns & or |
char find_operator(const char *line, char *op_ptr) {
    return line[op_ptr - line + strlen(op_ptr) + 1];
}

// Parse a set of commands and tokenize each command
// Commands are separated by && et ||
char *parse_commands(char *line, char **saveptr) {
    return strtok_r(line, "&&||", saveptr);
}

// Parse a command and tokenize its tokens
char **parse_args(char *cmd) {
    int no_of_args = 0;

    // Copy original command
    char *cmd_copy = strdup(cmd);

    // Find number of tokens
    if (strtok(cmd_copy, " ") != NULL) {
        ++no_of_args;
        while(strtok(NULL, " ") != NULL) {
            ++no_of_args;
        }
    }
    free(cmd_copy);

    // Create tokens
    char **args = malloc(sizeof(char *) * (no_of_args + 1));
    args[0] = strtok(cmd, " \n");
    int i = 1;
    while (i < no_of_args) {
        args[i] = strtok(NULL, " \n");
        ++i;
    }
    args[i] = NULL;
    return args;
}

// Execute linux commands
int exec_command(char **args) {
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");

    // Child process
    } else if (pid == 0) {
        if (execvp(*args, args) < 0) {
            printf("bash : %s: command not found.\n",args[0]);
            exit(-1);
        }

    // Parent process
    } else {
        waitpid(pid, &status, 0);
        if (WEXITSTATUS(status) == 0) {
            return true;
        } else {
            return false;
        }
    }
}

// Find the number of repetitions for r and f function calls
long find_repeat_amount(const char *command){
    // Find number of tokens
    char *cmd_copy = strdup(command);
    if (strtok(cmd_copy, "(") != NULL) {
        char *line = strtok(cmd_copy, "(");
        char *endl = NULL;
        long nbr = strtol(++line,&endl,10);
        if (strcmp(endl,"") != 0){
            free(cmd_copy);
            return -1;
        }
        free(cmd_copy);
        return nbr;
    }
    free(cmd_copy);
    return 1;
}

// Trim commands surrounded by parenthesis, used for r and f function calls
char* trim_command(const char* command){
    char *first = strchr(command,'(');
    char *start = ++first;
    char *end = strchr(command,')');
    char *line = malloc((sizeof(char)) * (end - start + 1));
    memcpy( line, start, end - start );
    line[end - start] = '\0';
    return line;
}

// Linux shell implementation
void shell() {
    start: ;
    char *line;
    char *line_copy; // copy of a line to tokenize it (call to strtok)
    char *cmd;
    char **args; // array of args for a command
    char *saveptr; // saved pointer for multiple calls to strtok_r
    int no_of_cmds;
    char op = ' '; // operator between commands
    int cmd_idx = 0;
    int ret_val = 0; // return value, 1 = successful command, 0 = failed command
    do {
        line = readLine();
        bool run_command = true;
        bool background = false;
        line_copy = strdup(line);
        no_of_cmds = find_no_of_cmds(line_copy);
        cmd_idx = 0;

        if (no_of_cmds > 0) {
            // background execution
            if (line[strlen(line) - 1] == '&') {
                pid_t pid;
                pid = fork();
                background = true;

                if (pid != 0) {
                    goto start;
                }
            }
            for (cmd = parse_commands(line_copy, &saveptr); cmd != NULL; cmd = parse_commands(NULL, &saveptr)) {
                long repeat_command = 1;
                bool r_function = false;
                if (no_of_cmds - cmd_idx > 1) {
                    op = find_operator(line, cmd);
                }
                if (cmd_idx > 0 && cmd[0] == ' ') {
                    ++cmd;
                }

                // check if r or f function call
                if (cmd[0] == 'f') { // f followed by number in ascii else r followed by number in ascii
                    repeat_command = find_repeat_amount(cmd);
                    if (repeat_command >= 0) {
                        repeat_command = 0;
                        ret_val = true;
                    } else {
                        repeat_command = 1;
                    }
                } else if (cmd[0] == 'r') {
                    //convert ascii to number
                    repeat_command = find_repeat_amount(cmd);
                    if (repeat_command >= 0) {
                        cmd = trim_command(cmd);
                        r_function = true;
                    } else {
                        repeat_command = 1;
                    }
                }
                // parse args of the command
                args = parse_args(cmd);

                // check if command is exit
                if (strcmp(args[0], "exit") == 0 && run_command) {
                    exit(0);
                }

                // execute commands
                for (int i = 0; i < repeat_command && run_command; i++) {
                    ret_val = exec_command(args);
                }

                // consider all r function calls like success
                if (r_function) {
                    ret_val = true;
                }
                free(args);

                // check for && and ||
                if (++cmd_idx < no_of_cmds) {
                    if (ret_val == false) {
                        if (op == '&') {
                            run_command = false;
                        } else {
                            run_command = true;
                        }
                    } else {
                        if (op == '|') {
                            run_command = false;
                        } else {
                            run_command = true;
                        }
                    }
                } else {
                    free(line_copy);
                    free(line);
                    // kill process if it's a background command
                    if (background) {
                        exit(0);
                    }
                    break;
                }
            }
        } else { // No commands, we free the empty line and its copy
            free(line_copy);
            free(line);
        }
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