#include "dialog_thread1.h"
#include "ui_dialog_thread1.h"
//界面
//子线程应该是为长期或者周期性需求服务的，不宜频繁开关,如果需要用线程中函数的开启和关闭代替
dialog_thread1::dialog_thread1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_thread1)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose,true);
    timer1 = new QTimer();
    timer1->setInterval(500);//0.5秒
    timer1->start();
    initalThread();
}

dialog_thread1::~dialog_thread1()
{
    timer1->stop();
    //发送finish信号，激活自杀槽
    if(thread)
    {
        thread->quit();
    }
    thread->wait();
    qDebug()<<"thread over";
    delete ui;
}

void dialog_thread1::on_Button_thread_clicked()
{
    if(thread->isRunning()==false)
    {
        //开启线程,但子线程的数据处理函数需要用槽函数激活，不然就还是运行在主线程中
        thread->start();
    }
}

void dialog_thread1::onTimeOut()
{
    t1++;
    ui->lineEdit->setText(QString::number(t1));
    if(t1>500)
        t1=0;
}

void dialog_thread1::on_Button_end_clicked()
{
    if(thread->isRunning()==true)
    {
        if(myobj)
        {
            myobj->stop();
            qDebug()<<"thread stop";
        }
    }
}

void dialog_thread1::initalThread()
{
    if(thread)
    {
        qDebug()<<"thread existed";
        return;
    }
    //堆分配一个子线程，需要为线程设置一个自杀槽，如果是QThread thread;，就要在析构函数中加quit，wait()
    thread =new QThread();
    // 新建一个 待放入子线程的类
    myobj=new ThreadObject();
    //放入子线程,但子线程未开启
    myobj->moveToThread(thread);
    //子程序结束，释放自身内存
    connect(thread,&QThread::finished,thread,&QObject::deleteLater);
    //    子程序结束，释放类内存
    connect(thread,&QThread::finished,myobj,&QObject::deleteLater);

    connect(timer1,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    //以下是激活子进程中的槽函数
    connect(this,&dialog_thread1::startThread,myobj,&ThreadObject::BjkRun);
    qDebug()<<"thread ready";
}

void dialog_thread1::on_pushButton_clicked()
{
    if(thread->isRunning()==true)
    {
        if(myobj)
        {
            emit startThread();  //启动子线程的信号
        }
    }
}
