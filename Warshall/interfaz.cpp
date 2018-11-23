#include "interfaz.h"
#include <pthread.h>
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
    string strResultado = warshallApl.generarMatrizVacia(numNodo);
    strResultado += "\n"+warshallApl.dibujarMatriz();
    QString resultadosTexto = QString::fromStdString(strResultado);
    ui->pantallaResultados->setPlainText(resultadosTexto);
}

void interfaz::on_botonIrDeVerticeAVertice_clicked()
{
    pthread_t thread1, thread2;

    string strResultado = "Matriz Original: \n" + warshallApl.dibujarMatriz();
    warshallApl.nodointer();
    warshallApl.warshallFloyd();
    //pthread_create(&thread1, NULL, warshallApl.nodointer() , NULL);
    //pthread_create(&thread2, NULL,  warshallApl.warshallFloyd(), NULL);
    strResultado += "\n\nMatriz Final: \n" + warshallApl.mostrar1();
    QString resultadosTexto = QString::fromStdString(strResultado);
    ui->pantallaResultados->setPlainText(resultadosTexto);

    //pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);
}

void interfaz::on_botonIngresar_clicked()
{
    int numNodosIngresar = ui->numNodosIngreso2->text().toInt();
    int cadenaMatriz = ui->lineaDeMatriz->text().toInt();
    string strResultado = warshallApl.generarMatrizConIngresos(numNodosIngresar, cadenaMatriz);
    if(strResultado != "Error en la matriz digitada\n1.Favor revise que indico ceros en la diagonal\n2.Favor revise que indico la cantidad adecuada de números"){
        strResultado += "\n"+warshallApl.dibujarMatriz();
        QString resultadosTexto = QString::fromStdString(strResultado);
        ui->pantallaResultados->setPlainText(resultadosTexto);
    }
    else{
        QString resultadosTexto = QString::fromStdString(strResultado);
        ui->pantallaResultados->setPlainText(resultadosTexto);
    }

}

void interfaz::on_pushButton_clicked()
{
    string strResultado = warshallApl.generarMatrizLista();
    strResultado += "\n"+warshallApl.dibujarMatriz();
    QString resultadosTexto = QString::fromStdString(strResultado);
    ui->pantallaResultados->setPlainText(resultadosTexto);

}
