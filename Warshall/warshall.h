#ifndef WARSHALL_H
#define WARSHALL_H

#include<iostream>
#include<conio.h>

using namespace std;

class Warshall
{
    int n;
    int tamanioMatriz = 0;
    int **matrizWarshall;
    int **matrizWarshall2;
    int A[10][10];
    int *vect1;
    int *vect2;
    int B[10][10];

    public:
        Warshall();
        void ingresar(int numAIngresar);
        void ingresar(int numAIngresar, int tamDeLaMatriz);
        void nodointer();
        void algoritWarshall();
        void mostrar1();
        void mostrar2();
        void preguntar(int vertice1, int vertice2);

};

#endif // WARSHALL_H
