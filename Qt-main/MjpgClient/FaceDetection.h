#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <QImage>
#include <qobject.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <qmessagebox.h>
#include <qdebug.h>
using namespace cv;

class FaceDetection : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetection(QObject *parent = nullptr);
    
signals:
    void faceInto();

public slots:
    void onFaceDetection(QImage img);
   
    
};

#endif // FACEDETECTION_H
