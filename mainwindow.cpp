#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_serial.setPortName("com3");
    m_serial.setBaudRate(9600);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setFlowControl(QSerialPort::NoFlowControl);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    if(m_serial.isOpen()){
        ui->label_2->setText("Conexão aberta");
        return;
    }
    if(m_serial.open(QIODevice::ReadWrite)){
        ui->label_2->setText("Conexão aberta");
        m_isConected = true;
    }else{
        ui->label_2->setText("Impossível conectar");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<< "send";

    QString input = ui->lineEdit->text();
    QByteArray data = QByteArray::fromHex(input.toLocal8Bit());

    if(m_serial.write(data) == -1){
        ui->label_2->setText("erro");
        return;
    }
    if(m_serial.waitForBytesWritten(1000)){
        qDebug()<< "ok";

        ui->label_2->setText("Comando enviado!");
    }
    if(m_serial.waitForReadyRead(3000))
    {
        ui->label_2->setText("Resposta recebida");
        ui->label->setText(m_serial.readAll().toHex());
        m_serial.close();
    }
}

