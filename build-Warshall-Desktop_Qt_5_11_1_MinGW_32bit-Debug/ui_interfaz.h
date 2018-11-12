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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interfaz
{
public:
    QWidget *centralWidget;
    QLineEdit *numNodosText;
    QLineEdit *vertice1Text;
    QLineEdit *vertice2Text;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *botonGenerar;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *botonIrDeVerticeAVertice;
    QLabel *label_4;
    QLineEdit *numAIngresarText;
    QPushButton *botonIngresar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *interfaz)
    {
        if (interfaz->objectName().isEmpty())
            interfaz->setObjectName(QStringLiteral("interfaz"));
        interfaz->resize(583, 456);
        centralWidget = new QWidget(interfaz);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        numNodosText = new QLineEdit(centralWidget);
        numNodosText->setObjectName(QStringLiteral("numNodosText"));
        numNodosText->setGeometry(QRect(110, 320, 31, 20));
        vertice1Text = new QLineEdit(centralWidget);
        vertice1Text->setObjectName(QStringLiteral("vertice1Text"));
        vertice1Text->setGeometry(QRect(480, 330, 31, 20));
        vertice2Text = new QLineEdit(centralWidget);
        vertice2Text->setObjectName(QStringLiteral("vertice2Text"));
        vertice2Text->setGeometry(QRect(540, 330, 31, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 320, 91, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(520, 330, 16, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 330, 81, 20));
        botonGenerar = new QPushButton(centralWidget);
        botonGenerar->setObjectName(QStringLiteral("botonGenerar"));
        botonGenerar->setGeometry(QRect(40, 360, 75, 23));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 290, 581, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(160, 300, 20, 111));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(370, 300, 20, 101));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        botonIrDeVerticeAVertice = new QPushButton(centralWidget);
        botonIrDeVerticeAVertice->setObjectName(QStringLiteral("botonIrDeVerticeAVertice"));
        botonIrDeVerticeAVertice->setGeometry(QRect(450, 360, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 320, 91, 16));
        numAIngresarText = new QLineEdit(centralWidget);
        numAIngresarText->setObjectName(QStringLiteral("numAIngresarText"));
        numAIngresarText->setGeometry(QRect(300, 320, 31, 20));
        botonIngresar = new QPushButton(centralWidget);
        botonIngresar->setObjectName(QStringLiteral("botonIngresar"));
        botonIngresar->setGeometry(QRect(230, 360, 75, 23));
        interfaz->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(interfaz);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 583, 18));
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
        label_2->setText(QApplication::translate("interfaz", "al", nullptr));
        label_3->setText(QApplication::translate("interfaz", "Ir del v\303\251rtice:", nullptr));
        botonGenerar->setText(QApplication::translate("interfaz", "Generar matriz", nullptr));
        botonIrDeVerticeAVertice->setText(QApplication::translate("interfaz", "Ir", nullptr));
        label_4->setText(QApplication::translate("interfaz", "N\303\272mero a ingresar", nullptr));
        botonIngresar->setText(QApplication::translate("interfaz", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interfaz: public Ui_interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
