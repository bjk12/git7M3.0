#include "threadobject.h"
#include <QThread>
ThreadObject::ThreadObject(QObject *parent) : QObject(parent)
{
    m_isStop=true;
}

ThreadObject::~ThreadObject()
{
}

void ThreadObject::BjkRun()
{
    int i=0;
    if(m_isStop==true)
    {
        QMutexLocker locker(&m_stopMutex);
        m_isStop=false;
    }
    while(1)
    {
        {
            QMutexLocker locker(&m_stopMutex);
            if(m_isStop)
                break;
        }
        QThread::msleep(25);
        i++;
        if(i>10000)
            i=0;
        qDebug()<<"new thread"+QString::number(i);
    }
}

void ThreadObject::stop()
{
    QMutexLocker locker(&m_stopMutex);
    m_isStop = true;
}
