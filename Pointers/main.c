#include <stdio.h>
#include <stdlib.h>

void increment(int a) {
    a++;
}

void incrementPtr(int *ptr) {
    (*ptr)++;
}

int m_malloc(void); //Forward Declaration

int main(void) {
    int a = 0;
    int* p = &a; //p -> a
    printf("Direccion a la que apunta p:%p, valor de *p: %d\n", p, *p);
    printf("Valor original de a: %d\n", a);
    printf("Direccion de a: %p\n", &a);
    printf("Direccion de p: %p\n", &p);

    increment(a);
    printf("Valor nuevo de a: %d\n", a);

    incrementPtr(p);
    printf("Valor despues de incrementar con ptr: %d\n", a);

    m_malloc();

    return 0;
}

int m_malloc(void) {
    int n;
    int *array;

    printf("Especifica el numero de elementos a ingresar\n");
    scanf("%d",&n);

    array = (int*)malloc(n * sizeof(int)); //Asignamos memoria

    //Revisamos que se haya asignado exitosamente
    if (array == NULL) {
        printf("Fracaso en asignar memoria\n");
        return 1;
    }

    printf("Ingresa %d elementos\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Ingresaste\n");
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\nDireccion del arreglo es %p\n", array);//Igual a &array[0]
    printf("Direccion del primer elemento es %p\n", &array[0]);
    printf("Tercer elemento es %d\n", array[2]);
    printf("Direccion del tercer elemento es %p\n", &array[2]);

    //Liberamos memoria
    free(array );
}
