#include <stdio.h> //printf(), fprintf(), stderr, getchar(), perr()
#include <stdlib.h> //malloc(), //realloc(), //free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> //strtok()
#include <unistd.h> //chdir(), fork(), exec(), pid_t
#include <sys/wait.h> //waitpid(), MACROS

int akSh_cd(char **args);
int akSh_help(char **args);
int akSh_exit(char **args);
void akSh_loop(void);

char* builtIn_str[] = {
        "cd",
        "help",
        "exit"
};

int (*builtIn_func[]) (char**) = {
        &akSh_cd,
        &akSh_help,
        &akSh_exit
};

int main(void) {
    akSh_loop();
    return EXIT_SUCCESS;
}

int akSh_num_builtIns() {
    return sizeof(builtIn_str) / sizeof(char*);
}

int akSh_cd(char** args) {
    if(args[1] == NULL) {
        fprintf(stderr, "aksh: se espera un argumento para \"cd\"\n");
    } else if (chdir(args[1]) != 0)
        perror("aksh: Directorio Invalido");
    return 1;
}

int akSh_help(char** args) {
    printf("Artek Shell\n");
    printf("Ingresa el programa y argumento, despues presiona enter\n");
    printf("Estos son nuestros built-ins:\n");

    for(int i = 0; i < akSh_num_builtIns(); i++)
        printf(" %s\n", builtIn_str[i]);

    printf("Usa man para obtener informacion sobre otros programas\n");
    return 1;
}

int akSh_exit(char** args) {
    return 0;
}

#define AKSH_RBUFFER_SIZE 1024
char* akSh_read() {
    int c;
    int position = 0;
    int bufSize = AKSH_RBUFFER_SIZE;

    char* buffer = malloc(sizeof(char) * bufSize);
    if(!buffer) {
        fprintf(stderr, "akSH: no se pudo asignar la memoria para la linea");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();
        if(c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else
            buffer[position] = c;
        position++;

        if(position >= bufSize) {
            bufSize += AKSH_RBUFFER_SIZE;
            buffer = realloc(buffer, bufSize);
            if(!buffer) {
                fprintf(stderr, "akSH: no se pudo reasignar la memoria para la linea");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define AKSH_TBUFFER_SIZE 64
#define AKSH_TDELIM " \t\r\n\a"
char** akSh_parse(char* line) {
    int bufSize = AKSH_TBUFFER_SIZE, position = 0;
    char* token;
    char** tokens = malloc(bufSize * sizeof(char*));

    if(!tokens) {
        fprintf(stderr, "akSH: no se pudo asignar la memoria para el token");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, AKSH_TDELIM);

    while(token != NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufSize) {
            bufSize += AKSH_TBUFFER_SIZE;
            tokens = realloc(tokens, bufSize*sizeof(char*));
            if(!tokens) {
                fprintf(stderr, "akSH: no se pudo reasignar la memoria para el token");
            }
        }
        token = strtok(NULL, AKSH_TDELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int akSh_launch(char** args) {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if(pid == 0) {
        if(execvp(args[0], args) == -1)
            perror("Error ay execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error Forking");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int akSh_exec(char** args) {
    if(args[0] == NULL)
        return 1;

    for (int i = 0; i < akSh_num_builtIns(); i++) {
        if (strcmp(args[0], builtIn_str[i]) == 0)
            return (*builtIn_func[i])(args);
    }
    return akSh_launch(args);
}

void akSh_loop(void) {
    int status;
    char* line;
    char** args;

    do {
        printf("O| ");

        line = akSh_read();
        args = akSh_parse(line);
        status = akSh_exec(args);

        free(line);
        free(args);
    } while(status);
}
