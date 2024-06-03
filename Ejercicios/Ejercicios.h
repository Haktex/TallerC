#ifndef EJERCICIOS_EJERCICIOS_H
#define EJERCICIOS_EJERCICIOS_H

#include <stdio.h>

void ej1();
void ej2();
void ej3();

#define PI 3.14
void ej4();
void ej5();
void ej6();

#include <math.h>
void ej7();
void ej8();
void ej9(int argc, char* argv[]);
void ej10();

#include <stdlib.h>
#include <string.h>
#define INITIAL_CAPACITY 3
int ej11();
#include <time.h>
void ej12();
void ej13();
void ej14();

struct estructura {
    int x;
    char a;
    float f;
};

extern struct estructura ejemplo_est;

void ej15();



#endif //EJERCICIOS_EJERCICIOS_H
