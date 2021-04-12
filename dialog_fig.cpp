#include "dialog_fig.h"
#include "ui_dialog_fig.h"
extern int flag_chart;
QStringList colorlist;
dialog_fig::dialog_fig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog_fig)
{
    ui->setupUi(this);
    setWindowTitle("数据可视化界面");
    m_chartPoint_counter=0;
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
    colorlist<<"orange"<<"tomato"<<"seagreen"<<"blue"<<"brown"<<"gold"<<"black"<<"chartreuse"
            <<"darkviolet"<<"cyan"<<"darkblue"<<"darkgoldenrod"<<"cyan"<<"deepskyblue"<<"green"<<"indigo"<<"lightblue";
    showchart();
}

dialog_fig::~dialog_fig()
{
    delete ui;
}

void dialog_fig::on_Button_quit_clicked()
{
    flag_chart=0;
    this->close();
    //close也是在调用reject,故无法关闭界面
}
QStringList temp1;
void dialog_fig::on_Replot_bjk(QString rece_data)
{
    //SkipEmptyParts设置跳过空格符，默认是保留空格符
    temp1.append(rece_data.split(QRegExp("[,|，|\\s|\\t|\\n]"),QString::SkipEmptyParts));
    if(temp1.size()>4)
    {
        for(int i=0;i<NUM_line;i++)
        {
            for(int j = 0; j< temp1.size()/NUM_line;++j)
            {
                //这时容器里面还没10个点 所有一直向里面存
                if(y[i].size() < Xrange)
                {
                    y[i].append(temp1.at(j*NUM_line+i).toDouble());
                    if(i==0)
                    {
                        x.append(m_chartPoint_counter);
                        m_chartPoint_counter++;
                    }
                }
                else
                {
                    //容器数据现在是正好10个  把第一个出栈  把第11个入栈  正好还是10个数据
                    y[i].removeFirst();
                    //入栈
                    y[i].append(temp1.at(j*NUM_line+i).toDouble());
//                    qDebug()<<j*NUM_line+i;
                 }  
            }
            //设置数据
            ui->customPlot->graph(i)->setData(x,y[i]);
        }
        temp1.clear();

        //重绘 每次改变完以后都要调用这个进行重新绘制
        ui->customPlot->replot(QCustomPlot::rpQueuedReplot);
    }
}

void dialog_fig::showchart()
{
    //硬件加速
    ui->customPlot->setOpenGl(true);

    //以下是图例部分
    ui->customPlot->setAutoAddPlottableToLegend(false);//禁止自动将曲线加入图例
    ui->customPlot->legend->setVisible(true);//设置图例可见
    QFont legendFont = font();  // 获得主窗口字体
    legendFont.setPointSize(9); // 调小字号
    ui->customPlot->legend->setFont(legendFont);//设为图例字体
    ui->customPlot->legend->setBrush(QBrush(QColor(255,255,255,200)));//图例为白色半透明
    //如果要将图例画在图内，用此句设置图例位置
//    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    int count = ui->customPlot->plotLayout()->rowCount();//获取布局当前行数
    ui->customPlot->legend->setBorderPen(Qt::NoPen);//无边框
    ui->customPlot->legend->setWrap(5);//每五个图例换行
    ui->customPlot->legend->setFillOrder(QCPLayoutGrid::foColumnsFirst);//列优先，即横向排列
    ui->customPlot->legend->setMargins(QMargins(60,1,50,10));//边距左上右下
    ui->customPlot->plotLayout()->addElement(count,0,ui->customPlot->legend);//将图例加入布局第count行（末行），0列，
    ui->customPlot->plotLayout()->setRowStretchFactor(count, 0.001);//设置拉伸因子

    //以下是标题
    ui->customPlot->plotLayout()->insertRow(0);     // 插入一行
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->customPlot, "数 据 实 时 可 视 化", QFont("Microsoft YaHei", 16, QFont::Bold)));  // 在第一行第一列添加标题
    //以下是背景
    ui->customPlot->axisRect()->setBackgroundScaled(true);//启用背景缩放
    ui->customPlot->axisRect()->setBackgroundScaledMode(Qt::AspectRatioMode::IgnoreAspectRatio);//自由缩放
    ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic07.jpg"));//背景图片
//  ui->customPlot->axisRect()->setBackground(QBrush(Qt::black));//背景黑色
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    /*
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);//显示x轴子网格线
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);//显示要轴子网格线
    ui->customPlot->xAxis->grid()->setZeroLinePen(QPen(Qt::white));//x轴0线颜色白色
    ui->customPlot->yAxis->grid()->setZeroLinePen(QPen(Qt::white));//y轴0线颜色白色
    */

    //以下是刻度轴
//    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);//x轴终点箭头图案
    //x,y轴对外距离
    ui->customPlot->xAxis->setPadding(0);
    ui->customPlot->yAxis->setPadding(0);
    //x,y轴对内距离
    ui->customPlot->xAxis->setOffset(0);
    ui->customPlot->yAxis->setOffset(0);
//    //设置XY轴大刻度个数
//    ui->customPlot->xAxis->ticker()->setTickCount(10);
//    ui->customPlot->yAxis->ticker()->setTickCount(10);
    //设置X轴范围
    ui->customPlot->xAxis->setRange(0,Xrange-1);
    //设置Y轴范围
    ui->customPlot->yAxis->setRange(YLrange,YHrange);
    QPen pen;
    pen.setColor(Qt::gray);//主刻度暗色
    pen.setWidth(2);//线宽3
    ui->customPlot->xAxis->setTickPen(pen);
    ui->customPlot->xAxis->setTickLengthIn(0);//主刻度向内延伸
    ui->customPlot->xAxis->setTickLengthOut(15);//主刻度向外延伸
    ui->customPlot->yAxis->setTickPen(pen);
    ui->customPlot->yAxis->setTickLengthIn(0);//主刻度向内延伸
    ui->customPlot->yAxis->setTickLengthOut(15);//主刻度向外延伸
    pen.setColor(Qt::black);//子刻度黑色
    pen.setWidth(1);//线宽1
    ui->customPlot->xAxis->setSubTickPen(pen);
    ui->customPlot->xAxis->setSubTickLengthIn(0);//子刻度向内延伸
    ui->customPlot->xAxis->setSubTickLengthOut(7);//子刻度向外延伸5
    ui->customPlot->yAxis->setSubTickPen(pen);
    ui->customPlot->yAxis->setSubTickLengthIn(0);//子刻度向内延伸
    ui->customPlot->yAxis->setSubTickLengthOut(7);//子刻度向外延伸5
//    ui->customPlot->xAxis->setTickLabels(true);//显示刻度值
//    ui->customPlot->xAxis->setTickLabelSide(QCPAxis::LabelSide::lsOutside);//显示在外部
//    ui->customPlot->yAxis->setTickLabels(true);//显示刻度值
//    ui->customPlot->yAxis->setTickLabelSide(QCPAxis::LabelSide::lsOutside);//显示在外部
//    //xy轴名字
//    ui->customPlot->xAxis->setLabel("X轴");
//    ui->customPlot->yAxis->setLabel("Y轴");
    //设置标签角度
    ui->customPlot->xAxis->setTickLabelRotation(0);

//    //设置大小
//    ui->customPlot->resize(600,400);
    //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //以下是画线
    pen.setWidth(2);
    //        SolidLine,DashLine,DotLine,DashDotLine,DashDotDotLine,CustomDashLine
    pen.setStyle(Qt::SolidLine);
    for(int i=0;i<10;i++)
    {
        pen.setColor(QColor(colorlist[i]));
        //新建曲线，四个坐标轴：xAxis（下）yAxis（左）xAxis2（上）yAxis2（右）
        ui->customPlot->addGraph(ui->customPlot->xAxis,ui->customPlot->yAxis );//自变量在底，因变量在左
        ui->customPlot->graph(i)->setPen(pen);//设置曲线颜色,宽度,线型
        //lsStepRight lsImpulse lsNone lsLine 数据点之间的插值方式,可以画出散点，折线，阶跃和脉冲图
        ui->customPlot->graph(i)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
        ui->customPlot->graph(i)->setName("第"+QString::number(i+1)+"条线");
        if(i==0)
        {
            ui->customPlot->graph(i)->setVisible(true);
            ui->customPlot->graph(i)->addToLegend();
        }
    }
    ui->Edit_LinNum->setPlaceholderText("线条个数：1");
    ui->Edit_Xran->setPlaceholderText("横坐标点数:200");
    ui->Edit_Yran->setPlaceholderText("纵坐标范围:0,3.3");
    //自动缩放以正常显示数据
//  ui->customPlot->rescaleAxes(true);
//    //重绘 每次改变完以后都要调用这个进行重新绘制
//    ui->customPlot->replot();
}

void dialog_fig::on_Edit_LinNum_returnPressed()
{
    NUM_line=ui->Edit_LinNum->text().toInt();
    if(NUM_line>10||NUM_line<1)
        NUM_line=1;
    for(int i=NUM_line;i<10;i++)
    {
        ui->customPlot->graph(i)->removeFromLegend();//将曲线移除图例
        ui->customPlot->graph(i)->setVisible(false);
        y[i].clear();
    }
    for(int i=0;i<NUM_line;i++)
    {
        ui->customPlot->graph(i)->addToLegend();//将曲线加入图例
        ui->customPlot->graph(i)->setVisible(true);
        y[i].clear();
    }
    m_chartPoint_counter=0;
    x.clear();
    ui->customPlot->replot();
}

void dialog_fig::on_Edit_Yran_returnPressed()
{
    QStringList temp=ui->Edit_Yran->text().split(",");
    YHrange=temp[1].toFloat();
    YLrange=temp[0].toFloat();
    if(YHrange<=YLrange)
    {
        YHrange=3.3;
        YLrange=0;
    }
    ui->customPlot->yAxis->setRange(YLrange, YHrange);
}

void dialog_fig::on_Edit_Xran_returnPressed()
{
    Xrange=ui->Edit_Xran->text().toInt();
    if(Xrange<1)
        Xrange=200;
    ui->customPlot->xAxis->setRange(0, Xrange-1);
    m_chartPoint_counter=0;
    x.clear();
    for(int i=0;i<NUM_line;i++)
    {
        y[i].clear();
    }
}

void dialog_fig::on_Edit_back_returnPressed()
{
    if(0==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic03.png"));
    else if(1==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic05.jpg"));
    else if(2==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic06.jpg"));
    else if(3==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic07.jpg"));
    else if(4==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic08.jpg"));
    else if(5==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic09.jpg"));
    else if(6==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/walls9.jpg"));
    else if(7==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic11.jpg"));
    else if(8==ui->Edit_back->text().toInt())
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/pic12.jpg"));
    else
        ui->customPlot->axisRect()->setBackground(QPixmap(":/image/walls5.png"));
    ui->Edit_back->clear();
    ui->customPlot->replot();
}
