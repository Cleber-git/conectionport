#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPortInfo>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void receiverInfoSerial(const QString);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
