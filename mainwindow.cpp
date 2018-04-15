#include "mainwindow.h"
#include <QString>
#include <QDebug>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include "ui_mainwindow.h"
#include "dialogresourse.h"
#include "dialogrisk.h"
#include "createkanban.h"
#include <card.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initKanban();
    connect(&Resourse,&DialogResourse::sendData,this,&MainWindow::set_data);
    connect(&Risk,&DialogRisk::sendRiskList,this,&MainWindow::set_risk_list);
    //connect(&Board,&createKanban::sendKanban,this,&MainWindow::setKanban);
    //connect(ui->add_res,ui->add_res->,this,SLOT(opendialogres()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(SaveFile()));
    connect(ui->actionLoad,SIGNAL(triggered(bool)),this,SLOT(LoadFile()));
    connect(ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(AppQuit()));
    //connect(ui->edit_res,SIGNAL(clicked(bool)),this,SLOT(ChangeTable()));
    //connect(ui->createKanban,SIGNAL(clicked(bool)),this,SLOT(initKanban()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::opendialogres()
{
    connect(&Resourse,&DialogResourse::sendData,this,&MainWindow::set_data);
    Resourse.show();
}

void MainWindow::ChangeTable()
{
  /*  bool flag = ui->tableRes->property(enabled);
    QVariant prom = ~flag;
    ui->tableRes->setProperty(enabled,prom);*/
}

void MainWindow::set_risk_list(QString a, QString b, QString c, QString d)
{
    QTableWidgetItem *prom = new QTableWidgetItem(tr("%1"));
    QTableWidgetItem *prom2 = new QTableWidgetItem(tr("%1"));
    QTableWidgetItem *prom3 = new QTableWidgetItem(tr("%1"));
    QTableWidgetItem *prom4 = new QTableWidgetItem(tr("%1"));
     int aa = ui->tableWidget_2->rowCount() - 1;
    prom->setText(a);
    prom2->setText(b);
    prom3->setText(c);
    prom4->setText(d);
    ui->tableWidget_2->setItem(aa,0,prom);
    ui->tableWidget_2->setItem(aa,1,prom2);
    ui->tableWidget_2->setItem(aa,2,prom3);
    ui->tableWidget_2->setItem(aa,3,prom4);
    qDebug() << "completed";
    ui->tableWidget_2->setRowCount((ui->tableWidget_2->rowCount() + 1));

}

void MainWindow::setKanban(QTableWidget a, QTableWidget b)
{
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

    QTableWidgetItem * prom = new QTableWidgetItem(tr("%1"));
    prom->setText(name);
    ui->tableRes->setItem((ui->tableRes->rowCount() - 1),0,prom);
    QTableWidgetItem * prom2 = new QTableWidgetItem(tr("%1"));
    prom2->setText(Yname);
    ui->tableRes->setItem((ui->tableRes->rowCount() - 1),1,prom2);
    qDebug() << name;
    qDebug() << Yname;
    ui->tableRes->setRowCount((ui->tableRes->rowCount() + 1));
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

void MainWindow::on_addres_clicked()
{
    Resourse.show();
}

void MainWindow::AppQuit()
{
    QApplication::quit();

}

void MainWindow::DrawCard()
{

}


void MainWindow::on_addrisk_clicked()
{
    Risk.show();
}

void MainWindow::on_createKanban_clicked()
{
    Board.show();
}

void MainWindow::on_pushButton_clicked()
{
    //Card card1("foma",Qt::red);
    //Card::DrawCard(Kan);
    //Kan.addItem(card1);
    //ui->graphicsView_2->setScene(Kan);
}
