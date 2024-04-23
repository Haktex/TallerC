#include <stdio.h>
/*
 * 1. Utilicen un if  para alternar entre mandelbrot y julia con un bool GLOBAL
 * 2. Funcion que devueva el cuadrado de un parametro sqr(newR);
 * 3. Con Julia que el centro sea blanco y con mandel negro
 * 4. Que los valores constantes para el set de Julian sean variables globales y constantes
 * 5. Utilicen operador ternario para los ifs - puntos extra
*/

//Variables Globales Constantes
const int image_width = 500, image_height = 500; //Dimensiones de imagen

double map(int pix, int minIn, int maxIn, double minOut, double maxOut);

int main(void) {

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int i = 0; i < image_width; i++) {
        for (int j = 0; j < image_height; j++) {

            double startR = map(i, 0, image_width,-2, 2); // c
            double startI = map(j, 0, image_height,-2, 2); // c

            double newR = startR; //Real de Zn + 1 //Utilicen un if  para alternar entre mandelbrot y julia con un bool GLOBAL
            double newI = startI; //Imaginario de Zn + 1 //Utilicen un if  para alternar entre mandelbrot y julia con un bool GLOBAL

            int n = 0;
            while(n < 100) {
                double currR = newR * newR - newI * newI; //Real de Z^2 //funcion que devuelva el cuadrado de un parametro ej. sqr(newR);
                double currI = 2 * newR * newI; //Imaginario  de Z^2

                newR = currR + 0; //nuevo Zn + 1 //Utilicen un if  para alternar entre mandelbrot y julia con un bool GLOBAL
                newI = currI + 0.8; //nuevo Zn + 1 //Utilicen un if  para alternar entre mandelbrot y julia con un bool GLOBAL

                if(newR * newR + newI * newI > 4) //funcion que devuelva el cuadrado de un parametro, ej. sqr(newR);
                    break;

                n++;
            }

            double bright = map(n, 0, 100, 0, 255); //Con Julia que el centro sea blanco y con mandel negro

            printf("%d %d %d\n", (int)bright, (int)bright, (int)bright);
        }
    }

    return 0;
}

double map(int pix, int minIn, int maxIn, double minOut, double maxOut) {
    return (double)(pix - minIn) / (maxIn - minIn) * (maxOut - minOut) + minOut;
}