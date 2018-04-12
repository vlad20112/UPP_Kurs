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

void DialogRisk::on_buttonBox_accepted()
{
    emit sendRiskList(ui->textrisk->toPlainText(),ui->textinfo->toPlainText(),ui->textver->toPlainText(),ui->textpoter->toPlainText());
    ui->textinfo->setText("");
    ui->textrisk->setText("");
    ui->textver->setText("");
    ui->textpoter->setText("");
}
