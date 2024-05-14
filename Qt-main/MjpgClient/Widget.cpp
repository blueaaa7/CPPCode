#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    labelVector.append(ui->labeljpeg1);
    labelVector.append(ui->labeljpeg2);
    labelVector.append(ui->labeljpeg3);
    labelVector.append(ui->labeljpeg4);
    
    m_index=0;
    
    manager = new QNetworkAccessManager(this);
    thread = new QThread(this);
    detectWork = new FaceDetection;     //不能指定父对象
    detectWork->moveToThread(thread);
    connect(this,SIGNAL(imageAcquired(QImage)),detectWork,SLOT(onFaceDetection(QImage)));
    connect(detectWork,SIGNAL(faceInto()),this,SLOT(on_btnGetJpeg_clicked()));
    
    thread->start();
}

Widget::~Widget()
{
    delete ui;
    delete manager;
    thread->terminate();
    thread->wait();
}


//获取视频
void Widget::on_btnGetMjpg_clicked()
{
    // 1.准备请求包 设置URL地址 
    request.setUrl(QUrl("http://192.168.13.128:8080?action=stream")); //snapshot
    // 2.发送请求包 使用get方式请求获取视频流数据，返回专门用于接收视频流的响应对象
    mjpgReply = manager->get(request);
    // 3.当服务器发送来响应数据时，发射readyRead()信号
    connect(mjpgReply,SIGNAL(readyRead()),this,SLOT(onMjpgReadyRead()));
    qDebug()<<"获取视频";
}

//接收mjpg
void Widget::onMjpgReadyRead()
{   // 接收数据
    mjpgBuff += mjpgReply->readAll();
    //剥离图片帧
    char startFlag[3] = {(char)0xff,(char)0xd8};    //开始标记
    char endFlag[3] = {(char)0xff,(char)0xd9};      //结束标记
    
    //查找视频流数据中的开始 结束 标记
    int startIndex = mjpgBuff.indexOf(startFlag,0);
    if(startIndex == -1) //没有找到
    {
        mjpgBuff.clear();
        return; 
    } 
    
    int endIndex = mjpgBuff.indexOf(endFlag,startIndex+2);
    if(endIndex == -1) //未找到结束标记 说明还没有接收完毕
    {
        return ;
    }
    //都找到了 开始截取完整图片
    QByteArray imgBuff = mjpgBuff.mid(startIndex,endIndex+2);
    //将imgbuff变为image
    bool res = mjpgImg.loadFromData(imgBuff,"JPG");
    if(!res){
        mjpgBuff.clear();
        return;
    }
    else
    {
        ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
        emit imageAcquired(mjpgImg); //触发人脸识别
        mjpgBuff.clear();
        return;
    }
    
}


//获取快照
void Widget::on_btnGetJpeg_clicked()
{
     // 1.准备请求包 设置URL地址 
    request.setUrl(QUrl("http://192.168.13.128:8080?action=snapshot")); //snapshot
    // 2.发送请求包 使用get方式请求获取视频流数据，返回专门用于接收快照的响应对象
    jpegReply = manager->get(request);
    // 3.当服务器发送来响应数据时，发射readyRead()信号
    connect(jpegReply,SIGNAL(readyRead()),this,SLOT(onJpegReadyRead()));
    qDebug()<<"获取快照";
}



//接收快照数据
void Widget::onJpegReadyRead()
{
    // 接收数据
    jpegBuff += jpegReply->readAll();
    //剥离图片帧
    char startFlag[3] = {(char)0xff,(char)0xd8}; //开始标记
    char endFlag[3] = {(char)0xff,(char)0xd9};      //结束标记
    
    //查找视频流数据中的开始 结束 标记
    int startIndex = jpegBuff.indexOf(startFlag,0);
    if(startIndex == -1) //没有找到
    {
        jpegBuff.clear();
        return; 
    } 
    
    int endIndex = jpegBuff.indexOf(endFlag,startIndex+2);
    if(endIndex == -1) //未找到结束标记 说明还没有接收完毕
    {
        return ;
    }
    //都找到了 开始截取完整图片
    QByteArray imgBuff = jpegBuff.mid(startIndex,endIndex+2);
    //将imgbuff变为image
    bool res = jpegImg.loadFromData(imgBuff,"JPG");
    if(!res){
        jpegBuff.clear();
        return;
    }
    else
    { //加载成功 显示在label上
        labelVector[m_index]->setPixmap(QPixmap::fromImage(jpegImg.scaled(QSize(142,117),Qt::IgnoreAspectRatio)));
        m_index=(++m_index)%4;
        jpegBuff.clear();
        return;
    }
}


