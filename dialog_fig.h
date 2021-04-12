#ifndef DIALOG_FIG_H
#define DIALOG_FIG_H

#include <QWidget>

namespace Ui {
class dialog_fig;
}

class dialog_fig : public QWidget
{
    Q_OBJECT

public:
    explicit dialog_fig(QWidget *parent = nullptr);
    ~dialog_fig();

private slots:
    void on_Button_quit_clicked();
    void on_Edit_LinNum_returnPressed();

    void on_Edit_Yran_returnPressed();

    void on_Edit_Xran_returnPressed();

    void on_Edit_back_returnPressed();

public:
    void on_Replot_bjk(QString);
private:
    Ui::dialog_fig *ui;
    void showchart();
    //给曲线准备数据 设置数据
    QVector<double> x;
    QVector<double> y[10];
    int NUM_line;
    int Xrange;
    float YHrange,YLrange;
    int m_chartPoint_counter;  //计数器  一直增加 来一条数据增加一下 控制x轴前进 实现动态效果
};

#endif // DIALOG_FIG_H
