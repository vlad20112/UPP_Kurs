#include "mainwindow.h"
#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "dialogresourse.h"
#include "dialogrisk.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->add_res,SIGNAL(clicked(bool)),this,SLOT(opendialogres()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(SaveFile()));
    connect(ui->actionLoad,SIGNAL(triggered(bool)),this,SLOT(LoadFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::opendialogres()
{
    DialogResourse a;
    connect(&a,SIGNAL(sendData(QString,QString)),this,SLOT(set_data(QString,QString)));
    a.exec();
}


void MainWindow::set_data(QString name, QString Yname)
{
    //ui->actionSave(SaveFile);
   /*    if(ui->actionSave->isChecked())
       {
           SaveFile();
       }*/
    //ui->tableWidget->cellWidget(0,i) = name;
    //ui->tableWidget->cellWidget(1,i) = Yname;
    //qDebug() << name;
}


void MainWindow::LoadFile()
{
    QString a = QFileDialog::getOpenFileName(this,tr("Загрузить файл"),"",
                                             tr("*.dpr"));
    if(a.isEmpty())
        return;
    else
    {
        QFile file(a);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("не открывается"),
                                     file.errorString());
            return;
        }
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        //in >> ui->tableRes->cellWidget(1,1);
    }
}


void MainWindow::SaveFile()
{
    QString a = QFileDialog::getSaveFileName(this,tr("Какой-то текст"),"",
                                           tr("DataProject(*.dpr)"));
    if (a.isEmpty())
        return;
    else
    {
        QFile file(a);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("типо нельзя открыть файл"),
                                     file.errorString());
            return;
        }
        QDataStream out (&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << ui->tableRes->cellWidget(1,1);
    }
}

/*void MainWindow::addResource(DialogRisk b, int i)
{
   /*ui->tableWidget->cellWidget(0,i) = b.textEdit.бла бла бла*/
    /*ui->tableWidget->cellWidget(1,i) = b.textEdit_2.бла бла бла
}*/

/*void MainWindow::on_pushButton_2_clicked()
{
    DialogResourse a;
    connect(&a,SIGNAL(sendData(QString,QString)),this,SLOT(set_data(QString,QString)));
    a.exec();

      
    {

     //некоторые действия для добавдения ресурсов
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    DialogRisk a;
    if(a.exec())
    {
        //некоторые действия для добавдения рисков
    }
}*/
