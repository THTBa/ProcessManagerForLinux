#ifndef CPUGRAPH_H
#define CPUGRAPH_H
#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QtGui>
#include <QDialog>
#include <vector>
#include <QDebug>
namespace Ui {
class CpuGraph;
}
using namespace std;
class CpuGraph : public QDialog
{
    Q_OBJECT

public:
    std::vector<float> px,py;
    explicit CpuGraph(QWidget *parent = 0);
    ~CpuGraph();
    virtual void Paint(vector<float>,vector<float>);

    virtual float GeneratePoint();
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
        qDebug()<<"pEvent";
    }
private slots:
    void timerCheck();
public:
    Ui::CpuGraph *ui;
    QImage image;
};

#endif // CPUGRAPH_H
