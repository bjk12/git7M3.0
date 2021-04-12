#ifndef DIALOG_REPEAT_H
#define DIALOG_REPEAT_H

#include <QDialog>

namespace Ui {
class Dialog_repeat;
}

class Dialog_repeat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_repeat(QWidget *parent = 0);
    ~Dialog_repeat();
signals:
     void repeat1(QByteArray data, int i);
private slots:
    void on_exitButton_clicked();

    void on_startButton_clicked();

private:
    Ui::Dialog_repeat *ui;
    void reject();

};

#endif // DIALOG_REPEAT_H
