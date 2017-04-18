#include "cpudialog.h"
#include "ui_cpudialog.h"
#include <fcntl.h>
#include <QFile>
#include <unistd.h>
#define BUF_SIZE 1024*1024
CpuDialog::CpuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CpuDialog)
{
    ui->setupUi(this);
     // cpuInfo
    QFile f("/proc/cpuinfo");
    if(!f.open(QIODevice::ReadOnly));
//     int fd,a = sizeof(char)*BUF_SIZE;
     ui->textBrowser->setText(f.readAll());
     f.close();
}

CpuDialog::~CpuDialog()
{
    delete ui;
}
