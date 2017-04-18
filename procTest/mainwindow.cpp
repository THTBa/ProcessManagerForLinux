#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>  
#include <pwd.h>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <fcntl.h>
#include <QFile>
#define BUF_SIZE 1024*4
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Cur_WidStat = 0;
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::timerCheck);
    timer->start(1000);


 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::itemClicked(QModelIndex index)
{
    DIR *dp;
    struct dirent *ptr;
    int fd;
    char *dir = "/proc",path[20];
    int  a = BUF_SIZE*sizeof(char);
    qDebug()<<index.row();
    if(index.row() != -1){
        if(!(dp = opendir(dir))){
            printf("No such a file named %s.\n",dir);
            return;
        }
        for(int i = 0;i<=index.row();){
            ptr = readdir(dp);
            if ((ptr->d_name[0] >= '0') && (ptr->d_name[0] <= '9')) i++;
        }
        sprintf(path, "/proc/%s/status", ptr->d_name);
        fd = open(path, O_RDONLY);  
        read(fd, store, a);
        ui->textBrowser->setText(store);
        ::close(fd);        
    }
}

void MainWindow::timerCheck(){
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    float a;
    char usage[40];
    if(cpuGraph.py.size()>0)a = cpuGraph.py[cpuGraph.py.size()-1];
    else a = 0;
    sprintf(usage,"%f",a);
    ui->label_2->setText(current_date+"             CPU use:"+usage);
        if(Cur_WidStat == 0){
            HideUI1();
            HideUI2();
            ShowChild();         
            mainTask();
        }
        if(Cur_WidStat == 1){
            HideChild();
            ShowUI1();
        }
        if(Cur_WidStat == 2){
            HideChild();
            ShowUI2();
        }
    Last_WidStat = Cur_WidStat;
}
void MainWindow::HideChild(){
    ui->label->hide();
    ui->processList->hide();
    ui->textBrowser->hide();
    ui->label_3->hide();
    ui->plainTextEdit->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}
void MainWindow::ShowChild(){
    ui->label->show();
    ui->processList->show();
    ui->textBrowser->show();
    ui->label_3->show();
    ui->plainTextEdit->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
}
void MainWindow::ShowUI1(){
    QFile f("/proc/sys/kernel/hostname"),f2("/proc/uptime"),f3("/proc/version");
    if(!f.open(QIODevice::ReadOnly));
    if(!f2.open(QIODevice::ReadOnly));
    if(!f3.open(QIODevice::ReadOnly));
    char PC[20] = "PC_name:  ",Run[30] = "Runtime and idel time:  ";

    ui->textBrowser_2->setText(PC+f.readAll()+"\n\n"+Run+f2.readAll()+"\n\n"+f3.readAll());
    f.close();f2.close();f3.close();
    ui->textBrowser_2->show();    
    ui->pushButton_3->show();
}
void MainWindow::ShowUI2(){
    
}
void MainWindow::HideUI1(){
    ui->textBrowser_2->hide();
    ui->pushButton_3->hide();
}
void MainWindow::HideUI2(){
    
}
void MainWindow::on_pushButton_clicked()
{
    cpuDialog.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    cpuGraph.show();
}

bool MainWindow::StatChanged()
{       
    return (Cur_WidStat != Last_WidStat);
}

void MainWindow::mainTask(){
    DIR *dp;
    struct dirent *ptr;
    int nCount,fd;
    char *dir = "/proc",path[20],name[40];
    int  i,a = BUF_SIZE*sizeof(char);
    if(standardItemModel){
        disconnect(ui->processList,SIGNAL(clicked(QModelIndex)),
                    this,SLOT(itemClicked(QModelIndex)));
    }
    standardItemModel = new QStandardItemModel(this);

     QStringList strList;

     if(!(dp = opendir(dir))){
         printf("No such a file named %s.\n",dir);
         return;
     }
    while ((ptr = readdir(dp)) != NULL) {
        if ((ptr->d_name[0] >= '0') && (ptr->d_name[0] <= '9')) {
            sprintf(path, "/proc/%s/status", ptr->d_name);
            fd = open(path, O_RDONLY);
            read(fd, store, a);
            for(i = 0;store[i]!='\n';i++){
                name[i] = store[i];
            }
            name[i] = '\0';

            strList.append(name);
            ::close(fd);
        }
    }
    closedir(dp);


     nCount = strList.size();
     for(int i = 0; i < nCount; i++)
     {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        if(i %2 == 1)
        {
            QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
            linearGrad.setColorAt(0, Qt::darkGreen);
            linearGrad.setColorAt(1, Qt::yellow);
            QBrush brush(linearGrad);
            item->setBackground(brush);
        }
        standardItemModel->appendRow(item);
     }
     ui->processList->setModel(standardItemModel);
     connect(ui->processList,SIGNAL(clicked(QModelIndex)),
             this,SLOT(itemClicked(QModelIndex)));
}

void MainWindow::on_actionPC_name_triggered()
{
    Cur_WidStat = 1;
}

void MainWindow::on_pushButton_3_clicked()
{
    Cur_WidStat = 0;
}


void MainWindow::on_pushButton_4_clicked()
{
    DIR *dp;
    struct dirent *ptr;
    int nCount,fd;
    char *dir = "/proc",path[20],name[40];
    int  i,a = BUF_SIZE*sizeof(char);
     QString str = ui->plainTextEdit->toPlainText();
     QByteArray ba = str.toLatin1();
     char *mm = ba.data();
     if(mm[0]!='\0'){
         if(!(dp = opendir(dir))){
             printf("No such a file named %s.\n",dir);
             return;
         }
         while ((ptr = readdir(dp)) != NULL) {
             if ((ptr->d_name[0] >= '0') && (ptr->d_name[0] <= '9')) {
                 if(!strcmp(mm,ptr->d_name)){
                     sprintf(path, "/proc/%s/status", ptr->d_name);
                     fd = open(path, O_RDONLY);
                     read(fd, store, a);
                     ui->textBrowser->setText(store);
                     ::close(fd);
                     break;
                 }
             }
         }
     }


}

void MainWindow::on_actionShutDown_triggered()
{
    system("shutdown -h now");
}

void MainWindow::on_pushButton_5_clicked()
{
    DIR *dp;
    struct dirent *ptr;
    int nCount,fd;
    char *dir = "/proc",path[20],name[40];
    int  i,a = BUF_SIZE*sizeof(char);
     QString str = ui->plainTextEdit->toPlainText();
     QByteArray ba = str.toLatin1();
     char *mm = ba.data();
     if(mm[0]!='\0'){
         if(!(dp = opendir(dir))){
             printf("No such a file named %s.\n",dir);
             return;
         }
         while ((ptr = readdir(dp)) != NULL) {
             if ((ptr->d_name[0] >= '0') && (ptr->d_name[0] <= '9')) {
                 if(!strcmp(mm,ptr->d_name)){
                     sprintf(path, "/bin/kill -9 %s", ptr->d_name);
                     system(path);
                     ::close(fd);
                     break;
                 }
             }
         }
     }

}

void MainWindow::on_actionP_Creat_triggered()
{

}

void MainWindow::on_pushButton_6_clicked()
{
    memDialog.show();
}

void MainWindow::on_pushButton_7_clicked()
{
    swapDialog.show();
}
