#include "serialportconnection.h"

SerialPortConnection::SerialPortConnection(){
    refreshSerialPorts();

    m_serialPort.setBaudRate(9600);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setStopBits(QSerialPort::OneStop);
    m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
}

bool SerialPortConnection::openConnection(){
    if(m_serialPort.open(QIODevice::ReadWrite)){
        return true;
    }
    return false;
}

void SerialPortConnection::setPortName(QString _name){
    m_serialPort.setPortName(_name);
}

void SerialPortConnection::closeConnection(){
    m_serialPort.close();
}

void SerialPortConnection::refreshSerialPorts(){
    m_listaDeSeriais = findSerials();
    if(m_listaDeSeriais.size() == 1){
        m_serialPort.setPortName(m_listaDeSeriais[0]);
    }
}

bool SerialPortConnection::sendData(QString _data, dataType _type){
    QByteArray input = QByteArray::fromHex(_data.toLocal8Bit());
    if(m_serialPort.write(input)== -1){
        return false;
    }
    if(m_serialPort.waitForBytesWritten(10000)){
        qDebug() << "[ Ok ] Dados enviados";
        if(m_serialPort.waitForReadyRead(3000)){
            qDebug() << "[ Ok ] Dados recebidos";
            m_dadosRecebidos = m_serialPort.readAll();
            return true;
        }
    }
}

QVector<QString> SerialPortConnection::findSerials(){
    auto portasSeriaisDisponiveis = QSerialPortInfo::availablePorts();
    QVector<QString> nomeDasPortas;
    for(QSerialPortInfo &_ports: portasSeriaisDisponiveis){
        nomeDasPortas.push_back(_ports.portName());
    }
    return nomeDasPortas;
}

QString SerialPortConnection::AcessarDadosRecebidos(){
    QString dados = m_dadosRecebidos;
    m_dadosRecebidos.clear();
    return dados;
}
