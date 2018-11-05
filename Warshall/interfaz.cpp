#include "interfaz.h"
#include "ui_interfaz.h"

interfaz::interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);
}

interfaz::~interfaz()
{
    delete ui;
}

void interfaz::on_botonGenerar_clicked()
{
    int numNodo = ui->numNodosText->text().toInt();
    int numAIngresar = ui->numAIngresarText->text().toInt();
    warshallApl.ingresar(numAIngresar,numNodo);
}

void interfaz::on_botonIrDeVerticeAVertice_clicked()
{

}
