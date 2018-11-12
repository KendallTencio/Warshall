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
    //int numAIngresar = ui->numAIngresarText->text().toInt();
    string strResultado = warshallApl.generarMatrizVacia(numNodo);
    strResultado += "\n"+warshallApl.dibujarMatriz();
    QString resultadosTexto = QString::fromStdString(strResultado);
    ui->pantallaResultados->setPlainText(resultadosTexto);
}

void interfaz::on_botonIrDeVerticeAVertice_clicked()
{
    int vertice1 = ui->vertice1Text->text().toInt();
    int vertice2 = ui->vertice2Text->text().toInt() ;
    warshallApl.nodointer();
    warshallApl.algoritWarshall();
    warshallApl.mostrar1();
    warshallApl.mostrar2();
    warshallApl.preguntar(vertice1 , vertice2);
}

void interfaz::on_botonIngresar_clicked()
{
    int numAIngresar = ui->numAIngresarText->text().toInt();
    warshallApl.ingresar(numAIngresar);
    warshallApl.nodointer();
    warshallApl.algoritWarshall();
}
