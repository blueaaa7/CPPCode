#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



//缺省路径
void Widget::on_btnDefaultPath_clicked()
{
    QString curPath=QDir::currentPath();
    QDir dir(curPath);
    QString sub="temp";
    dir.mkdir(sub);
    ui->lineEditPath->setText(curPath+"/"+sub+"/");
}

//下载
void Widget::on_btnDownload_clicked()
{
   QString urlSpec=ui->lineEditUrl->text().trimmed();  //获取用户输入的要下载文件url
   if(urlSpec.isEmpty()){
        QMessageBox::warning(this,"error","请输入需要下载的URL");
        return;
   }
   QUrl newUrl=QUrl::fromUserInput(urlSpec);
   
   if(!(newUrl.isValid())){
    QMessageBox::warning(this,"error",
                        QString("无效的URL:%1\n错误信息:%2").arg(urlSpec,newUrl.errorString()));
        return;
   }
   
   QString tempDir=ui->lineEditPath->text().trimmed(); //获取保存下载文件的路径
   
   if(tempDir.isEmpty()){
        QMessageBox::warning(this,"error","请指定下载文件的保存路径");
        return;
   }
   
   QString fullFileName = tempDir+newUrl.fileName();
   if(QFile::exists(fullFileName)){
        QFile::remove(fullFileName); //如果文件已存在，删除
   }
   
   downloadFile=new QFile(fullFileName);
   if(!downloadFile->open(QIODevice::WriteOnly)){
        QMessageBox::warning(this,"error","临时文件打开失败");
        return;
   }
   ui->btnDownload->setEnabled(false);
   
   networkReply = networkAccessManager.get(QNetworkRequest(newUrl)); //发动网络请求，获取网络响应对象
   
   connect(networkReply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
   connect(networkReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
   connect(networkReply,SIGNAL(finished()),this,SLOT(onFinished()));
}

void Widget::onReadyRead()
{
    downloadFile->write(networkReply->readAll());
}

void Widget::onDownloadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);    
}

//网络响应结束
void Widget::onFinished()
{
    QFileInfo fileInfo;
    fileInfo.setFile(downloadFile->fileName());
    downloadFile->close();
    delete downloadFile;
    downloadFile = nullptr;
    networkReply->deleteLater();
    
    if(ui->checkBoxOpen->isChecked()){
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
        ui->btnDownload->setEnabled(true);
    }
    ui->btnDownload->setEnabled(true);
}
