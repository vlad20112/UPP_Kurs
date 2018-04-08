#ifndef DIALOG_RESOURSE_H
#define DIALOG_RESOURSE_H

#include <QDialog>

namespace Ui {
class DialogResourse;
}

class DialogResourse : public QDialog
{
    Q_OBJECT

public:

    explicit DialogResourse(QWidget *parent = 0);
    ~DialogResourse();

private:
    Ui::DialogResourse *ui;
signals:
    //void onSendData(QString a, QString b);

};

#endif // DIALOG_RESOURSE_H
