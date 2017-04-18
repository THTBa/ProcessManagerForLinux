#ifndef CPUDIALOG_H
#define CPUDIALOG_H
#include <QMainWindow>
#include <QDialog>
#include <QAbstractItemModel>
#define BUF_SIZE 1024*1024
namespace Ui {
class CpuDialog;
}
class CpuDialog : public QDialog
{
    Q_OBJECT

public:
    char *store = (char*)malloc(BUF_SIZE*sizeof(char));
    explicit CpuDialog(QWidget *parent = 0);
    ~CpuDialog();

private:
    Ui::CpuDialog *ui;
};

#endif // CPUDIALOG_H
