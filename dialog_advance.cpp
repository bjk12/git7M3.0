#include "dialog_advance.h"
#include "ui_dialog_advance.h"
int flag1=0;
Dialog_advance::Dialog_advance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_advance)
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
    ui->endButton->setEnabled(false);
}

Dialog_advance::~Dialog_advance()
{
    delete ui;
}

void Dialog_advance::reject()
{
}

void Dialog_advance::on_startButton_clicked()
{
    ui->exitButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->endButton->setEnabled(true);
    time11=3600*(ui->hour1->text().toInt())+60*(ui->minute1->text().toInt());
    time22=3600*(ui->hour2->text().toInt())+60*(ui->minute2->text().toInt());
    Timer1->start();
}

void Dialog_advance::on_endButton_clicked()
{
    Timer1->stop();
    if(flag1==1)
    {
        emit end_uart();
        flag1=0;
    }
    ui->exitButton->setEnabled(true);
    ui->startButton->setEnabled(true);
    ui->endButton->setEnabled(false);
}

void Dialog_advance::on_exitButton_clicked()
{
    this->accept();
}

void Dialog_advance::on_timeout()
{
    QTime T1=QTime::currentTime();
    time0=3600*T1.hour()+60*T1.minute()+T1.second();
    if(time0>time11 && time0<time22 && flag1==0)
    {
        flag1=1;
        emit start_urat();
    }
    else if(time0>time22 && flag1==1)
    {
        flag1=0;
        emit end_uart();
        on_endButton_clicked();
    }
}
