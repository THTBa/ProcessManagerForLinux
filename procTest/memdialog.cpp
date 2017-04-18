#include "memdialog.h"
#include "ui_memdialog.h"
#include "ui_cpugraph.h"
#include "cpugraph.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
MemDialog::MemDialog(QWidget *parent) :
    CpuGraph(0)
    //ui(new Ui::MemDialog)
{
    // ui->setupUi(this);
}

MemDialog::~MemDialog()
{
    // delete ui;
}


float MemDialog::GeneratePoint(){
    static float usage;
    static int allmem,freemem;
    static char *p,*split = " ";
    char CurRead[50];
    ifstream infile;
    infile.open("/proc/meminfo");
    infile.getline(CurRead,50);
    p = strtok(CurRead,split);
    p = strtok(NULL,split);
    stringstream sstr(p);
    sstr >> allmem;
    infile.getline(CurRead,50);

    p = strtok(CurRead,split);
    p = strtok(NULL,split);
    stringstream sstr1(p);
    sstr1 >> freemem;
    usage = (float)(freemem)/(allmem);
    //close
    infile.close();
    return (1-usage)*100;	

}
