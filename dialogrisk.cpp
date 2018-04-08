#include "dialogrisk.h"
#include "ui_dialogrisk.h"

DialogRisk::DialogRisk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRisk)
{
    ui->setupUi(this);
}

DialogRisk::~DialogRisk()
{
    delete ui;
}

/*DialogRisk::onSendData(QString n1, QString n2, QString n3, QString n4)
{
    emit sendDate(ui->textrisk->toPlainText(),ui->textinfo->toPlainText(),ui->textver->toPlainText(),ui->textpoter->toPlainText());
}*/
