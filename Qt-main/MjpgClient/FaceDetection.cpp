#include "FaceDetection.h"
#include <string>
#include <vector>
#include <QTime>
FaceDetection::FaceDetection(QObject *parent)
    : QObject{parent}
{
    
}

void FaceDetection::onFaceDetection(QImage img)
{
//    qDebug()<<"进来了";
    //将图像转换为RGB24位色
    QImage image=img.convertToFormat(QImage::Format_RGB888);
    //将QImage格式转换为Mat格式
    Mat matImg=Mat(image.height(),image.width(),CV_8UC3,image.bits(),image.bytesPerLine());
    
    //将图片做灰度处理
    Mat imgGray;
    cvtColor(matImg,imgGray,COLOR_RGB2GRAY);
    //加载视觉分类器
    CascadeClassifier faceDetector;  //创建分类器
    
    std::string detectorPath="../MjpgClient/haarcascade_frontalface_default.xml";
    //加载分类器
    faceDetector.load(detectorPath);
    //创建向量容器 保存检测到的人脸数据
    std::vector<Rect> faces;
    //直方图均衡化
    equalizeHist(imgGray,imgGray);
    //多尺寸检测人脸
    faceDetector.detectMultiScale(
                                    imgGray, //检测的输入图像 灰度图
                                    faces,      // 保存检测到的人脸数据的向量
                                    1.1,        //每次图像尺寸减小的比例
                                    3,          //至少检测3次
                                    0,
                                    Size(30,30)  //目标最小尺寸
                                    ); 
    
//     qDebug()<<faces.size();
    if(!faces.empty()){
        QString str="检测到"+QString::number(faces.size())+"人进入监控区域";
        emit faceInto();
        qDebug()<<str<<" "<<"emit了"<<QTime::currentTime();
    }
//    else{
//        qDebug()<<"执行到onFaceDetection 未检测到人脸";
//    }
    
}

