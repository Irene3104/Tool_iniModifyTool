/********************************************************************************
** Form generated from reading UI file 'iniTool.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITOOL_H
#define UI_INITOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iniToolClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *btn_path;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *btn_click;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *iniToolClass)
    {
        if (iniToolClass->objectName().isEmpty())
            iniToolClass->setObjectName(QString::fromUtf8("iniToolClass"));
        iniToolClass->resize(475, 320);
        centralWidget = new QWidget(iniToolClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 281, 31));
        btn_path = new QPushButton(centralWidget);
        btn_path->setObjectName(QString::fromUtf8("btn_path"));
        btn_path->setGeometry(QRect(410, 20, 41, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 31));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 60, 431, 23));
        progressBar->setValue(24);
        btn_click = new QPushButton(centralWidget);
        btn_click->setObjectName(QString::fromUtf8("btn_click"));
        btn_click->setGeometry(QRect(130, 200, 221, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 110, 431, 71));
        iniToolClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(iniToolClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 475, 21));
        iniToolClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(iniToolClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        iniToolClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(iniToolClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        iniToolClass->setStatusBar(statusBar);

        retranslateUi(iniToolClass);

        QMetaObject::connectSlotsByName(iniToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *iniToolClass)
    {
        iniToolClass->setWindowTitle(QCoreApplication::translate("iniToolClass", "iniTool", nullptr));
        btn_path->setText(QCoreApplication::translate("iniToolClass", "...", nullptr));
        label->setText(QCoreApplication::translate("iniToolClass", "*.ini folder path :", nullptr));
        btn_click->setText(QCoreApplication::translate("iniToolClass", "Click", nullptr));
    } // retranslateUi

};

namespace Ui {
    class iniToolClass: public Ui_iniToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITOOL_H
