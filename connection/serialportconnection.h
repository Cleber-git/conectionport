#ifndef SERIALPORTCONNECTION_H
#define SERIALPORTCONNECTION_H
#include "abstract/abstractconnection.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVector>
#include <QDebug>

class SerialPortConnection: public abstractConnection
{
public:
    SerialPortConnection();
    bool openConnection()override;
    bool sendData(QString _data, dataType _type)override;
    void refreshSerialPorts()override;
    void setPortName(QString _name)override;
    void closeConnection()override;
    QVector<QString> findSerials()override;

    QVector<QString> obterListaDeSeriais(){return m_listaDeSeriais;}
    QString AcessarDadosRecebidos();

private:
    QSerialPort m_serialPort;
    QString m_dadosRecebidos;
    QVector<QString> m_listaDeSeriais;

};

#endif // SERIALPORTCONNECTION_H
