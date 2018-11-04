#ifndef WARSHALL_H
#define WARSHALL_H

#include<iostream>
#include<conio.h>

using namespace std;

class Warshall
{
    int n;
    int A[10][10];
    int vect1[10];
    int vect2[10];
    int B[10][10];

    public:
        Warshall();
        void ingresar();
        void nodointer();
        void floid();
        void mostrar1();
        void mostrar2();
        void preguntar();

};

#endif // WARSHALL_H
