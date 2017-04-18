#ifndef SWAPDIALOG_H
#define SWAPDIALOG_H

#include <QDialog>
#include "cpugraph.h"
namespace Ui {
class SwapDialog;
}

class SwapDialog : public CpuGraph
{
    Q_OBJECT

public:
	float GeneratePoint();
    explicit SwapDialog(QWidget *parent = 0);
    ~SwapDialog();

private:
   // Ui::SwapDialog *ui;

};

#endif // MEMDIALOG_H
