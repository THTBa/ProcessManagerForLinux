#include "swapdialog.h"
#include "ui_swapdialog.h"
#include "ui_cpugraph.h"
#include "cpugraph.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
SwapDialog::SwapDialog(QWidget *parent) :
    CpuGraph(0)
    //ui(new Ui::SwapDialog)
{
    // ui->setupUi(this);
}

SwapDialog::~SwapDialog()
{
    // delete ui;
}


float SwapDialog::GeneratePoint(){
    static float usage = 0;
    static int allswap,usedswap;
    static char *p,*split = " ";
    char CurRead[500];
    ifstream infile;
    infile.open("/proc/swaps");
    infile.getline(CurRead,500);
    infile.getline(CurRead,500);

    p = strtok(CurRead,split);
    p = strtok(NULL,"\t");
    p = strtok(NULL,"\t");
    stringstream sstr(p);
    sstr >> allswap;
    p = strtok(NULL,"\t");
    stringstream sstr1(p);
    sstr1 >> usedswap;
    usage = (float)(usedswap)/(allswap);
    //close
    infile.close();
    return (usage)*100;
}
