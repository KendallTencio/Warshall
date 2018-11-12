#include "warshall.h"

Warshall::Warshall()
{

}

string Warshall::ingresar(int numAIngresar, int tamDeLaMatriz)
{
    string resultado = "Ingrese numero de nodos: ";
    cout<<"Ingrese numero de nodos: ";
    int i,j;
    tamanioMatriz = tamDeLaMatriz;

    resultado += "Reservando memoria para matrices...";
    //Reservando la memoria para la matriz dinámica
    this->matrizWarshall = new int*[tamDeLaMatriz];
    for(i=0;i<tamDeLaMatriz;i++)
        this->matrizWarshall[i] = new int[tamDeLaMatriz];

    //Reservando la memoria para la matriz#2 dinámica
    this->matrizWarshall2 = new int*[tamDeLaMatriz];
    for(i=0;i<tamDeLaMatriz;i++)
        this->matrizWarshall2[i] = new int[tamDeLaMatriz];

    //Reservando memoria para los vectores auxiliares
    this->vect1 = new int[tamDeLaMatriz];
    this->vect2 = new int[tamDeLaMatriz];

    for(i=0;i<tamDeLaMatriz;i++)
        for(j=0;j<tamDeLaMatriz;j++){
            resultado += "Numero ingresado en posicion [i][j] : numAIngresar";
            cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
            *(*(this->matrizWarshall+i)+j) = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar<<endl;
        }
    return resultado;
}

void Warshall::ingresar(int numAIngresar)
{
    cout<<"Ingrese numero de nodos: ";
    int i,j;
    for(i=0;i<this->tamanioMatriz;i++)
        for(j=0;j<this->tamanioMatriz;j++){
            cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
            *(*(this->matrizWarshall+i)+j) = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar<<endl;
        }
}

void Warshall::nodointer()
{
    int i,j;
    for(i=0;i<this->tamanioMatriz;i++)
        for(j=0;j<this->tamanioMatriz;j++)
        {
            if(i==j)
                *(*(this->matrizWarshall2+i)+j)=0;
            else
                *(*(this->matrizWarshall2+i)+j)=j;
        }
}

void Warshall::algoritWarshall()
{
    int bucle,i,j,suma;
    for(bucle=0;bucle<this->tamanioMatriz;bucle++)
    {
        for(i=0;i<this->tamanioMatriz;i++)
        {
            this->vect1[i]=*(*(this->matrizWarshall+bucle)+i);
            this->vect2[i]=*(*(this->matrizWarshall+i)+bucle);
    }

        for(i=0;i<this->tamanioMatriz;i++)
            for(j=0;j<this->tamanioMatriz;j++)
            {
                if(getVect2(i) == 999 || getVect(i) == 999)
                    suma=999;
                else
                    suma=getVect2(i)+getVect(j);

                if(suma<*(*(this->matrizWarshall+i)+j))
                {
                    *(*(this->matrizWarshall+i)+j)=suma;
                    *(*(this->matrizWarshall2+i)+j)=bucle;
                }
            }
    }
}

void Warshall::mostrar1()
{
    int i,j;
    cout<<"Imprime distancias o pesos optimo: "<<endl;
    for(i=1;i<=this->tamanioMatriz;i++){
        for(j=1;j<=this->tamanioMatriz;j++)
        {
            cout<<*(*(this->matrizWarshall+i)+j);
        }
        cout<<endl;
    }
}

void Warshall::mostrar2()
{
    int i,j;
    cout<<"Imprime matriz intermedios: "<<endl;
    for(i=1;i<=this->tamanioMatriz;i++)
    {
        for(j=1;j<=this->tamanioMatriz;j++)
        {
            cout<<*(*(this->matrizWarshall2+i)+j);
        }
        cout<<endl;
    }
}

void Warshall::preguntar(int vertice1, int vertice2)
{
    cout<<"Del vertice: "<<vertice1<<endl;
    cout<<"Al vertice: "<<vertice2<<endl;
    if(vertice1==0 || vertice2==0 || vertice1==vertice2)
        cout<<"Distancia minima es 0";
    else
    {
        cout<<"Distancia minima"<<endl;
        cout<<*(*(this->matrizWarshall+vertice1)+vertice2)<<endl;
        cout<<"Pasa por el "<<*(*(this->matrizWarshall2+vertice1)+vertice2)<<" y despues por el "<<vertice2<<endl;
    }
}

void Warshall::setVect(int indice, int numSet){
    this->vect1[indice] = numSet;
}

void Warshall::setVect2(int indice, int numSet){
    this->vect2[indice] = numSet;
}

int Warshall::getVect(int indice){
    return this->vect1[indice];
}

int Warshall::getVect2(int indice){
    return this->vect2[indice];
}
