#ifndef _QTSERIALPORT_H
#define _QTSERIALPORT_H

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCore/QByteArray>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <iostream>

class jyQtSerialPort :public QObject
{
  Q_OBJECT
public:
  jyQtSerialPort();
  void initPort();
  QSerialPort *getSP();
  bool ComOpen();
  bool closeCom();
  float ByteToFloat(unsigned char *data);
  bool handleData();
  bool sumCheck();

private:
  QSerialPort *m_pCom=NULL;
  QByteArray m_pData = NULL;
  QString m_sComInfo = "";

public slots:
  void slotReadData();
};

#endif //_QTSERIALPORT_H
