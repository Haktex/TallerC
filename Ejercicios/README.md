1. Imprime "Hola Artek".
---
2. Inicializa y asigna valores a un entero, flotante, y caracter. Imprimer cada uno con una oracion que los describa:
```
10 es - un entero
3.14 - es un flotante
Hola - es un arreglo de caracteres 
```
---
3. Pide al usuario su primer y segundo nombre para imprimir un mensaje de bienvenida. Almacena el input comoo un caracter.
   1. Asigna una cantidad arbitraria de indices a tu arreglo de caracteres.

   2. Asigna de forma dynamica el tamaño del arreglo dependiendo del input del usuario.
---
4. Pide al usuario ingresar el tamaño de un radio e imprime con eso el area de un circulo.
   1. Utiliza la directiva #define para asignar 3.14 a PIE
   2. Imprime unicamente 3 digitos despues del punto decimal
```bash
Ingresa el radio de un circulo: 5
El area de tu circulo es: 75.539
```
---
5. Pide al usuario ingresar un numero de segundos y conviertelo a horas, minutos y segundos restantes.
   1. Asegurate de no imprimir con decimales.
```bash
Ingresa una cantidad de segundos: 18550
18550 segundos es igual a 5 horas, 9 minutos, y 10 segundos. 
```
---
6. Pide al usuario un numerador y un denominador para indicarle si hay o no hay un valor restante utilizando if.
```Bash
Ej 1:
Ingresa un numerador: 24
Ingresa un denominador: 8
No hay un valor restante.
Ej 2:
Ingresa un numerador: 52
Ingrea un denominador: 9
Resta: 7
```
---
7. Pidele al usuario los valores A, B, y C; usalos para determinar el valor de `X` utilizando la formula cuadratica.
   1. Puedes utilizar math.h
   2. Revisa si la solucion es correcta ingresando la solucion en la formula para ver si es igual a `0`.
   3. Utiliza un 'if' que compruebe si es igual a 0, de lo contrario, propon revisarlo
```bash
Ej. 1:
Ingresa el valor de A: 1
Ingresa el valor de B: 5
Ingresa el valor de C: 6
La solucion usando + es: -2.000
La solucion usando - es: -3.000
Ej.2:
Ingresa el valor de A: -9
Ingresa el valor de B: 5
Ingresa el valor de C: 2
La solucion usando + es: -0.269
La solucion usando - es: 0.824, pero deberias confirmarlo
```
---
8. Pidele al usuario un numero entre 1 y 500 y determina si se encuentra dentro de los siguientes rangos:
   - 1-100
   - 101-200
   - 201-300
   - 301-400
   - 401-500
```bash
Ej 1:
Ingresa un numero entre 1 y 500: 50
Tu numero esta netre 1 y 100.
Ej 2:
Ingresa un numero entre 1 y 500: 250
Tu numero esta netre 201 y 300.
```
---
9. Toma dos arguentos desde la linea de comandos - su primer y segundo nombre, para imprimir un mensaje de bienvenida. El programa deber revisar si hay dos argumentos para dar instrucciones en caso de que el usuario ingrese una cantidad erronea.
```bash
Ej 1:
usuario:~/TallerC/ # ./ejercicio9
Uso: ./ejercicio9 PrimerNombre SegundoNombre
Ej 2:
usuario:~/TallerC/ # ./ejercicio9 Optimus Prime
Hola, Optimus Prime
Ej 3:
usuario:~/TallerC/ # ./ejercicio9 Smaug The Tremendous
Uso: ./ejercicio9 PrimerNombre SegundoNombre
```
---
10. Crea un arreglo de 10 enteros e imprime el numero de elementos en el arreglo. 
    1. Imprime el tamaño en bytes del arreglo y de cada elemento en el arreglo.
```bash
El arreglo tiene 10 elementos.
El tamaño en bytes de cada elemento es 4.
El tamaño en bytes del arreglo es 40.
```
---
11. (En Clase) Pide al usuario ingresar calificaciones the manera continua, preguntando en cada instancia si quiere continuar o no. Almacena los resultados y calcula el promedio de su puntuaje al terminar el programa. 
    1. Inicializa tu arreglo con 10 y limita el numero de entradas a 2.
    2. Imprime el promedio de la califiacion con dos lugares decimales.
    3. Utiliza un `while`, un `for`, y `strcmp()`.
```bash
Ingresa una calificacion: 90
Quieres continuar? Y/N Y
Ingresa una calificacion: 75
Quieres continuar? Y/N Y
Ingresa una calificacion: 99
Quieres continuar? Y/N N
Tu promedio es: 88
```
