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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interfaz
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *interfaz)
    {
        if (interfaz->objectName().isEmpty())
            interfaz->setObjectName(QStringLiteral("interfaz"));
        interfaz->resize(400, 300);
        menuBar = new QMenuBar(interfaz);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        interfaz->setMenuBar(menuBar);
        mainToolBar = new QToolBar(interfaz);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        interfaz->addToolBar(mainToolBar);
        centralWidget = new QWidget(interfaz);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        interfaz->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(interfaz);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        interfaz->setStatusBar(statusBar);

        retranslateUi(interfaz);

        QMetaObject::connectSlotsByName(interfaz);
    } // setupUi

    void retranslateUi(QMainWindow *interfaz)
    {
        interfaz->setWindowTitle(QApplication::translate("interfaz", "interfaz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interfaz: public Ui_interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
