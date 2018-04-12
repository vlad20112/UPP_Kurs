#include "mainwindow.h"
#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QApplication>
#include <QLineEdit>
#include "ui_mainwindow.h"
#include "dialogresourse.h"
#include "dialogrisk.h"
#include "createkanban.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initKanban();
    connect(ui->add_res,SIGNAL(clicked(bool)),this,SLOT(opendialogres()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(SaveFile()));
    connect(ui->actionLoad,SIGNAL(triggered(bool)),this,SLOT(LoadFile()));
    connect(ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(AppQuit()));
    connect(ui->edit_res,SIGNAL(clicked(bool)),this,SLOT(ChangeTable()));
    connect(ui->createKanban,SIGNAL(clicked(bool)),this,SLOT(initKanban()));
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

void MainWindow::ChangeTable()
{
  /*  bool flag = ui->tableRes->property(enabled);
    QVariant prom = ~flag;
    ui->tableRes->setProperty(enabled,prom);*/
}

void MainWindow::initKanban()
{
    createKanban a;
    connect(&a,SIGNAL(sendData(QTableWidget, QTableWidget)),this,SLOT(set_data(QString,QString)));
    a.exec();
    /*QPen pen(Qt::black);
    QBrush br(Qt::black);

    QGraphicsScene *q = new QGraphicsScene;
    //qreal a = 2;
    QLine f (20,20,80,80);
    q->addLine(f,pen);
    ui->graphicsView_2->setScene(q);
    //QGraphicsLineItem *a = new QGraphicsLineItem(f);
    //QSize sizer = ui->graphicsView_2->size();*/
}

void MainWindow::set_data(QString name, QString Yname)
{
    /*ui->actionSave(SaveFile);
       if(ui->actionSave->isChecked())
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
                                             tr("*.txt"));
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
 /*       QTextEdit a = new QTextEdit;
        in >> a;
        ui->tableRes->setCellWidget(0,1,a);*/
    }
}


void MainWindow::SaveFile()
{
    QString a = QFileDialog::getSaveFileName(this,tr("Какой-то текст"),"",
                                           tr("DataProject(*.txt)"));
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
void MainWindow::AppQuit()
{
    QApplication::quit();

}

void MainWindow::DrawCard()
{

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
