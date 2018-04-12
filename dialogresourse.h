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
private slots:
    void onSendData();

    void on_buttonBox_accepted();

private:
    Ui::DialogResourse *ui;
signals:
    void sendData(QString a, QString b);

};

#endif // DIALOG_RESOURSE_H
