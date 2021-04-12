#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

private slots:
    void on_quitButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_timeout () ; //定时溢出处理槽函数
private:
    Ui::Dialog2 *ui;
    QTimer* Timer1;
      void reject();
      double set_times=0,time0=0;
signals:
      void calltime1();
};

#endif // DIALOG2_H
