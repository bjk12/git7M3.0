#include "dialog2.h"
#include "ui_dialog2.h"
int flag2=0;
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    Timer1=new QTimer(this);
    Timer1->stop();
    Timer1->setInterval (1000) ;
    connect(Timer1,SIGNAL(timeout()),this,SLOT(on_timeout()));
}

Dialog2::~Dialog2()
{
    delete ui;
}
void Dialog2::reject()
{
}
void Dialog2::on_quitButton_clicked()
{
    //this->close();
    //close也是在调用reject,故无法关闭界面
    this->accept();
}
void Dialog2::on_startButton_clicked()
{
    ui->quitButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    set_times=ui->time1->text().toDouble();
    QTime T1=QTime::currentTime();
    time0=(double)(3600*T1.hour()+60*T1.minute()+T1.second());
    Timer1->start();
}
void Dialog2::on_stopButton_clicked()
{
    Timer1->stop();
    ui->quitButton->setEnabled(true);
    ui->startButton->setEnabled(true);
}
void Dialog2::on_timeout()
{
        QTime T1=QTime::currentTime();
        if((3600*T1.hour()+60*T1.minute()+T1.second()-time0)>=60*set_times)
        {
            flag2=1;
            time0=(double)(3600*T1.hour()+60*T1.minute()+T1.second());
            emit calltime1();
        }
}
