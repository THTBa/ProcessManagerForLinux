/********************************************************************************
** Form generated from reading UI file 'memdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMDIALOG_H
#define UI_MEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MemDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MemDialog)
    {
        if (MemDialog->objectName().isEmpty())
            MemDialog->setObjectName(QStringLiteral("MemDialog"));
        MemDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MemDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(MemDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MemDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MemDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MemDialog);
    } // setupUi

    void retranslateUi(QDialog *MemDialog)
    {
        MemDialog->setWindowTitle(QApplication::translate("MemDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemDialog: public Ui_MemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMDIALOG_H
