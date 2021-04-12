#include "dialog_chart.h"
#include "ui_dialog_chart.h"
#include "mainwindow.h"
#include <QThread>
QQueue<double> list1;
extern int flag_chart;
dialog_chart::dialog_chart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_chart)
{
    ui->setupUi(this);

    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    NUM_line=1;
    Xrange=200;
    YHrange=3.3;
    YLrange=0;
    ui->Edit_NUMline->setPlaceholderText("线条个数：1");
    ui->Edit_Xrange->setPlaceholderText("横坐标点数:200");
    ui->Edit_Yrange->setPlaceholderText("纵坐标范围:0,3.3");
    //实例化折线类
    for(int i=0;i<10;i++)
    {
        serieslist.append(new QLineSeries());
    }
    series=serieslist[0];
    //实例化图类
    chart = new QChart();
    //将折线与图表绑定
    for(int i=0;i<10;i++)
    {
        chart->addSeries(serieslist[i]);
    }

    //开启opengl加速
    series->setUseOpenGL(true);
    series->setVisible(true);
    for(int i=1;i<10;i++)
    {
        serieslist[i]->setUseOpenGL(false);
        serieslist[i]->setVisible(false);
    }
    // 将图表绑定到视图
    ui->widget->setChart(chart);
    //抗锯齿
    ui->widget->setRenderHint(QPainter::Antialiasing);
    ui->widget->chart()->setTheme(QChart::ChartThemeHighContrast);//Light , Dark ,Brown Sand ,Blue Ncs,High Contrast,Blue Icy,Qt,BlueCerulean
    axisX = new QValueAxis(this);
    axisX->setRange(0, Xrange-1);
    axisY = new QValueAxis(this);
    axisY->setRange(YLrange, YHrange);
    //axisY->setTitleText("axisY");
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series->setName("signal_1");
    for(int i=1;i<10;i++)
    {
        serieslist[i]->attachAxis(axisX);
        serieslist[i]->attachAxis(axisY);
        serieslist[i]->setName("signal_"+ QString::number(i));
    }

// 基于已添加到图表的 series 来创建默认的坐标轴
    chart->setTitle("real_time_data_show");
    chart->setTitleFont(QFont("宋体",16));
    chart->legend()->setVisible(true);//显示图例
    chart->legend()->setAlignment(Qt::AlignBottom);
//    测试数据
//    QString rece_data="123.4 12.45 16.6\t 12.11\n 13.5 3.4 2.45 161.6\t ";
//    dialog_chart::dataofchart(rece_data);
//    QString rece_data1="3.4 2.45 161.6\t 29.11\n 3.5 123.4 12.45 16.6\t 12.11\n";
//    dialog_chart::dataofchart(rece_data1);
}

dialog_chart::~dialog_chart()
{
    delete ui;
}

void dialog_chart::reject()
{

}

void dialog_chart::on_quitButton_clicked()
{
    flag_chart=0;
    //this->close();
    //close也是在调用reject,故无法关闭界面
    this->accept();
}
QStringList temp;
void dialog_chart::dataofchart(QString rece_data)
{
    //SkipEmptyParts设置跳过空格符，默认是保留空格符
    temp.append(rece_data.split(QRegExp("[,|，|\\s|\\t|\\n]"),QString::SkipEmptyParts));
    if(temp.size()>0)
    {
        //将采集数据传入list1这个队列中
        for(int i = 0; i< temp.size();++i)
        {
            list1.enqueue(temp.at(i).toDouble());
        }
        temp.clear();
        int a=list1.count()-Xrange*NUM_line;
        //控制各个队列长度为Xrange
        if (a>0)
        {
            for(int i = 0; i< a;++i)
            {
                list1.dequeue();
            }
        }
        for(int i=0;i<NUM_line;i++)
        {
            serieslist[i]->clear();
            //将新队列数据传入折线图中
            for (int i1 = 0; i1 < list1.count()/NUM_line; i1++)
            {
                serieslist[i]->append(i1,list1.at(i1*NUM_line+i));
            }
        }
    }
}

void dialog_chart::on_Edit_NUMline_returnPressed()
{
    NUM_line=ui->Edit_NUMline->text().toInt();
    if(NUM_line>10||NUM_line<1)
        NUM_line=1;
    for(int i=NUM_line;i<10;i++)
    {
        serieslist[i]->clear();
        serieslist[i]->setUseOpenGL(false);
        serieslist[i]->setVisible(false);
    }
    for(int i=0;i<NUM_line;i++)
    {
        serieslist[i]->setUseOpenGL(true);
        serieslist[i]->setVisible(true);
    }
}

void dialog_chart::on_Edit_Xrange_returnPressed()
{
    //chart->removeAxis(axisX);
    Xrange=ui->Edit_Xrange->text().toInt();
    if(Xrange<1)
        Xrange=200;
    axisX->setRange(0, Xrange-1);
}

void dialog_chart::on_Edit_Yrange_returnPressed()
{
    QStringList temp=ui->Edit_Yrange->text().split(",");
    YHrange=temp[1].toFloat();
    YLrange=temp[0].toFloat();
    if(YHrange<=YLrange)
    {
        YHrange=3.3;
        YLrange=0;
    }
    axisY->setRange(YLrange, YHrange);
}

void dialog_chart::on_Edit_theme_returnPressed()
{
    if(0==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeHighContrast);
    else if(1==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeLight);
    else if(2==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeDark);
    else if(3==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeBrownSand);
    else if(4==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeBlueNcs);
    else if(5==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeBlueIcy);
    else if(6==ui->Edit_theme->text().toInt())
        ui->widget->chart()->setTheme(QChart::ChartThemeQt);
    else
        ui->widget->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    ui->Edit_theme->clear();
}
