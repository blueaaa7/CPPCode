#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread();
    void stop();
protected:
    void run();
private:
    bool isStopped;
    int buffer[100];
    
};

#endif // WORKTHREAD_H
