#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n);

int elevar(int base, int exponente);

void mostrarArreglo(int inicio, int arreglo[], int final);

void mostrarArregloInvertido(int posicion, int arreglo[], int validos);

int esCapicua(int validos, int arreglo[validos], int iteracion);

int sumarArreglo(int iteracion, int arreglo[], int validos);

int buscarMenor(int inicio, int arreglo[], int validos);

void escribirArregloEnArchivo(int arreglo[], int validos);

int buscarMenorDeArchivo(int validos);

int realizarBusqueda(FILE * archivo,int validos,int indice);

int main() {
    srand(time(NULL));

    ///Ejercicio 1
//    int n = rand()%10;
//    printf("n = %d\n",n);
//    printf("n! = %d\n", factorial(n));

    ///Ejercicio 2
//    int base = rand()%5;
//    int exponente = rand()%5;
//    printf("%d elevado a la %d es igual a: %d\n",base,exponente, elevar(base,exponente));

    int arreglo[5] = {1, 2, 3, 4, 5};
    int arregloRandom[5] = {rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10};

    ///Ejercicio 3
//    mostrarArreglo(0, arreglo, 5);

    ///Ejercicio 4
//    mostrarArregloInvertido(0,arreglo,5);

    ///Ejercicio 5
//    printf("El arreglo impar%s es capicua\n", esCapicua(5, arreglo, 0) ? " " : " no");
//    int arregloImparCapicua[5] = {1, 2, 3, 2, 1};
//    printf("El arreglo impar capicua%s es capicua\n", esCapicua(5, arregloImparCapicua, 0) ? " " : " no");
//    int arregloPar[4] = {1,2,3,4};
//    printf("El arreglo par%s es capicua\n", esCapicua(4, arregloPar, 0) ? " " : " no");
//    int arregloParCapicua[4] = {1,2,2,1};
//    printf("El arreglo par capicua%s es capicua\n", esCapicua(4, arregloParCapicua, 0) ? " " : " no");

    ///Ejercicio 6
//    printf(" La suman del arreglo: \n");
//    mostrarArreglo(0, arreglo, 5);
//    printf(" es igual a: %d\n", sumarArreglo(0, arreglo, 5));

    ///Ejercicio 7
//    printf(" El menor del arreglo:\n");
//    mostrarArreglo(0, arregloRandom, 5);
//    printf(" es: %d\n", buscarMenor(0, arregloRandom, 5));

    ///Ejercicio 8
    escribirArregloEnArchivo(arregloRandom, 5);
    mostrarArreglo(0,arregloRandom,5);
    printf("El menor del arreglo es: %d\n",buscarMenorDeArchivo(5));

    system("pause");
    return 0;
}

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int elevar(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else if (exponente == 1) {
        return base;
    } else {
        return base * elevar(base, exponente - 1);
    }
}

void mostrarArreglo(int inicio, int arreglo[], int final) {
    if (inicio < final) {
        printf(" [%d] ", arreglo[inicio]);
        mostrarArreglo(inicio + 1, arreglo, final);
    } else {
        printf("\n");
    }
}

void mostrarArregloInvertido(int posicion, int arreglo[], int validos) {
    if (posicion < validos) {
        mostrarArregloInvertido(posicion + 1, arreglo, validos);
        printf("[%d] ", arreglo[posicion]);
    }
    if (posicion == 0) printf("\n");
}

int esCapicua(int validos, int arreglo[], int iteracion) {
    if ((validos - iteracion - 1) <= iteracion) {
        return 1;
    } else if (arreglo[validos - iteracion - 1] == arreglo[iteracion]) {
        return esCapicua(validos, arreglo, iteracion + 1);
    } else {
        return 0;
    }
}

int sumarArreglo(int iteracion, int arreglo[], int validos) {
    return (iteracion < validos) ? arreglo[iteracion] + sumarArreglo(iteracion + 1, arreglo, validos) : 0;
}

int buscarMenor(int indice, int arreglo[], int validos) {
    if (indice < validos) {
        int minimo = buscarMenor(indice + 1, arreglo, validos);
        return minimo < arreglo[indice] ? minimo : arreglo[indice];
    } else {
        return arreglo[indice - 1];
    }
}

void escribirArregloEnArchivo(int arreglo[], int validos) {
    FILE *archivo = fopen("archivo.dat", "wb");
    fwrite(arreglo, sizeof(int), validos, archivo);
    fclose(archivo);
}

int buscarMenorDeArchivo(int validos){
    FILE* archivo = fopen("archivo.dat","rb");
    return realizarBusqueda(archivo,validos,0);
}

int realizarBusqueda(FILE * archivo,int validos,int indice){
    int valorActual = INT_MAX;
    fread(&valorActual, sizeof(int),1,archivo);
    if (indice < validos){
        int valorSiguiente = realizarBusqueda(archivo,validos,indice+1);
        return valorActual < valorSiguiente ? valorActual : valorSiguiente;
    } else {
        return valorActual;
    }
}