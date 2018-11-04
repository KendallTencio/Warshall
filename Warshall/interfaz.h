#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>

namespace Ui {
class interfaz;
}

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit interfaz(QWidget *parent = 0);
    ~interfaz();

private:
    Ui::interfaz *ui;
};

#endif // INTERFAZ_H
