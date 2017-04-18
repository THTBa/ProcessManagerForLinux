/********************************************************************************
** Form generated from reading UI file 'swapdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWAPDIALOG_H
#define UI_SWAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SwapDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SwapDialog)
    {
        if (SwapDialog->objectName().isEmpty())
            SwapDialog->setObjectName(QStringLiteral("SwapDialog"));
        SwapDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(SwapDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(SwapDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SwapDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SwapDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SwapDialog);
    } // setupUi

    void retranslateUi(QDialog *SwapDialog)
    {
        SwapDialog->setWindowTitle(QApplication::translate("SwapDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SwapDialog: public Ui_SwapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWAPDIALOG_H
