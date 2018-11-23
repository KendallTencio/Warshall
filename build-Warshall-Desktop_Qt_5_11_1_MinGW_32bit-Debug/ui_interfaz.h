/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interfaz
{
public:
    QWidget *centralWidget;
    QLineEdit *numNodosText;
    QLabel *label;
    QLabel *label_3;
    QPushButton *botonGenerar;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *botonIrDeVerticeAVertice;
    QLabel *label_4;
    QLineEdit *numNodosIngreso2;
    QPushButton *botonIngresar;
    QPlainTextEdit *pantallaResultados;
    QRadioButton *radioButton;
    QLabel *label_2;
    QLineEdit *lineaDeMatriz;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *interfaz)
    {
        if (interfaz->objectName().isEmpty())
            interfaz->setObjectName(QStringLiteral("interfaz"));
        interfaz->resize(620, 488);
        centralWidget = new QWidget(interfaz);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        numNodosText = new QLineEdit(centralWidget);
        numNodosText->setObjectName(QStringLiteral("numNodosText"));
        numNodosText->setGeometry(QRect(110, 320, 31, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 320, 91, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 310, 151, 20));
        botonGenerar = new QPushButton(centralWidget);
        botonGenerar->setObjectName(QStringLiteral("botonGenerar"));
        botonGenerar->setGeometry(QRect(20, 360, 131, 23));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 290, 611, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(160, 300, 20, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(410, 300, 20, 131));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        botonIrDeVerticeAVertice = new QPushButton(centralWidget);
        botonIrDeVerticeAVertice->setObjectName(QStringLiteral("botonIrDeVerticeAVertice"));
        botonIrDeVerticeAVertice->setGeometry(QRect(480, 340, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 310, 91, 16));
        numNodosIngreso2 = new QLineEdit(centralWidget);
        numNodosIngreso2->setObjectName(QStringLiteral("numNodosIngreso2"));
        numNodosIngreso2->setGeometry(QRect(300, 310, 31, 20));
        botonIngresar = new QPushButton(centralWidget);
        botonIngresar->setObjectName(QStringLiteral("botonIngresar"));
        botonIngresar->setGeometry(QRect(190, 400, 75, 23));
        pantallaResultados = new QPlainTextEdit(centralWidget);
        pantallaResultados->setObjectName(QStringLiteral("pantallaResultados"));
        pantallaResultados->setGeometry(QRect(30, 20, 561, 251));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(440, 370, 111, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 340, 91, 16));
        lineaDeMatriz = new QLineEdit(centralWidget);
        lineaDeMatriz->setObjectName(QStringLiteral("lineaDeMatriz"));
        lineaDeMatriz->setGeometry(QRect(290, 340, 121, 61));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 350, 91, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 360, 91, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 370, 61, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 390, 131, 23));
        interfaz->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(interfaz);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 18));
        interfaz->setMenuBar(menuBar);
        mainToolBar = new QToolBar(interfaz);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        interfaz->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(interfaz);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        interfaz->setStatusBar(statusBar);

        retranslateUi(interfaz);

        QMetaObject::connectSlotsByName(interfaz);
    } // setupUi

    void retranslateUi(QMainWindow *interfaz)
    {
        interfaz->setWindowTitle(QApplication::translate("interfaz", "interfaz", nullptr));
        label->setText(QApplication::translate("interfaz", "N\303\272mero de nodos", nullptr));
        label_3->setText(QApplication::translate("interfaz", "Obtener camino m\303\241s corto: ", nullptr));
        botonGenerar->setText(QApplication::translate("interfaz", "Generar matriz aleatoria", nullptr));
        botonIrDeVerticeAVertice->setText(QApplication::translate("interfaz", "Resolver", nullptr));
        label_4->setText(QApplication::translate("interfaz", "N\303\272mero de nodos", nullptr));
        botonIngresar->setText(QApplication::translate("interfaz", "Ingresar", nullptr));
        radioButton->setText(QApplication::translate("interfaz", "Usando hilos", nullptr));
        label_2->setText(QApplication::translate("interfaz", "Cadena de matriz", nullptr));
        label_5->setText(QApplication::translate("interfaz", "<html><head/><body><p><span style=\" font-size:6pt;\">Esta ser\303\241 la matriz</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("interfaz", "<html><head/><body><p><span style=\" font-size:6pt;\"> favor usar formato: 1343</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("interfaz", "<html><head/><body><p><span style=\" font-size:6pt;\">en una de 2x2</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("interfaz", "Generar Manual", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interfaz: public Ui_interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
