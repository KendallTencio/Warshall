#ifndef WARSHALL_H
#define WARSHALL_H

#include<iostream>
#include<windows.h>
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
        string generarMatrizVacia(int tamDeLaMatriz);
        void nodointer();
        void algoritWarshall();
        void mostrar1();
        string mostrar2();
        string preguntar(int vertice1, int vertice2);
        string dibujarMatriz();
        void setVect(int indice, int numSet);
        void setVect2(int indice, int numSet);
        int getVect(int indice);
        int getVect2(int indice);
};

#endif // WARSHALL_H
