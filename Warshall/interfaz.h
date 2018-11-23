#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include "warshall.h"

namespace Ui {
class interfaz;
}

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit interfaz(QWidget *parent = 0);
    ~interfaz();

private slots:
    void on_botonGenerar_clicked();

    void on_botonIrDeVerticeAVertice_clicked();

    void on_botonIngresar_clicked();

    void on_pushButton_clicked();

private:
    Ui::interfaz *ui;
    Warshall warshallApl;
};

#endif // INTERFAZ_H
