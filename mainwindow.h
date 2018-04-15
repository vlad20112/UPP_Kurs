#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include "dialogrisk.h"
#include "dialogresourse.h"
#include "createkanban.h"
#include "card.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
      void set_data(QString name, QString value);
      void set_risk_list(QString a, QString b, QString c, QString d);
      void setKanban(QTableWidget a, QTableWidget b);
      void opendialogres();
      void SaveFile();
      void LoadFile();
      void AppQuit();
      void ChangeTable();
      void initKanban();
      void DrawCard();
  //  void on_pushButton_2_clicked();
  //  void on_pushButton_3_clicked();
      void on_addres_clicked();

      void on_addrisk_clicked();

      void on_createKanban_clicked();

      void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DialogRisk Risk;
    DialogResourse Resourse;
    createKanban Board;
    QGraphicsScene *Kan;


};

#endif // MAINWINDOW_H
