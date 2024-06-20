#include <stdio.h>
#include "alloc.h"

int main(void) {
    int* arr = (int*)malloc(10 * sizeof(int));

    if(arr) {
        for(int i = 0; i < 10; i++)
            arr[i] = i * i;

        for(int i = 0; i < 10; i++)
            printf("%d ", arr[i]);

        printf("\n");
    } else
        printf("malloc fracaso");

    free(arr);

    arr = (int*) calloc(10, sizeof(int));

    if(arr) {
        for (int i = 0; i < 10; i++)
            printf("%d ", arr[i]);

        printf("\n");
    } else
        printf("calloc fracaso");

    free(arr);

    arr = (int*)malloc(5 * sizeof(int));

    if (arr) {
        for (int i = 0; i < 5; i++)
            arr[i] = i * 10;

        printf("Antes de realloc: ");

        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);

        printf("\n");

        arr = (int*)realloc(arr, 10 * sizeof(int));

        if (arr) {
            printf("Despues de realloc: ");

            for (int i = 0; i < 10; i++)
                printf("%d ", arr[i]);

            printf("\n");

            for (int i = 5; i < 10; i++)
                arr[i] = i * 10;

            printf("Despues de realloc 2: ");

            for (int i = 0; i < 10; i++)
                printf("%d ", arr[i]);

            printf("\n");
        } else
            printf("realloc fracaso\n");
    } else
        printf("malloc para realloc fracaso\n");

    free(arr);

    return 0;
}
