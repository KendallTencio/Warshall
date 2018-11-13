#include "warshall.h"

#include <QMainWindow>

//Código fuertemente influenciado y basado en el encontrado en: https://xcodigoinformatico.blogspot.com/2012/09/probado-en-codeblocks-y-dev-cpp-como.html

Warshall::Warshall()
{

}

string Warshall::generarMatrizVacia(int tamDeLaMatriz)
{
    string resultado = "Construyendo matrices...\n";
    cout<<"Ingrese numero de nodos: ";
    int numAIngresar;
    int i,j;
    tamanioMatriz = tamDeLaMatriz;

    resultado += "Reservando memoria para matrices...\n";
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
        for(j=0;j<tamDeLaMatriz;j++)
        {
            //MessageBoxA(("¿Guardar el fichero?","Guardar como",MB_OK) == IDOK);
            numAIngresar = rand() % 100;
            if(i == j)
            {
                resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(0)+"\n";
                cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
                *(*(this->matrizWarshall+i)+j) = 0;
                cout<<"Numero ingresado: "<<0<<endl;
                continue;
            }
            resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(numAIngresar)+"\n";
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
        for(j=0;j<this->tamanioMatriz;j++)
        {
            cout<<"Ingrese numero en posicion de la matriz de ["<<i<<"]["<<j<<"] :"<<endl;
            *(*(this->matrizWarshall+i)+j) = numAIngresar;
            cout<<"Numero ingresado: "<<numAIngresar<<endl;
        }
}

string Warshall::dibujarMatriz()
{
    string matrizString = "";
    int j, i;
    for(i=0;i<this->tamanioMatriz;i++)
    {
        matrizString += "\n";
        for(j=0;j<this->tamanioMatriz;j++)
            matrizString += "|"+to_string(*(*(this->matrizWarshall+i)+j))+"|";
    }
    return matrizString;

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
                if(getVect2(i) == 99 || getVect(i) == 99) //Infinito
                    suma=99;
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
    for(i=0;i<this->tamanioMatriz;i++)
    {
        for(j=0;j<this->tamanioMatriz;j++)
        {
            cout<<*(*(this->matrizWarshall+i)+j);
        }
        cout<<endl;
    }
}

string Warshall::mostrar2()
{
    string resultado = "";
    int i,j;
    cout<<"Imprime matriz intermedios: "<<endl;
    for(i=0;i<this->tamanioMatriz;i++)
    {
        resultado += "\n";
        for(j=0;j<this->tamanioMatriz;j++)
        {
            resultado += "|"+to_string(*(*(this->matrizWarshall2+i)+j))+"|";
            cout<<*(*(this->matrizWarshall2+i)+j);
        }
        cout<<endl;
    }
    return resultado;
}

string Warshall::preguntar(int vertice1, int vertice2)
{
    string resultado = "";
    resultado += "\nDel vertice: "+to_string(vertice1);
    resultado += "\nAl vertice: "+to_string(vertice2);
    cout<<"\nDel vertice: "<<vertice1<<endl;
    cout<<"Al vertice: "<<vertice2<<endl;
    if(vertice1==0 || vertice2==0 || vertice1==vertice2)
    {
        resultado += "\nDistancia mínima es 0";
        cout<<"\nDistancia minima es 0";
    }
    else
    {
        resultado += "\nDistancia mínima: "+ to_string(*(*(this->matrizWarshall+vertice1)+vertice2));
        resultado += "\nPasa por el " + to_string(*(*(this->matrizWarshall2+vertice1)+vertice2)) + " y después por el " + to_string(vertice2);
        cout<<"Distancia minima"<<endl;
        cout<<*(*(this->matrizWarshall+vertice1)+vertice2)<<endl;
        cout<<"Pasa por el "<<*(*(this->matrizWarshall2+vertice1)+vertice2)<<" y despues por el "<<vertice2<<endl;
    }
    return resultado;
}

void Warshall::setVect(int indice, int numSet)
{
    this->vect1[indice] = numSet;
}

void Warshall::setVect2(int indice, int numSet)
{
    this->vect2[indice] = numSet;
}

int Warshall::getVect(int indice)
{
    return this->vect1[indice];
}

int Warshall::getVect2(int indice)
{
    return this->vect2[indice];
}
