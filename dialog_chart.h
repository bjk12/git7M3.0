#ifndef DIALOG_CHART_H
#define DIALOG_CHART_H

#include <QDialog>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class dialog_chart;
}

class dialog_chart : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_chart(QWidget *parent = nullptr);
    ~dialog_chart();
public:
    void dataofchart(QString rece_data);

private slots:
    void on_quitButton_clicked();

    void on_Edit_NUMline_returnPressed();

    void on_Edit_Xrange_returnPressed();

    void on_Edit_Yrange_returnPressed();

    void on_Edit_theme_returnPressed();

private:
    Ui::dialog_chart *ui;
    void reject();
    QChart* chart;
    QList <QLineSeries *> serieslist;
    QLineSeries * series;
    QValueAxis* axisX;
    QValueAxis* axisY;
    int NUM_line;
    int Xrange;
    float YHrange,YLrange;
};

#endif // DIALOG_CHART_H
