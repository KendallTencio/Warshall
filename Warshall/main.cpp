#include "interfaz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interfaz w;
    floyd E;
    E.ingresar();
    E.nodointer();
    E.floid();
    E.mostrar1();
    E.mostrar2();
    E.preguntar();
    getch();
    //w.show();

    return a.exec();
}
