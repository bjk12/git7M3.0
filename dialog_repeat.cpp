#include "dialog_repeat.h"
#include "ui_dialog_repeat.h"

Dialog_repeat::Dialog_repeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_repeat)
{
    ui->setupUi(this);
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
}

Dialog_repeat::~Dialog_repeat()
{
    delete ui;
}

void Dialog_repeat::on_exitButton_clicked()
{
    this->accept();
}

void Dialog_repeat::on_startButton_clicked()
{
    emit repeat1(ui->test1->text().toUtf8(),ui->text2->text().toInt());
}

void Dialog_repeat::reject()
{
}
