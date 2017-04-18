#include "cpugraph.h"
#include "ui_cpugraph.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define TIME_INTERVAL 1
#define POINT_NUM 30
using namespace std;
CpuGraph::CpuGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CpuGraph)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CpuGraph::timerCheck);
    timer->start(1000);
}
void CpuGraph::timerCheck(){

    for(vector<float>::iterator iter=px.begin();iter!=px.end();iter++){
            *iter += TIME_INTERVAL;
    }
    py.push_back(GeneratePoint());
    px.push_back(0);
    if(px.size()>POINT_NUM){
        px.erase(px.begin());
        py.erase(py.begin());
    }        
    Paint(px,py);
    repaint();
}

float CpuGraph::GeneratePoint(){
    static float usage;
    static int ttime1,ttime0,user[2] = {0},nice[2] = {0},sys[2] = {0},idel[2] = {0},irq[2] = {0},soft[2] = {0},steal[2] = {0},guest[2] = {0};
    static char *p,*split = " ";
    string CurReads;
    ifstream infile;
    infile.open("/proc/stat");
    std::getline(infile,CurReads);
    char *CurRead = (char*)malloc(CurReads.length()*sizeof(char));
    CurReads.copy(CurRead,CurReads.length(),0);
    p = strtok(CurRead,split);
    p = strtok(NULL,split);
    stringstream sstr(p);
    sstr >> user[1];
    p = strtok(NULL,split);
    stringstream sstr1(p);
    sstr1 >> nice[1];
    p = strtok(NULL,split);
    stringstream sstr2(p);
    sstr2 >> sys[1];
    p = strtok(NULL,split);
    stringstream sstr3(p);
    sstr3 >> idel[1];
    p = strtok(NULL,split);
    stringstream sstr4(p);
    sstr4 >> soft[1];
    p = strtok(NULL,split);
    stringstream sstr5(p);
    sstr5 >> steal[1];
    p = strtok(NULL,split);
    stringstream sstr6(p);
    sstr6 >> guest[1];
    ttime1 = user[1]+nice[1]+sys[1]+idel[1]+irq[1]+soft[1]+steal[1]+guest[1];
    ttime0 = user[0]+nice[0]+sys[0]+idel[0]+irq[0]+soft[0]+steal[0]+guest[0];
        usage = (float)(idel[1]-idel[0])/(ttime1-ttime0);
    user[0] = user[1];
    nice[0] = nice[1];
    sys[0] = sys[1];
    idel[0] =idel[1];
    irq[0] = irq[1];
    soft[0] = soft[1];
    steal[0] = steal[1];
    guest[0] = guest[1];
    infile.close();
    return (1-usage)*100;
}

CpuGraph::~CpuGraph()
{
    delete ui;
}

void CpuGraph::Paint(vector<float> px,vector<float> py)
{
    QPainter painter(&image);
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(2);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    for(int i=0;(unsigned)i<px.size();i++)
    {
        painter.drawLine(pointx+kx*px[i],pointy-py[i]*ky,pointx+kx*(px[i+1]),pointy-py[i+1]*ky);
        painter.drawPoint(pointx+kx*px[i],pointy-py[i]*ky);
    }
}
