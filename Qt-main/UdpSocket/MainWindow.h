#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qudpsocket.h>
#include<qlabel.h>
#include<qhostinfo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    //QUdpSocket::stateChanged(QAbstractSocket::SocketState socketState)
    void onStateChanged(QAbstractSocket::SocketState socketState);
    //QUdpSocket::readyRead()
    void onReadyRead();
    
    void on_actBind_triggered();
    
    void on_actUnbind_triggered();
    
    void on_btnSendMsg_clicked();
    
    void on_actTextClear_triggered();
    
private:
    //获取本机ip
    QString getLocalIP();
    
private:
    Ui::MainWindow *ui;
    
    QLabel* labelSocketState; //状态栏 显示 socket状态
    QUdpSocket* udpSocket;  //udp通信的套接字
    
};
#endif // MAINWINDOW_H
