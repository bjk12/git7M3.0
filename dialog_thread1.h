#ifndef DIALOG_THREAD1_H
#define DIALOG_THREAD1_H

#include <QDialog>
#include <QThread>
#include "threadobject.h"

namespace Ui {
class dialog_thread1;
}

class dialog_thread1 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_thread1(QWidget *parent = nullptr);
    ~dialog_thread1();

private slots:
    void on_Button_thread_clicked();

    void onTimeOut();
    void on_Button_end_clicked();

    void on_pushButton_clicked();

signals:
    void startThread();  //启动子线程的信号
private:
    void initalThread();
    Ui::dialog_thread1 *ui;
    ThreadObject* myobj=NULL;
    QThread* thread=NULL;
    QTimer* timer1;
    int t1=0;
};

#endif // DIALOG_THREAD1_H
