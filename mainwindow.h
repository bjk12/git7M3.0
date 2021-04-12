#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog_advance.h"
#include "dialog_repeat.h"
#include "dialog_chart.h"
#include "dialog_fig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void datatochart(QString rece_data);

private slots:
    void serialPort_readyRead();

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();

    void on_moreButton_clicked();

    void on_saveButton_clicked();

    void thread_new_saveButton();

    void repeat(QByteArray data,int i);

    void bjkopenmore();
public:
    Dialog1* dlg1;
    Dialog2* dlg2;
    Dialog_advance* dlg3;
    Dialog_repeat* dlg4;
    dialog_chart* dlg_chart;
    dialog_fig* dlgfig;
private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QThread* m_currentRunLoaclThread;

};

#endif // MAINWINDOW_H
