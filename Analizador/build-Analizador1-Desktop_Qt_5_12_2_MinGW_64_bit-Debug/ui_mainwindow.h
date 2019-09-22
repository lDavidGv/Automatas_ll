/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QWidget *centralWidget;
    QPlainTextEdit *textoAnalizar;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *Token;
    QPlainTextEdit *Error;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1134, 655);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textoAnalizar = new QPlainTextEdit(centralWidget);
        textoAnalizar->setObjectName(QString::fromUtf8("textoAnalizar"));
        textoAnalizar->setGeometry(QRect(10, 50, 1101, 221));
        QFont font;
        font.setPointSize(12);
        textoAnalizar->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 550, 161, 41));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 290, 91, 21));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 290, 81, 21));
        label_2->setFont(font2);
        Token = new QPlainTextEdit(centralWidget);
        Token->setObjectName(QString::fromUtf8("Token"));
        Token->setGeometry(QRect(10, 320, 541, 221));
        Token->setFont(font);
        Error = new QPlainTextEdit(centralWidget);
        Error->setObjectName(QString::fromUtf8("Error"));
        Error->setGeometry(QRect(600, 320, 511, 221));
        Error->setFont(font);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 550, 171, 41));
        pushButton_3->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 81, 21));
        label_3->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1134, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "ANALIZAR", nullptr));
        label->setText(QApplication::translate("MainWindow", "Aceptacion:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Errores:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Limpiar", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Entrada:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
