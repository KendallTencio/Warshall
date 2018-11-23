#include "interfaz.h"
#include <thread>
#include <ctime>
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
    string strResultado = "Matriz Original: \n" + warshallApl.dibujarMatriz();
    unsigned t0, t1;

    if(ui->radioButton->isChecked())
    {
        //EJECUCIÓN DE LOS HILOS
        strResultado += "\n\nEjecutando hilos paralelamente...";
        t0 = clock();

        std::thread first(&Warshall::nodointer, warshallApl);   //  Hilo para la función nodointer
        std::thread second(&Warshall::algoritWarshall, warshallApl);  // Hilo para la función algoritWarshall

        // sincronizando hilos:
        first.join();                // Se detienen cuando los hilos terminan
        second.join();

        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        strResultado += "\nTiempo transcurrido:" + to_string(time);
        strResultado += "\n¡Hilos completados!";

        //FINALIZACIÓN DE HILOS
    }
    else
    {
        t0 = clock();
        warshallApl.nodointer();
        warshallApl.warshallFloyd();
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        strResultado += "\nTiempo transcurrido:" + to_string(time);
    }
    strResultado += "\n\nMatriz Final: \n" + warshallApl.mostrar1();
    QString resultadosTexto = QString::fromStdString(strResultado);
    ui->pantallaResultados->setPlainText(resultadosTexto);
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
