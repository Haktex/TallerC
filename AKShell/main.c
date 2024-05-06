#include <stdio.h> //printf(), fprintf(), stderr, getchar(), perror()
#include <sys/wait.h> //waitpid() + macros
#include <unistd.h> //chdir(), fork(), exec(), pid_t
#include <stdlib.h> //malloc(), //realloc(), free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> //strcmp(), strtok()

#define AKSH_RL_BUFSIZE 1024
#define AKSH_TOK_BUFSIZE 64
#define AKSH_TOK_DELIM " \t\r\n\a"

//Forward Function declaration of Built In Commands
int akSh_cd(char **args);
int akSh_help(char **args);
int akSh_exit(char **args);
void akSh_loop(void);

//Builtin Commands Array:
char *builtIn_str[] = {
        "cd",
        "help",
        "exit"
};

//Command Function Array:
int (*builtIn_func[]) (char **) = {
        &akSh_cd,
        &akSh_help,
        &akSh_exit
};

int main(void) {
    akSh_loop();
    return EXIT_SUCCESS;
}

int akSh_num_builtins() {
    return sizeof(builtIn_str) / sizeof(char*);
}

int akSh_cd(char **args) {
    if(args[1] == NULL) {
        fprintf(stderr, "aksh: expected argument to \"cd\"n");
    } else if (chdir(args[1]) != 0)
            perror("Invalid directory");
    return 1;
}

int akSh_help(char **args) {
    printf("Artek Shell\n");
    printf("Type program and argument, then hit enter\n");
    printf("The following commands are built in:\n");

    for(int i = 0; i < akSh_num_builtins(); i++)
        printf(" %s\n", builtIn_str[i]);

    printf("Use man for info on other programs\n.");
    return 1;
}

int akSh_exit(char **args) {
    return 0;
}

int akSh_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if(pid == 0) { //Child Process
        if(execvp(args[0], args) == -1)
            perror("Error at execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error Forking");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int akSh_execute(char **args) {
    if (args[0] == NULL) //Empty command
        return 1;

    for (int i = 0; i < akSh_num_builtins(); i++) {
        if (strcmp(args[0], builtIn_str[i]) == 0)
            return (*builtIn_func[i])(args);
    }
    return akSh_launch(args);
}

char *akSh_read_line(void) {
    int c;
    int position = 0;
    int bufSize = AKSH_RL_BUFSIZE;
    char *buffer = malloc(sizeof(char) * bufSize);

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

char **akSh_split_line(char *line) {
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

void akSh_loop(void) {
    int status;
    char *line;
    char **args;

    do {
        printf("> ");
        line = akSh_read_line();
        args = akSh_split_line(line);
        status = akSh_execute(args);

        free(line);
        free(args);
    } while(status);
}