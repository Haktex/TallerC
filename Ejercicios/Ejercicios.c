#include "Ejercicios.h"

void ej17() {
    /*
    int nc;
    for(nc = 0; getchar() != EOF; ++nc);
    printf("%d\n",nc);
    printf("%d", EOF);
     */

    int c, nl = 0, nt = 0, ns = 0, i = 0;


    while((c = getchar()) != EOF) {
        switch(c) {
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            case '\t':
                putchar('\\');
                putchar('t');
                ++nt;
                break;
            case '\n':
                putchar('\\');
                putchar('n');
                ++nl;
                break;
            case ' ':
                putchar('1');
                ++ns;
                break;
            default:
                putchar(c);
                break;
        }
    }
    printf("\n%d %d %d\n", nl, nt, ns);
}

void ej16() {
        int fahr;
        /*
        float celsius;

        fahr = LOWER;

        while(fahr <= UPPER) {
            celsius = (5.0/9.0) * (fahr - 32);
            printf("%3d%10.3f\n",fahr,celsius);
            fahr += STEP;
        }
         */
        for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
            printf("%3d%10.3f\n",fahr,(5.0/9.0) * (fahr-32));
}

void ej15() {
    struct empProf empleados;

    for(int i = 0; i < 2; i++) {
        struct empData* empleado = &empleados.emp1;
        if (i > 0)
            empleado = &empleados.emp2;

        printf("Ingresa el nombre del empleado %d: ", i + 1);
        scanf("%s",empleado->name);

        printf("Ingresa el apellido del empleado %d: ", i + 1);
        scanf("%s",empleado->last);

        printf("Ingresa el ID del empleado %d: ", i + 1);
        scanf("%d",&empleado->id);
    }

    for(int i = 0; i < 2; i++) {
        struct empData* empleado = &empleados.emp1;
        if (i > 0)
            empleado = &empleados.emp2;

        printf("Informacion de empleado para %s %s\n", empleado->name, empleado->last);
        printf("ID: %d\n", empleado->id);
    }
}

void ej14() {
    int x = 10;
    int* p = &x;

    printf("El valor de x es: %d\n", x);
    printf("El valor del apuntador a x es: %p\n", p);
    printf("La direccion de memoria de x es: %p\n", &x);
    printf("El valor en la direccion al que apunta el apuntador es: %d\n", *p);
}

void ej13() {

    int player[4][5];
    int w;

    for(int i = 0; i < 4; i++) {
        printf("Juego %d:\n",i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Ingresa un puntuaje para el juegador %d ", j + 1);
            scanf(" %d",&player[i][j]);
        }
    }

    int curr = 0;
    for(int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += player[j][i];
            if(curr < sum) {
                curr = sum;
                w = i + 1;
            }
        }
    }

    printf("El jugador %d tuvo el mejor promedio con %.2f puntos por juego.\n", w, (float)curr / 4);
}

void ej12() {
    int x,a = 0,s = 0;
    time_t t;

    printf("Ingresa el numero de veces a lanzar la moneda: ");
    scanf("%d", &x);

    srand((unsigned)time(&t));

    for(int i = 0; i < x;i++)
        rand() % 2 == 1 ? a++:s++;

    printf("Despues de lanzar la moneda 5000 veces, los resultados fueron:\n");
    printf("%d aguila\n", a);
    printf("%d sol", s);
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

    return 0;
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
    solution1 = (-b + sqrt((b*b)-(4*a*c))) / (2*a);
    solution2 = (-b - sqrt((b*b)-(4*a*c))) / (2*a);

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
