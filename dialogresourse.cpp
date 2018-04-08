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
/*void DialogResourse::onSendData()
{
    emit sendData(ui->textEdit->toPlainText(), ui->textEdit_2->toPlainText());
}*/
