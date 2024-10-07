#ifndef ABSTRACTCONNECTION_H
#define ABSTRACTCONNECTION_H
#include <QString>
#include <QByteArray>
#include <QVector>

class abstractConnection
{
public:
    enum dataType{
        VERIFY,
        OPEN
    };
    virtual bool openConnection()=0;
    virtual bool sendData(QString _data, dataType _type)=0;
    virtual void refreshSerialPorts()=0;
    virtual void closeConnection()=0;
    virtual QVector<QString> findSerials()=0;
    virtual void setPortName(QString _name)=0;
};

#endif // ABSTRACTCONNECTION_H
