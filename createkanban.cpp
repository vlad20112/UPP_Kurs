#include "createkanban.h"
#include "ui_createkanban.h"

createKanban::createKanban(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createKanban)
{
    ui->setupUi(this);
}

createKanban::~createKanban()
{
    delete ui;
}

/*void createKanban::on_buttonBox_accepted()
{
    emit sendKanban(ui->tableWidget,ui->tableWidget_2);
}*/
