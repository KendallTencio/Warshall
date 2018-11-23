#include "warshall.h"
#include <QMainWindow>

//Código fuertemente influenciado y basado en el algoritmo encontrado en: https://www.sanfoundry.com/cpp-program-implement-floyd-warshall-algorithm/

Warshall::Warshall()
{

}

string Warshall::generarMatrizVacia(int tamDeLaMatriz)
{
    string resultado = "Construyendo matrices...\n";
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
            numAIngresar = rand() % 2;
            if(i == j)
            {
                resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(0)+"\n";
                *(*(this->matrizWarshall+i)+j) = 0;
                continue;
            }
            resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(numAIngresar)+"\n";
            *(*(this->matrizWarshall+i)+j) = numAIngresar;
        }
    return resultado;
}

string Warshall::generarMatrizLista()
{
    //Corroborar con video: https://www.youtube.com/watch?v=9QV6QpyhN0o
    string resultado = "Construyendo matrices...\n";
    int numAIngresar;
    int matrizLista[] = {0,8,99,1,99,0,1,99,4,99,0,99,99,2,9,0};
    int i,j,k = 0;
    int tamDeLaMatriz = 4;
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
            numAIngresar = rand() % 2;
            resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(matrizLista[k])+"\n";
            *(*(this->matrizWarshall+i)+j) = matrizLista[k];
            k++;
        }
    return resultado;
}

string Warshall::generarMatrizConIngresos(int tamanioDeLaMatriz, int cadenaDeNumero)
{
    //Girar el número ingresado para que esté acorde a la matriz
    int numReserva = cadenaDeNumero;
    cadenaDeNumero = 0;
    do{
        cadenaDeNumero += numReserva % 10;
        cadenaDeNumero = cadenaDeNumero * 10;
        numReserva /= 10;
    }
    while (numReserva>0);
    cadenaDeNumero /= 10;

    string resultado = "Construyendo matriz...\n";
    int numAIngresar;
    int i,j;
    this->tamanioMatriz = tamanioDeLaMatriz;

    resultado += "Reservando memoria para matriz...\n";
    //Reservando la memoria para la matriz dinámica
    this->matrizWarshall = new int*[tamanioDeLaMatriz];
    for(i=0;i<tamanioDeLaMatriz;i++)
        this->matrizWarshall[i] = new int[tamanioDeLaMatriz];

    //Reservando la memoria para la matriz#2 dinámica
    this->matrizWarshall2 = new int*[tamanioDeLaMatriz];
    for(i=0;i<tamanioDeLaMatriz;i++)
        this->matrizWarshall2[i] = new int[tamanioDeLaMatriz];

    //Reservando memoria para los vectores auxiliares
    this->vect1 = new int[tamanioDeLaMatriz];
    this->vect2 = new int[tamanioDeLaMatriz];

    resultado += "Agregando diagonal de ceros...\n";
    for(i=0;i<tamanioDeLaMatriz;i++)
        for(j=0;j<tamanioDeLaMatriz;j++)
        {
            numAIngresar = cadenaDeNumero % 10;
            if(cadenaDeNumero == 0){
               return "Error en la matriz digitada\n1.Favor revise que indico la cantidad adecuada de números\n2.Gracias a que los 0 de la diagonal se colocan automáticamente\n, verifique que colocó números distintos de 0 a los lados de su cadena";
            }
            if(i == j)
            {
                resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(0)+"\n";
                *(*(this->matrizWarshall+i)+j) = 0;
                cadenaDeNumero = cadenaDeNumero / 10;
                continue;
            }
            resultado += "Numero ingresado en posicion ["+to_string(i)+"]["+to_string(j)+"] : "+to_string(numAIngresar)+"\n";
            *(*(this->matrizWarshall+i)+j) = numAIngresar;
            cadenaDeNumero = cadenaDeNumero / 10;
        }
    return resultado;
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

void Warshall::warshallFloyd()
{
    int i, j, k;
    for (k = 0; k < this->tamanioMatriz; k++)
    {
        for (i = 0; i < this->tamanioMatriz; i++)
            for (j = 0; j < this->tamanioMatriz; j++)
                if ((*(*(this->matrizWarshall+i)+k) * *(*(this->matrizWarshall+k)+j) != 0) && (i != j))
                    if (*(*(this->matrizWarshall+i)+k) + *(*(this->matrizWarshall+k)+j) < *(*(this->matrizWarshall+i)+j) || (*(*(this->matrizWarshall+i)+j) == 0))
                        *(*(this->matrizWarshall+i)+j) = *(*(this->matrizWarshall+i)+k) + *(*(this->matrizWarshall+k)+j);
        for (i = 0; i < this->tamanioMatriz; i++)
        {
            cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
            for (j = 0; j < this->tamanioMatriz; j++)
                cout<<*(*(this->matrizWarshall+i)+j)<<"\t";

        }
    }
}

void Warshall::warshallFloydThreads()
{
  //  Threads hilosPrueba;
 //   this->matrizWarshall = hilosPrueba.warshallFloydThreads(this->tamanioMatriz, this->matrizWarshall);
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

string Warshall::mostrar1()
{
    string resultado = "";
    int i,j;
    cout<<"Imprime distancias o pesos optimo: "<<endl;
    for(i=0;i<this->tamanioMatriz;i++)
    {
        resultado += "\n";
        for(j=0;j<this->tamanioMatriz;j++)
        {
            resultado += "|"+to_string(*(*(this->matrizWarshall+i)+j))+"|";
            cout<<*(*(this->matrizWarshall+i)+j);
        }
        cout<<endl;
    }
    return resultado;
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
