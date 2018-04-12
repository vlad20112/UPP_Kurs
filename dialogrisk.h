#ifndef DIALOGRISK_H
#define DIALOGRISK_H

#include <QDialog>

namespace Ui {
class DialogRisk;
}

class DialogRisk : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRisk(QWidget *parent = 0);
    ~DialogRisk();

signals:
    void sendRiskList(QString,QString,QString,QString);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogRisk *ui;
};

#endif // DIALOGRISK_H
