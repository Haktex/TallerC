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

struct empData {
    char name[20];
    char last[20];
    int id;
};
struct empProf {
    struct empData emp1;
    struct empData emp2;
};
extern struct empProf empleados;

void ej15();

#define LOWER 0
#define UPPER 300
#define STEP 20
void ej16();
void ej17();

#endif //EJERCICIOS_EJERCICIOS_H
