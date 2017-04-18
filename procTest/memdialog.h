#ifndef MEMDIALOG_H
#define MEMDIALOG_H

#include <QDialog>
#include "cpugraph.h"
namespace Ui {
class MemDialog;
}

class MemDialog : public CpuGraph
{
    Q_OBJECT

public:
	float GeneratePoint();
    explicit MemDialog(QWidget *parent = 0);
    ~MemDialog();

private:
   // Ui::MemDialog *ui;

};

#endif // MEMDIALOG_H
