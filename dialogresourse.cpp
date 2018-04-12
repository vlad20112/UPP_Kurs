#include "dialogresourse.h"
#include "ui_dialogresourse.h"

DialogResourse::DialogResourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResourse)
{
    ui->setupUi(this);
}

DialogResourse::~DialogResourse()
{
    delete ui;
}
void DialogResourse::onSendData()
{

}

void DialogResourse::on_buttonBox_accepted()
{
    emit sendData(ui->textEdit->toPlainText(), ui->textEdit_2->toPlainText());
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}
