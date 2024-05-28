#include "Ejercicios.h"

int ej12() {

}

int ej11() {
    double *scores = malloc(INITIAL_CAPACITY * sizeof(double));
    if(!scores)
    {
        fprintf(stderr, "No se pudo asignar memoria.\n");
        return 1;
    }

    int capacity = INITIAL_CAPACITY;
    char answer[] = "y";
    int numScores = 0;

    do {
        if(numScores == capacity)
        {
            capacity *= 2;
            scores = realloc(scores, capacity * sizeof(double));
            if(!scores)
            {
                fprintf(stderr, "No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        printf("Ingresa una calificacion: ");
        scanf("%lf", &scores[numScores]);

        numScores++;

        printf("Deseas continuar? y/n ");
        scanf("%s", &answer);

    } while(!strcmp(answer, "n") ? 0 : !strcmp(answer, "N") ? 0 : !strcmp(answer, "y") ? printf("Continuando\n") : !strcmp(answer, "Y") ? printf("Continuando\n") : printf("Interpretando como Y\n"));

    double sum = 0;

    for(int i = 0; i < numScores; i++)
        sum += scores[i];

    printf("el promedio es %.2f.\n", sum / numScores);

    free(scores);
}

void ej10() {
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    printf("El arreglo tiene %d elementos.\n",sizeof(array) / sizeof(array[0]));
    printf("El tamaño en bytes de cada elemento es %d.\n",sizeof(array[0]));
    printf("El tamaño en bytes del arreglo es %d.\n",sizeof(array));
}

void ej9(int argc, char* argv[]) {
    if(argc < 3 || argc > 3)
        printf("Uso: ./Ejercicios PrimerNombre SegundoNombre");
    else
        printf("Hola, %s %s", argv[1], argv[2]);
}

void ej8() {
    int input;

    printf("Ingresa un numero entre 1 y 500: ");
    scanf("%d", &input);

    if (input >= 0 && input <= 100)
        printf("Tu numero esta entre 1 y 100!");

    else if (input >= 101 && input <= 200)
        printf("Tu numero esta entre 101 y 100!");

    else if (input >= 201 && input <= 300)
        printf("Tu numero esta entre 201 y 300!");

    else if (input >= 301 && input <= 400)
        printf("Tu numero esta entre 301 y 400!");

    else if (input >= 401 && input <= 500)
        printf("Tu numero esta entre 401 y 500!");

    else
        printf("Tu numero no esta dentro de los rangos disponibles.");
}

void ej7() {
    float a,b,c;
    printf("Ingresa el valor de \'A\': ");
    scanf("%f", &a);
    printf("Ingresa el valor de \'B\': ");
    scanf("%f", &b);
    printf("Ingresa el valor de \'C\': ");
    scanf("%f", &c);

    float solution1, solution2;
    solution1 = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
    solution2 = (-b - sqrt((b*b)-(4*a*c)))/(2*a);

    if (((a*(solution1*solution1)) + (b*solution1) + c) == 0)
        printf("La solucion usando '+' es: %.2f\n", solution1);
    else
        printf("La solucion usando '+' es: %.2f, pero deberias confirmarlo...\n", solution1);

    if (((a*(solution2*solution2)) + (b*solution2) + c) == 0)
        printf("La solucion usando '-' es: %.2f\n", solution2);
    else
        printf("La solucion usando '-' es: %.2f, pero deberias confirmarlo...\n", solution2);
}

void ej6() {
    int numerador, denominador;
    printf("Ingresa un numerador: ");
    scanf("%d", &numerador);
    printf("Inrgesa un denominador: ");
    scanf("%d", &denominador);

    if (numerador % denominador == 0)
        printf("No hay un valor restante remainder!");
    else
        printf("Resta: %d",numerador % denominador);
}

void ej5() {
    int sec, hor, min, r_sec;

    printf("Ingresa la cantidad de segundos: ");
    scanf("%d", &sec);

    hor = sec / 3600;

    min = (sec % 3600)/60;

    r_sec = (sec % 3600)%60;
    printf("%d segundos es igual a %d horas, %d minutos, y %d segundos.", sec, hor, min, r_sec);
}

void ej4() {
    float radio;

    printf("Ingresa el radio de un circulo: ");
    scanf("%f", &radio);

    float area;
    area = PI * (radio * radio);

    printf("El area de tu circulo es %.2f", area);
}

void ej3() {
    char firstS[20];
    char lastS[20];

    char *firstD;
    char *lastD;

    printf("Ingresa tu primer nombre: ");
    scanf("%ms", &firstD);

    int i;
        for (i = 0; firstD[i] != '\0'; i++)
        firstS[i] = firstD[i];

    firstS[i] = '\0';

    printf("Ingresa tu ultimo nombre: ");
    scanf("%ms", &lastD);

    for (i = 0; lastD[i] != '\0'; i++)
        lastS[i] = lastD[i];

    lastS[i] = '\0';

    printf("Hola (estatico) %s %s!\n", firstS, lastS);
    printf("Hola (dinamico) %s %s!\n", firstD, lastD);
}

void ej2() {
    int m_int = 10;
    float m_float = 3.14;
    char m_string[] = "Hola";

    printf("%d es un entero\n", m_int);
    printf("%.2f es un flotante\n", m_float);
    printf("\"%s\" es un arreglo de caracteres que termina en '\\0'\n", m_string);
}

void ej1() {
    printf("Hola, Artek!\n");
}
