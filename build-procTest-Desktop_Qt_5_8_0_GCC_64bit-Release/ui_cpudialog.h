/********************************************************************************
** Form generated from reading UI file 'cpudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUDIALOG_H
#define UI_CPUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CpuDialog
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CpuDialog)
    {
        if (CpuDialog->objectName().isEmpty())
            CpuDialog->setObjectName(QStringLiteral("CpuDialog"));
        CpuDialog->resize(922, 575);
        label = new QLabel(CpuDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 71, 17));
        textBrowser = new QTextBrowser(CpuDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 60, 671, 361));

        retranslateUi(CpuDialog);

        QMetaObject::connectSlotsByName(CpuDialog);
    } // setupUi

    void retranslateUi(QWidget *CpuDialog)
    {
        CpuDialog->setWindowTitle(QApplication::translate("CpuDialog", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CpuDialog", "CPU_INFO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CpuDialog: public Ui_CpuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUDIALOG_H
