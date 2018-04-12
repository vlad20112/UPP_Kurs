#ifndef CREATEKANBAN_H
#define CREATEKANBAN_H

#include <QDialog>

namespace Ui {
class createKanban;
}

class createKanban : public QDialog
{
    Q_OBJECT

public:
    explicit createKanban(QWidget *parent = 0);
    ~createKanban();

private:
    Ui::createKanban *ui;
};

#endif // CREATEKANBAN_H
