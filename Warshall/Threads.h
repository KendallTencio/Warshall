#ifndef THREADS_H
#define THREADS_H
#include <windows.h>
#include <strsafe.h>
#include <stdio.h>
#include <iostream>

class Threads
{
public:
    Threads();
    int ejercerHilos();
    void DisplayMessage (HANDLE hScreen, char *ThreadName, int Data, int Count);
    //DWORD WINAPI Thread_no_1( LPVOID lpParam );
    //DWORD WINAPI Thread_no_2( LPVOID lpParam );
    /*{
        Threads t;
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
           t.DisplayMessage (hStdout, "Hilo 1", Data, count);
        }

        return 0;
    }*/
};

#endif // THREADS_H
