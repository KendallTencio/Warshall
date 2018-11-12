#include "warshall.h"

Warshall::Warshall()
{

}

void Warshall::ingresar(int numAIngresar, int tamDeLaMatriz)
{
    cout<<"Ingrese numero de nodos: ";
    int i,j;
    tamanioMatriz = tamDeLaMatriz;

    //Reservando la memoria para la matriz dinámica
    matrizWarshall = new int*[tamDeLaMatriz];
    for(i=0;i<tamDeLaMatriz;i++)
        matrizWarshall[i] = new int[tamDeLaMatriz];

    //Reservando la memoria para la matriz#2 dinámica
    matrizWarshall2 = new int*[tamDeLaMatriz];
    for(i=0;i<tamDeLaMatriz;i++)
        matrizWarshall2[i] = new int[tamDeLaMatriz];

    //Reservando memoria para los vectores auxiliares
    vect1 = new int[tamDeLaMatriz];
    vect2 = new int[tamDeLaMatriz];

    for(i=0;i<tamDeLaMatriz;i++)
        for(j=0;j<tamDeLaMatriz;j++){
            cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
            *(*(matrizWarshall+i)+j) = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar<<endl;
        }
}

void Warshall::ingresar(int numAIngresar)
{
    cout<<"Ingrese numero de nodos: ";
    int i,j;
    for(i=0;i<tamanioMatriz;i++)
        for(j=0;j<tamanioMatriz;j++){
            cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
            *(*(matrizWarshall+i)+j) = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar<<endl;
        }
}

void Warshall::nodointer()
{
    int i,j;
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
        {
            if(i==j)
                *(*(matrizWarshall2+i)+j)=0;
            else
                *(*(matrizWarshall2+i)+j)=j;
        }
}

void Warshall::algoritWarshall()
{
    int bucle,i,j,suma;
    for(bucle=0;bucle<n;bucle++)
    {
        for(i=0;i<n;i++)
        {
            vect1[i]=*(*(matrizWarshall+bucle)+i);
            vect2[i]=*(*(matrizWarshall+i)+bucle);
    }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(vect2[i]==999 || vect1[j]==999)
                    suma=999;
                else
                    suma=vect2[i]+vect1[j];

                if(suma<*(*(matrizWarshall+i)+j))
                {
                    *(*(matrizWarshall+i)+j)=suma;
                    *(*(matrizWarshall2+i)+j)=bucle;
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
            cout<<*(*(matrizWarshall+i)+j);
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
            cout<<*(*(matrizWarshall2+i)+j);
        }
        cout<<endl;
    }
}

void Warshall::preguntar(int vertice1, int vertice2)
{
    cout<<"De que vertice a que vertice desea ir : "<<endl;
    cout<<"Del vertice: "<<vertice1<<endl;
    cout<<"Al vertice: "<<vertice2<<endl;
    if(vertice1==0 || vertice2==0 || vertice1==vertice2)
        cout<<"Distancia minima es 0";
    else
    {
        cout<<"Distancia minima"<<endl;
        cout<<*(*(matrizWarshall+vertice1)+vertice2)<<endl;
        cout<<"Pasa por el "<<*(*(matrizWarshall2+vertice1)+vertice2)<<" y despues por el "<<vertice2<<endl;
    }
}
