/********************************************************************************
** Form generated from reading UI file 'cpugraph.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUGRAPH_H
#define UI_CPUGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CpuGraph
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *CpuGraph)
    {
        if (CpuGraph->objectName().isEmpty())
            CpuGraph->setObjectName(QStringLiteral("CpuGraph"));
        CpuGraph->resize(608, 371);
        buttonBox = new QDialogButtonBox(CpuGraph);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(240, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CpuGraph);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 310, 91, 17));

        retranslateUi(CpuGraph);
        QObject::connect(buttonBox, SIGNAL(accepted()), CpuGraph, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CpuGraph, SLOT(reject()));

        QMetaObject::connectSlotsByName(CpuGraph);
    } // setupUi

    void retranslateUi(QDialog *CpuGraph)
    {
        CpuGraph->setWindowTitle(QApplication::translate("CpuGraph", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CpuGraph", "CPU usage", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CpuGraph: public Ui_CpuGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUGRAPH_H
