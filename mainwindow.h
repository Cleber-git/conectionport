#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "dialog.h"
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isComplete(const QByteArray _mensagem);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();
    bool isExist(QString arg1, QComboBox *combobox);

    void on_pushButton_4_clicked();

    void receiverResponse();
    void processMessage(const QByteArray &message) {
        // Aqui você pode tratar a mensagem completa recebida
        qDebug() << "Processando mensagem:" << message;
    }
signals:
    void sendPortalInfo(const QString);
private:
    Ui::MainWindow *ui;
    QSerialPort m_serial;
    bool m_isConected = false;
    Dialog *m_dialog;
    QByteArray m_buffer;

};
#endif // MAINWINDOW_H
