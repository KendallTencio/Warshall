#include "Threads.h"
//#define BUF_SIZE 255
//using namespace std;

#include <windows.h>
#include <strsafe.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 255
//Código basado, modificado e inspirado en:
        //https://www.codeproject.com/Articles/13557/Creating-Threads-using-the-CreateThread-API

//------------------------------------------
// Función para imprimir y ver en qué hilo se está
//------------------------------------------
void DisplayMessage (HANDLE hScreen, char *ThreadName, int Data, int Count)
{

    TCHAR msgBuf[BUF_SIZE];
    size_t cchStringSize;
    DWORD dwChars;

    // Imprime dato o mensaje del hilo
    StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Ejecutando iteracion %02d de %s , el dato es = %02d \n"), Count, ThreadName, Data);
    StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
    WriteConsole(hScreen, msgBuf, cchStringSize, &dwChars, NULL);
    Sleep(1000);
}

//-------------------------------------------
// Función Hilo 1
//-------------------------------------------
DWORD WINAPI Thread_no_1( LPVOID lpParam )
{

    int     Data = 0;
    int     count = 0;
    HANDLE  hStdout = NULL;

    // Get Handle To screen.
    if( (hStdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE )
    return 1;

    // Cast the parameter to the correct
    // data type passed by callee i.e main() in our case.
    Data = *((int*)lpParam);
    for (count = 0; count <= 2; count++ )
    {
       DisplayMessage (hStdout, "Hilo 1", Data, count);
    }

    return 0;
}

//-------------------------------------------
// Función hilo 2
//-------------------------------------------
DWORD WINAPI Thread_no_2( LPVOID lpParam )
{

    int     Data = 0;
    int     count = 0;
    HANDLE  hStdout = NULL;

    // Get Handle To screen.
    if( (hStdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE )
    return 1;

    // Cast the parameter to the correct
    // data type passed by callee i.e main() in our case.
    Data = *((int*)lpParam);
    for (count = 0; count <= 2; count++ )
    {
      DisplayMessage (hStdout, "Hilo 2", Data, count);
    }

    return 0;
}


int Threads::ejercerHilos()
{
    // Dato para el hilo 1
    int Data_Of_Thread_1 = 1;
    // Dato para el hilo 2
    int Data_Of_Thread_2 = 2;

    // Variable para el handle para el hilo 1
    HANDLE Handle_Of_Thread_1 = 0;
    // Variable para el handle para el hilo 2
    HANDLE Handle_Of_Thread_2 = 0;

    // Arreglo con los handle de los hilos
    HANDLE Array_Of_Thread_Handles[2];

    // Crea el hilo 1.
    Handle_Of_Thread_1 = CreateThread( NULL, 0,
           Thread_no_1, &Data_Of_Thread_1, 0, NULL);
    if ( Handle_Of_Thread_1 == NULL)
        ExitProcess(Data_Of_Thread_1);

    // Crea el hilo 2.
    Handle_Of_Thread_2 = CreateThread( NULL, 0,
           Thread_no_2, &Data_Of_Thread_2, 0, NULL);
    if ( Handle_Of_Thread_2 == NULL)
        ExitProcess(Data_Of_Thread_2);

    // Guarda los handle en el arreglo de handles
    Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;
    Array_Of_Thread_Handles[1] = Handle_Of_Thread_2;

    // Esperando que terminen los hilos
    WaitForMultipleObjects( 2,
        Array_Of_Thread_Handles, TRUE, INFINITE);

    cout<<("Todos los hilos ejecutados \nCerrando... \n");

    // Cierra los handle cuando se ha completado el proceso del hilo
    CloseHandle(Handle_Of_Thread_1);
    CloseHandle(Handle_Of_Thread_2);

    return 0;
}
/*
void main()
{
    // Dato para el hilo 1
    int Data_Of_Thread_1 = 1;

    // Variable para el handle para el hilo 1
    HANDLE Handle_Of_Thread_1 = 0;

    // Arreglo con los handle de los hilos
    HANDLE Array_Of_Thread_Handles[3];

    // Crea el hilo 1.
    Handle_Of_Thread_1 = CreateThread( NULL, 0,
           Thread_no_1, &Data_Of_Thread_1, 0, NULL);
    if ( Handle_Of_Thread_1 == NULL)
        ExitProcess(Data_Of_Thread_1);

    // Guarda los handle en el arreglo de handles
    Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;

    // Esperando que terminen los hilos
    WaitForMultipleObjects( 3,
        Array_Of_Thread_Handles, TRUE, INFINITE);

    cout<<("Todos los hilos ejecutados \nCerrando... \n");

    // Cierra los handle cuando se ha completado el proceso del hilo
    CloseHandle(Handle_Of_Thread_1);
}
*/
