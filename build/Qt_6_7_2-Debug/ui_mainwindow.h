/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(584, 439);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 150, 411, 141));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Script")});
        font.setPointSize(28);
        font.setBold(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background: grey ;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 90, 131, 31));
        label_2->setStyleSheet(QString::fromUtf8("background: grey ;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 90, 81, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 310, 83, 29));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 310, 113, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("background: grey ;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 0, 461, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Text")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(12, 180, 81, 81));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label_4->setFont(font2);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(290, 90, 82, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(480, 90, 16, 29));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(330, 360, 83, 29));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 360, 113, 28));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background: grey ;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 310, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(110, 360, 63, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(290, 60, 41, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 100, 121, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 584, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Primeiro estabele\303\247a a conex\303\243o em seguida envie os dados", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Response:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "verify", nullptr));
        lineEdit_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Abrir:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Verificar:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "serial:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "connect response:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
