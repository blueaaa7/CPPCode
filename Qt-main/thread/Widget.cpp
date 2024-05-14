#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnEnd->setEnabled(false);
    ui->btnStart->setEnabled(true);
    
    qDebug()<<"主线程"<<QThread::currentThreadId()<<"开始运行";
}

Widget::~Widget()
{
    delete ui;
}

//开始
void Widget::on_btnStart_clicked()
{
  for(int i=0;i<MAXSIZE;i++){
    workThread[i]=new WorkThread;
  }  
  for(int i=0;i<MAXSIZE;i++){
    workThread[i]->start();
  }
  ui->btnStart->setEnabled(false);
  ui->btnEnd->setEnabled(true);
}

//停止
void Widget::on_btnEnd_clicked()
{
    for(int i=0;i<MAXSIZE;i++){
        workThread[i]->stop();
        workThread[i]->wait();
        delete workThread[i];
        workThread[i]=nullptr;
    }
    qDebug()<<"停止了";
    ui->btnStart->setEnabled(true);
    ui->btnEnd->setEnabled(false);
}

