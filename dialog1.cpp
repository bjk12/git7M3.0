#include "dialog1.h"
#include "ui_dialog1.h"
#include "mainwindow.h"

int flag_chart=0;

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags
                    &~(
                        //这里是禁止的按钮
                        Qt::WindowContextHelpButtonHint|
                        //Qt::WindowMaximizeButtonHint|
                        //Qt::WindowMinimizeButtonHint|
                        Qt::WindowCloseButtonHint
                        )
                    |(
                        //这里是允许的按钮
                       Qt::WindowMaximizeButtonHint|
                       Qt::WindowMinimizeButtonHint
                        )
                   );
    ptr= (MainWindow*)parentWidget();

    ui->advanceButton->setEnabled(false);
    ui->repeatButton->setEnabled(false);
    ui->ontime1Button->setEnabled(false);
    ui->chartButton->setEnabled(false);
    ui->Button_thread1->setEnabled(false);
    ui->Button_thread1->setEnabled(false);

}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::reject()
{
    //QDialog::reject();
}

void Dialog1::on_pushButton_clicked()
{
    emit d1closed();
    //this->close();
    //close也是在调用reject,故无法关闭界面
    this->accept();
}


void Dialog1::on_okButton_clicked()
{
    if(((ui->name1->text()==QString("启蒙"))&&(ui->password->text()==QString("321930")))||
            ((ui->name1->text()==QString("祁萌"))&&(ui->password->text()==QString("123")))||
            ((ui->name1->text()==QString("拆患"))&&(ui->password->text()==QString("1")))
      )
    {
        ui->advanceButton->setEnabled(true);
        ui->repeatButton->setEnabled(true);
        ui->ontime1Button->setEnabled(true);
        ui->chartButton->setEnabled(true);
        ui->Button_thread1->setEnabled(true);
        QMessageBox::about(this, "温馨提示", "身份确认，获得本软件高级功能使用权。");
    }
    else
    QMessageBox::about(this, "温馨提示", "账号或密码输入错误。");
}

void Dialog1::on_advanceButton_clicked()
{
    ui->password->clear();
//    ui->advanceButton->setEnabled(false);
    ptr->dlg3->setModal(false);
    ptr->dlg3->show();
}

void Dialog1::on_ontime1Button_clicked()
{
    ui->password->clear();
//    ui->ontime1Button->setEnabled(false);
    ptr->dlg2->setModal(false);
    ptr->dlg2->show();
}

void Dialog1::on_repeatButton_clicked()
{
    ui->password->clear();
//    ui->repeatButton->setEnabled(false);
    ptr->dlg4->setModal(false);
    ptr->dlg4->show();
}


void Dialog1::on_chartButton_clicked()
{
    flag_chart=1;
    ui->password->clear();
    //ui->chartButton->setEnabled(false);
    //关闭半模态，若开启则主界面被阻塞，但show（）后面的程序会直接执行
    ptr->dlg_chart->setModal(false);
    ptr->dlg_chart->show();
}

void Dialog1::on_Button_thread1_clicked()
{
    dlg1 =new dialog_thread1(this);
    dlg1->setModal(true);
    dlg1->show();
}

void Dialog1::on_Button_fig_clicked()
{
     flag_chart=2;
     //QWidght 模态框
     ptr->dlgfig->setAttribute(Qt::WA_ShowModal, false);
     ptr->dlgfig->setAttribute(Qt::WA_DeleteOnClose,false);
     ptr->dlgfig->show();
}
