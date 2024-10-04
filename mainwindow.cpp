#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dialog = new Dialog();

    connect(this, SIGNAL(sendPortalInfo(const QString)), m_dialog, SLOT(receiverInfoSerial(const QString)));

    on_pushButton_3_clicked();

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

//send and receiver data
void MainWindow::on_pushButton_2_clicked()
{

    if(ui->lineEdit->text().isEmpty()) return;
    qDebug()<< "send";

    QString input = "90060501" + ui->lineEdit->text()+ "03";
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
        // QString response = m_serial.readAll().toHex().contains(85)? "ABERTA": "ERRO";
        ui->label_2->setText("Resposta recebida");
        ui->label->setText(m_serial.readAll().toHex());
        m_serial.close();
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    m_serial.setPortName(arg1);
}

// refresh verify serialPorts availables
void MainWindow::on_pushButton_3_clicked()
{
    auto serialPortsInfo = QSerialPortInfo::availablePorts();
    if( serialPortsInfo.size() == 0 ){
        ui->comboBox->clear();
    }
    for (const QSerialPortInfo &portInfo: serialPortsInfo) {
        ui->comboBox->addItem(portInfo.portName());

    }
    if(serialPortsInfo.size() == 1){
        qDebug() << "\n apenas uma porta";
        m_serial.setPortName(serialPortsInfo[0].portName());
    }
    // m_dialog->show();
}


// lista todas as descrições de uma porta serial
/*
 *        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
*/
