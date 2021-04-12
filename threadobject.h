#ifndef THREADOBJECT_H
#define THREADOBJECT_H

#include <QMutexLocker>
#include <QObject>
#include <QMutex>

class ThreadObject : public QObject
{
    Q_OBJECT
public:
    explicit ThreadObject(QObject *parent = NULL);
    ~ThreadObject();
    void BjkRun();
    void stop();
signals:
    void progress(int present);
public slots:

private:
    bool m_isStop;
    QMutex m_stopMutex;
};

#endif // THREADOBJECT_H
