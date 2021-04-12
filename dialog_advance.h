#ifndef DIALOG_ADVANCE_H
#define DIALOG_ADVANCE_H

#include <QDialog>

namespace Ui {
class Dialog_advance;
}

class Dialog_advance : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_advance(QWidget *parent = 0);
    ~Dialog_advance();

private slots:
    void on_startButton_clicked();

    void on_endButton_clicked();

    void on_exitButton_clicked();

    void on_timeout () ; //定时溢出处理槽函数
private:
    Ui::Dialog_advance *ui;
        QTimer* Timer1;
          void reject();
          int time11=0,time22=0,time0=0,time1=0;
signals:
          void start_urat();
          void end_uart();
};

#endif // DIALOG_ADVANCE_H
