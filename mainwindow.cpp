#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dialog = new Dialog();

    connect(this, SIGNAL(sendPortalInfo(const QString)), m_dialog, SLOT(receiverInfoSerial(const QString)));

    m_serialPortConnection.refreshSerialPorts();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(m_serialPortConnection.openConnection()){
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
    if(!m_serialPortConnection.sendData(input, SerialPortConnection::OPEN)){
        ui->label_2->setText("Erro");
        return;
    }
    ui->label_2->setText("Resposta recebida");
    ui->label->setText(m_serialPortConnection.AcessarDadosRecebidos());
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    m_serialPortConnection.setPortName(arg1);
}

void MainWindow::on_pushButton_3_clicked()
{
    m_serialPortConnection.refreshSerialPorts();
    auto serialPortsInfo = m_serialPortConnection.obterListaDeSeriais();
    if( serialPortsInfo.size() == 0 ){
        ui->comboBox->clear();
    }

    for (const QString &portInfo: serialPortsInfo) {
        if(!isExist(portInfo, ui->comboBox)){
            ui->comboBox->addItem(portInfo);
        }
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

    if(!m_serialPortConnection.sendData(input, SerialPortConnection::VERIFY)){
        ui->label_2->setText("Erro");
        return;
    }
        ui->label_2->setText("Resposta recebida");
        ui->label->setText(m_serialPortConnection.AcessarDadosRecebidos());
}

















