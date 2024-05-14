#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qvector.h>
#include <QLabel>
#include <qnetworkaccessmanager.h>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <qurl.h>
#include <qthread.h>
#include <QDebug>
#include "FaceDetection.h"
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void imageAcquired(QImage);     //发射人脸检测信号
   
    
private slots:
    void  onMjpgReadyRead();    //接收到视频流响应数据的槽函数
    void onJpegReadyRead();     //接收到的快照的响应数据的槽函数
    
    
    void on_btnGetMjpg_clicked();
    
    void on_btnGetJpeg_clicked();
    
//    void onFaceInto();
    
private:
    Ui::Widget *ui;
    QNetworkAccessManager* manager; //管理整个通信过程
    QNetworkRequest request;        //根据url生成请求包
    QNetworkReply* mjpgReply;       //获取视频响应
    QByteArray mjpgBuff;            //保存视频响应数据
    QImage mjpgImg;                //保存从视频流中截取的图片
    
    QNetworkReply* jpegReply;    //获取快照响应数据包
    QByteArray jpegBuff;        //保存快照响应数据
    QImage jpegImg;             //保存快照照片
    
    QThread* thread;                //进行人脸检测
    FaceDetection* detectWork;      //人脸检测工作对象
    
    QVector<QLabel*> labelVector; //保存显示快照的容器
    int m_index; //索引
};
#endif // WIDGET_H
