#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMetaEnum>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actBind->setEnabled(true);
    ui->actUnbind->setEnabled(false);
    //状态栏初始化
    labelSocketState =new QLabel("Socket状态："); 
    labelSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(labelSocketState);
    //获取主机ip
    QString localIp=getLocalIP();
    setWindowTitle(windowTitle()+"--本机ip："+localIp);
    ui->cmbTargetIP->addItem(localIp);
    //创建QUdpSocket对象
    udpSocket=new QUdpSocket(this);
    
    connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
    this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




QString MainWindow::getLocalIP()
{
    QString hostName=QHostInfo::localHostName(); //获取主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);//根据主机名获取主机信息
    QString localIp="";
    QList<QHostAddress> addList=hostInfo.addresses();   //获取主机地址的列表
    if(!addList.isEmpty()){
        for(int i=0;i<addList.count();i++){
            QHostAddress addr=addList.at(i);
            if(addr.protocol()==QAbstractSocket::IPv4Protocol){
                localIp=addr.toString();
                break;
            }
        }
    }
    return localIp;
}

//绑定端口
void MainWindow::on_actBind_triggered()
{
    quint16 port=ui->spinBindPort->value();
    if(udpSocket->bind(port)){
        ui->plainTextEdit->appendPlainText("***成功绑定");
        ui->plainTextEdit->appendHtml("***绑定端口:"+QString::number(udpSocket->localPort()));
        ui->actBind->setEnabled(false);
        ui->actUnbind->setEnabled(true);
    }
    else{
        ui->plainTextEdit->appendPlainText("***绑定失败");
    }
}

//解除绑定
void MainWindow::on_actUnbind_triggered()
{
    udpSocket->abort();
    ui->actBind->setEnabled(true);
    ui->actUnbind->setEnabled(false);
    ui->plainTextEdit->appendPlainText("***已解除绑定");
}

//socket状态发生改变
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum=QMetaEnum::fromType<QAbstractSocket::SocketState>();
    const char* str=metaEnum.valueToKey(socketState);
    labelSocketState->setText("Socket状态："+QString(str));
}

//发送消息
void MainWindow::on_btnSendMsg_clicked()
{
      ui->btnSendMsg->setEnabled(false);
      QString targetIP=ui->cmbTargetIP->currentText();  //目标ip地址
      QHostAddress targetAddr(targetIP);
      quint16 targetPort=ui->spinTargetPort->value(); //目标地址端口
      QString msg=ui->editMessage->text();
      QByteArray str=msg.toUtf8();
      udpSocket->writeDatagram(str,targetAddr,targetPort); //写数据报
      ui->plainTextEdit->appendPlainText("[发送]"+msg);
//      ui->plainTextEdit->clear();
      ui->plainTextEdit->setFocus();
      ui->btnSendMsg->setEnabled(true);
} 

//接收消息 有数据待读取
void MainWindow::onReadyRead()
{
     QByteArray datagram;
     datagram.resize(udpSocket->pendingDatagramSize());
     QHostAddress peerAddr;
     quint16 peerPort;
     udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
     QString str=datagram.data();
     QString peer="from"+peerAddr.toString()+":"+QString::number(peerPort);
     ui->plainTextEdit->appendPlainText(peer+" "+str);
}


//清空文本框
void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}

