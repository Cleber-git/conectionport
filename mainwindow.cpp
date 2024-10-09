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

    // m_serial.setBaudRate(QSerialPort::Baud9600);
    // m_serial.setParity(QSerialPort::NoParity);
    // m_serial.setStopBits(QSerialPort::OneStop);
    // m_serial.setFlowControl(QSerialPort::NoFlowControl);
    // m_serial.setDataBits(QSerialPort::Data8);


    connect(&m_serial, SIGNAL(readyRead()), this, SLOT(receiverResponse()));
    // serialPort->setPortName("COM1");  // Altere conforme necessário
    m_serial.setBaudRate(QSerialPort::Baud9600);
    m_serial.setDataBits(QSerialPort::Data8);
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

    ui->label->clear();
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
        qDebug() << m_serial.readAll().toHex();
        QString response = m_serial.readAll().toHex().size()?"Abriu":"Erro na abertura";
        ui->label->setText(response);
        m_serial.flush();
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
        if(!isExist(portInfo.portName(), ui->comboBox)){
            ui->comboBox->addItem(portInfo.portName());
        }
    }
    if(serialPortsInfo.size() == 1){
        qDebug() << "\n apenas uma porta";
        m_serial.setPortName(serialPortsInfo[0].portName());
    }
    // m_dialog->show();
}

bool MainWindow::isExist(QString arg1, QComboBox* combobox){
    if(combobox->findText(arg1) == -1){
        return false;
    }
    return true;
}

void MainWindow::on_pushButton_4_clicked()
{
    QString input = "90070201" + ui->lineEdit_2->text()+ "0003";
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
        QByteArray getRespposta = m_serial.readAll().toHex();
        QString response = (getRespposta.size() == 14)?"Verificado":"Erro ao verificar";
        qDebug() << getRespposta;
        ui->label->setText(response);
        m_serial.flush();
        // m_serial.close();,
    }

}

void MainWindow::receiverResponse(){
    while(m_serial.waitForReadyRead(1000)){
        QByteArray data = m_serial.readAll();
        if(!data.isEmpty()){
            m_buffer.append(data);

            if(isComplete(m_buffer)){
                qDebug()<< "Mensagem completa recebida:" << m_buffer.toHex();
                m_buffer.clear();
            }else{
                qDebug() << m_buffer.toHex();
                m_buffer.clear();
            }
        }
    }

}

bool MainWindow::isComplete(const QByteArray _msg){
    if(_msg.size() == 14){
        qDebug() << "Mensagem Completa";
        return true;
    }
    return false;

}
