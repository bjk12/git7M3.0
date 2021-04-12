#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent>
#include <QThread>

//#include <windows.h>

QString byteArray,rece_data1;
QByteArray rece_data;

extern int flag1,flag2,flag_chart;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //去掉最大化最小化按钮，保留关闭按钮
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);

    dlg1=new Dialog1(this);
    dlg2=new Dialog2(this);
    dlg3=new Dialog_advance(this);
    dlg4=new Dialog_repeat(this);
    dlg_chart=new dialog_chart(this);
    dlgfig=new dialog_fig();
    //连接信号和槽
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);
    QObject::connect(dlg1, &Dialog1::d1closed, this, &MainWindow::bjkopenmore);
    QObject::connect(dlg2, &Dialog2::calltime1, this, &MainWindow::thread_new_saveButton);
    QObject::connect(dlg3, &Dialog_advance::start_urat, this, &MainWindow::on_openButton_clicked);
    QObject::connect(dlg3, &Dialog_advance::end_uart, this, &MainWindow::on_openButton_clicked);
    QObject::connect(dlg4, &Dialog_repeat::repeat1, this, &MainWindow::repeat);
    //禁用发送按键
    ui->sendButton->setEnabled(false);
    //设定默认波特率1152000
    ui->baud_rate->setCurrentIndex(13);
    ui->recvText->document()->setMaximumBlockCount(30001);
    ui->clearBox->setCheckState(Qt::Checked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serialPort_readyRead()
{
    //从接收区中读取数据
    rece_data = serial.readAll();
    if(flag_chart==1)
    {
        if(!rece_data.isEmpty())
        {
            byteArray.append(QString(rece_data));
            if(byteArray.contains("\n"))
            {
                rece_data1=byteArray.left(byteArray.lastIndexOf('\n')+1);
                byteArray = byteArray.right(byteArray.length()-byteArray.lastIndexOf('\n')-1);
                QtConcurrent::run(dlg_chart, &dialog_chart::dataofchart,rece_data1);
            }
        }
    }
    if(flag_chart==2)
    {
        if(!rece_data.isEmpty())
        {
            byteArray.append(QString(rece_data));
            if(byteArray.contains("\n"))
            {
                rece_data1=byteArray.left(byteArray.lastIndexOf('\n')+1);
                byteArray = byteArray.right(byteArray.length()-byteArray.lastIndexOf('\n')-1);
                QtConcurrent::run(dlgfig, &dialog_fig::on_Replot_bjk,rece_data1);
            }
        }
    }
    if(ui->clearBox->isChecked())
    {

        ui->recvText->clear();
        QThread::msleep(3);

    }
    else
    {
        QElapsedTimer timer;
        timer.start();
        //从界面中读取以前收到的数据
        QString recv = ui->recvText->toPlainText();
        recv += rece_data;
        //清空以前的显示
        ui->recvText->clear();
        //重新显示
        ui->recvText->appendPlainText(recv);
//        qDebug()<<timer.elapsed()<<"ms";
    }
//    emit datatochart(rece_data1);
}
void MainWindow::on_searchButton_clicked()
{
    ui->portName->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portName->addItem(info.portName());
    }
}
void MainWindow::on_openButton_clicked()
{
    if(ui->openButton->text()==QString("打开串口"))
    {
        //输入串口代号
        serial.setPortName(ui->portName->currentText());
        //输入波特率
        serial.setBaudRate(ui->baud_rate->currentText().toInt());
        //输入数据位数
        switch(ui->dataBits->currentIndex())
        {
        case 0: serial.setDataBits(QSerialPort::Data8); break;
        case 1: serial.setDataBits(QSerialPort::Data7); break;
        case 2: serial.setDataBits(QSerialPort::Data6); break;
        case 3: serial.setDataBits(QSerialPort::Data5); break;
        default: break;
        }
        //确认奇偶校验位
        switch(ui->Parity->currentIndex())
        {
        case 0: serial.setParity(QSerialPort::NoParity); break;
        case 1: serial.setParity(QSerialPort::OddParity); break;
        case 2: serial.setParity(QSerialPort::EvenParity); break;
        default: break;
        }
        //确认停止位
        switch(ui->stopBits->currentIndex())
        {
        case 0: serial.setStopBits(QSerialPort::OneStop); break;
        case 1: serial.setStopBits(QSerialPort::TwoStop); break;
        default: break;
        }
        //设置流控制
        switch(ui->flowControl->currentIndex())
        {
        case 0: serial.setFlowControl(QSerialPort::NoFlowControl); break;
        case 1: serial.setFlowControl(QSerialPort::SoftwareControl); break;
        case 2: serial.setFlowControl(QSerialPort::HardwareControl); break;
        default: break;
        }
        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox::about(NULL, "温馨提示", "无法打开串口，请重试。");
            flag1=0;
            return;
        }
        //下拉菜单控件失能
        ui->portName->setEnabled(false);
        ui->baud_rate->setEnabled(false);
        ui->dataBits->setEnabled(false);
        ui->Parity->setEnabled(false);
        ui->stopBits->setEnabled(false);
        ui->searchButton->setEnabled(false);
        ui->flowControl->setEnabled(false);
        ui->moreButton->setEnabled(false);
        ui->openButton->setText(QString("关闭串口"));
        //使能发送按键
        ui->sendButton->setEnabled(true);
    }
    else
    {
        //关闭串口
        serial.close();
        //下拉菜单控件使能
        ui->portName->setEnabled(true);
        ui->baud_rate->setEnabled(true);
        ui->dataBits->setEnabled(true);
        ui->Parity->setEnabled(true);
        ui->stopBits->setEnabled(true);
        ui->searchButton->setEnabled(true);
        ui->flowControl->setEnabled(true);
        ui->moreButton->setEnabled(true);
        ui->openButton->setText(QString("打开串口"));
        //禁用发送按键
        ui->sendButton->setEnabled(false);
    }
}
void MainWindow::on_sendButton_clicked()
{
    //获取待发送的数据并转换成utf8格式的字节流
    QByteArray data = ui->sendText->toPlainText().toUtf8();
    if(ui->newlineBox->isChecked())
    {
        data.append("\n");
    }
    serial.write(data);
}
void MainWindow::on_clearButton_clicked()
{
    ui->recvText->clear();
}

void MainWindow::on_saveButton_clicked()
{    QString recv = ui->recvText->toPlainText();
     if(flag2==0)
     {
         ui->sendText->setPlainText("温馨提示,接收区数据以文本文档格式保存在电脑桌面处。");
     }
     else
     {
         //定时保存的话就不用弹出消息框了
         flag2=0;
         ui->recvText->clear();
     }
    QString m_strDate,m_strTime;
    QDateTime curDateTime=QDateTime::currentDateTime();
    m_strDate=curDateTime.toString("yyyy-MM-dd");         //格式化日期
    m_strTime=curDateTime.toString("hh时mm分ss秒");         //格式化时间
    m_strTime="\\"+m_strTime+"_uart.txt";
    QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QFile file1(location+m_strTime);
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream txtOutput(&file1);
    txtOutput <<recv<< endl;
    file1.close();
}

void MainWindow::thread_new_saveButton()
{
    QtConcurrent::run(this, &MainWindow::on_saveButton_clicked);
    QThread::usleep(400);
}

void MainWindow::repeat(QByteArray data, int i)
{
    int x=0;
    if(ui->newlineBox->isChecked())
    {
        data.append("\n");
    }
    for(;x<i;x++)
    {
        serial.write(data);
        QElapsedTimer time;
        time.start();
        while(time.elapsed() < 100){             //等待时间流逝100毫秒
            QCoreApplication::processEvents();   //处理事件
        }
    }
}

void MainWindow::bjkopenmore()
{
   ui->moreButton->setEnabled(true);
}

void MainWindow::on_moreButton_clicked()
{
    dlg1->setModal(false);
    dlg1->show();
    ui->moreButton->setEnabled(false);
}
