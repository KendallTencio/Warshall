#include "warshall.h"

Warshall::Warshall()
{

}

void Warshall::ingresar(int numAIngresar, int tamDeLaMatriz)
{
    cout<<"Ingrese numero de nodos: ";
    int i,j;
    for(i=1;i<=tamDeLaMatriz;i++)
        for(j=1;j<=tamDeLaMatriz;j++){
            cout<<"Ingrese número en posición de la matriz de ["<<i<<"]["<<j<<"] :";
            A[i][j] = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar;
            break;        }
}

void Warshall::nodointer()
{
    int i,j;
    for(i=1;i<=6;i++)
        for(j=1;j<=6;j++)
        {
            if(i==j)
                B[i][j]=0;
            else B[i][j]=j;}
}

void Warshall::floid()
{
    int bucle,i,j,suma;
    for(bucle=1;bucle<=n;bucle++)
    {
        for(i=1;i<=n;i++)
        {
            vect1[i]=A[bucle][i];
            vect2[i]=A[i][bucle];
    }

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(vect2[i]==999 || vect1[j]==999)
                    suma=999;
                else
                    suma=vect2[i]+vect1[j];

                if(suma<A[i][j])
                {
                    A[i][j]=suma;
                    B[i][j]=bucle;
                }
            }
    }
}

void Warshall::mostrar1()
{
    int i,j;
    cout<<"Imprime distancias o pesos optimo: "<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }
}

void Warshall::mostrar2()
{
    int i,j;
    cout<<"Imprime matriz intermedios: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<B[i][j];
        }
        cout<<endl;
    }
}

void Warshall::preguntar()
{
    int i,j;
    cout<<"De que vertice a que vertice desea ir : "<<endl;
    cout<<"Del vértice: "<<endl;
    cin>>i;
    cout<<"Al vértice: "<<endl;
    cin>>j;
    if(i==0 || j==0 || i==j)
        cout<<"Distancia minima es 0";
    else
    {
        cout<<"Distancia minima"<<endl;
        cout<<A[i][j]<<endl;
        cout<<"Pasa por el "<<B[i][j]<<" y despues por el "<<j<<endl;
    }
    getch();
}
