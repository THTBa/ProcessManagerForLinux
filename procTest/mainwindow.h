#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cpudialog.h>
#include <cpugraph.h>
#include <memdialog.h>
#include <swapdialog.h>
#include <QStandardItemModel>
#include <QModelIndex>
#define BUF_SIZE 1024*4

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    CpuDialog cpuDialog;
    CpuGraph cpuGraph;
    MemDialog memDialog;
    SwapDialog swapDialog;
    int Cur_WidStat,Last_WidStat;
    char store[BUF_SIZE];
    Ui::MainWindow *ui;
    QStandardItemModel *standardItemModel;
    bool StatChanged();
    void mainTask();
    void HideChild();
    void HideUI1();
    void ShowUI1();
    void HideUI2();
    void ShowUI2();
	void ShowChild();
private slots:
    void itemClicked(QModelIndex index);
    void timerCheck();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_actionPC_name_triggered();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_actionShutDown_triggered();
    void on_pushButton_5_clicked();
    void on_actionP_Creat_triggered();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};



#endif // MAINWINDOW_H
