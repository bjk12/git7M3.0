#ifndef DIALOG1_H
#define DIALOG1_H
class MainWindow;
#include <QDialog>
#include "dialog_thread1.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
signals:
    void d1closed();
private slots:
    void on_pushButton_clicked();

    void on_okButton_clicked();

    void on_advanceButton_clicked();

    void on_ontime1Button_clicked();

    void on_repeatButton_clicked();

    void on_chartButton_clicked();

    void on_Button_thread1_clicked();

    void on_Button_fig_clicked();

private:
    Ui::Dialog1 *ui;
    MainWindow *ptr;
    dialog_thread1* dlg1;
    void reject();
};
#endif // DIALOG1_H
