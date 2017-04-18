/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPC_name;
    QAction *actionShutDown;
    QAction *actionP_Creat;
    QWidget *centralWidget;
    QLabel *label;
    QListView *processList;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QMenuBar *menuBar;
    QMenu *menuproc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(986, 568);
        actionPC_name = new QAction(MainWindow);
        actionPC_name->setObjectName(QStringLiteral("actionPC_name"));
        actionShutDown = new QAction(MainWindow);
        actionShutDown->setObjectName(QStringLiteral("actionShutDown"));
        actionP_Creat = new QAction(MainWindow);
        actionP_Creat->setObjectName(QStringLiteral("actionP_Creat"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 81, 17));
        processList = new QListView(centralWidget);
        processList->setObjectName(QStringLiteral("processList"));
        processList->setGeometry(QRect(0, 20, 381, 381));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(390, 20, 521, 381));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 450, 89, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 450, 111, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 480, 671, 20));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(210, 0, 701, 401));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(820, 410, 89, 25));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(140, 410, 181, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(6, 410, 101, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 410, 89, 25));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(450, 410, 89, 25));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(230, 450, 121, 25));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(360, 450, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 986, 28));
        menuproc = new QMenu(menuBar);
        menuproc->setObjectName(QStringLiteral("menuproc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuproc->menuAction());
        menuproc->addAction(actionPC_name);
        menuproc->addAction(actionShutDown);
        menuproc->addAction(actionP_Creat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionPC_name->setText(QApplication::translate("MainWindow", "PC-name", Q_NULLPTR));
        actionShutDown->setText(QApplication::translate("MainWindow", "ShutDown", Q_NULLPTR));
        actionP_Creat->setText(QApplication::translate("MainWindow", "P_Creat", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ProcessList", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "CPU-INFO", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "CPU-USING-GH", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Process-PID", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "MEM-USING_GH", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "SWAP-GH", Q_NULLPTR));
        menuproc->setTitle(QApplication::translate("MainWindow", "func", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
