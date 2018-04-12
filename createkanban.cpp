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
