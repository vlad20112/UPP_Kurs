#ifndef CREATEKANBAN_H
#define CREATEKANBAN_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class createKanban;
}

class createKanban : public QDialog
{
    Q_OBJECT

public:
    explicit createKanban(QWidget *parent = 0);
    ~createKanban();
signals:
    //void sendKanban(QTableWidget,QTableWidget);

private slots:
    //void on_buttonBox_accepted();

private:
    Ui::createKanban *ui;
};

#endif // CREATEKANBAN_H
