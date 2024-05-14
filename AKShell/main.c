#include <stdio.h> //printf(), fprintf(), stderr, getchar(), perror()
#include <sys/wait.h> //waitpid() + macros
#include <unistd.h> //chdir(), fork(), exec(), pid_t
#include <stdlib.h> //malloc(), //realloc(), free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> //strcmp(), strtok()

void akSh_loop(void);

int main(void) {
    akSh_loop();
    return EXIT_SUCCESS;
}

#define AKSH_TOK_BUFSIZE 64
#define AKSH_TOK_DELIM " \t\r\n\a"
char** akSh_split_line(char *line) {
    int bufSize = AKSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufSize * sizeof(char*));
    char *token;

    if(!tokens) {
        fprintf(stderr, "akSh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, AKSH_TOK_DELIM);
    while(token != NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufSize) {
            bufSize += AKSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufSize * sizeof(char*));
            if(!tokens) {
                fprintf(stderr, "akSh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL,AKSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

#define AKSH_RL_BUFSIZE 1024
char* akSh_read_line(void) {
    int c;
    int position = 0;
    int bufSize = AKSH_RL_BUFSIZE;
    char* buffer = malloc(sizeof(char) * bufSize);

    if(!buffer) {
        fprintf(stderr, "akSh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar(); //Read char

        if (c == EOF || c == '\n') { //If EOF replace with null and return
            buffer[position] = '\0';
            return buffer;
        } else
            buffer[position] = c;
        position++;

        if(position >= bufSize) { //If buffer exceeded, reallocate
            bufSize += AKSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufSize);
            if(!buffer) {
                fprintf(stderr, "akSh: allocation error \n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void akSh_loop(void) {
    int status;
    char* line;
    char** args;

    do {
        printf("O| ");
        line = akSh_read_line();
        args = akSh_split_line(line);
        status = akSh_execute(args);

        free(line);
        free(args);
    } while(status);
}
