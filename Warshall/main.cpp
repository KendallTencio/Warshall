#include "interfaz.h"
#include <QApplication>
#include "warshall.h"
//#include "Threads.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interfaz w;
    w.show();

    return a.exec();
}
