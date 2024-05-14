#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <qfile.h>
#include <qdir.h>
#include <qurl.h>
#include <qmessagebox.h>
#include <QFileInfo>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    //自定义槽函数
    void onReadyRead();
    void onDownloadProgress(qint64 bytesRead,qint64 totalBytes);
    void onFinished();
    
    void on_btnDefaultPath_clicked();
    
    void on_btnDownload_clicked();
    
private:
    Ui::Widget *ui;
    QNetworkAccessManager networkAccessManager; //网络管理
    QNetworkReply* networkReply; //网络响应
    QFile* downloadFile; //保存临时下载文件
    
    
};
#endif // WIDGET_H
