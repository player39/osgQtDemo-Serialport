#include "..\..\include\Viewer\QtSerialPort.h"

jyQtSerialPort::jyQtSerialPort()
{
  m_pCom = new QSerialPort();
//  m_pData = new QByteArray();
  initPort();
  ComOpen();
  connect(m_pCom, &QSerialPort::readyRead, this, &jyQtSerialPort::slotReadData);
}

void jyQtSerialPort::initPort()
{
  //int _num = 0;
  foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
  {
    m_sComInfo.append(info.portName());
  }

  m_pCom->setPort(QSerialPortInfo(m_sComInfo));
  m_pCom->setBaudRate(QSerialPort::Baud115200);
  m_pCom->setDataBits(QSerialPort::Data8);
  m_pCom->setStopBits(QSerialPort::OneStop);
  m_pCom->setFlowControl(QSerialPort::NoFlowControl);
  m_pCom->setParity(QSerialPort::NoParity);
}

QSerialPort * jyQtSerialPort::getSP()
{
  return m_pCom;
}

bool jyQtSerialPort::ComOpen()
{
  if (m_pCom->open(QIODevice::ReadOnly))
  {
    return false;
  }
  return m_pCom->isOpen();
}

bool jyQtSerialPort::closeCom()
{
  m_pCom->close();
  return m_pCom->isOpen();
}

float jyQtSerialPort::ByteToFloat(unsigned char * data)
{
  float result;
  unsigned char *p;
  p = (unsigned char *)& result;
  *p = *data; *(p + 1) = *(data + 1); *(p + 2) = *(data + 2); *(p + 3) = *(data + 3);
  qDebug() << result << "  result";
  return result;
}

bool jyQtSerialPort::handleData()
{
  //去掉头尾
  if (sumCheck())
  {
    m_pData.remove(0, 2);
    float _temAXYZ[3];
    int n = 0;
    for (int i = 1; i < 6; i = i + 2)
    {
      short k = (unsigned char)m_pData[i];
      short j = (unsigned char)m_pData[i - 1];
      short _tem = ((k << 8) | j);
      _temAXYZ[n]=_tem / 32768.0 * 16 * 9.8;
      ++n;
    }
    m_pData.remove(0, 9);
    qDebug() << _temAXYZ[0] << _temAXYZ[1] << _temAXYZ[2];
  }
  else
  {
    return false;
  }
  if (sumCheck())
  {
    m_pData.remove(0, 2);
    float _temRPY[3];
    int n = 0;
    for (int i = 1; i < 6; i = i + 2)
    {
      short k = (unsigned char)m_pData[i];
      short j = (unsigned char)m_pData[i - 1];
      short _tem = ((k << 8) | j);
      _temRPY[n] = _tem / 32768.0 * 180;
      ++n;
    }
    qDebug() << _temRPY[0] << _temRPY[1] << _temRPY[2];
  }
  else
  {
    return false;
  }
  return true;
}

bool jyQtSerialPort::sumCheck()
{
  int _sum = 0;
  //检验和
  for (int i = 0; i < 10; ++i)
  {
    //取检验和
    _sum += (int)(unsigned char)m_pData[i];
  }
  //校验位为2位 超过255就减掉
  if (_sum > 256)
  {
    int flag = _sum / 256;
    _sum = _sum - 256 * flag;
  }

  if (_sum - (int)(unsigned char)m_pData[10])
  {
    return false;
  }

  return true;
}

void jyQtSerialPort::slotReadData()
{
 // qDebug() << m_pCom->readAll().toHex();
  QByteArray _temData = m_pCom->readAll();
 // qDebug() << _temData.toHex();
 // qDebug() << _temData.size();
  m_pData.append(_temData);
 // qDebug() << m_pData.size();
 // qDebug() << m_pData.toHex();
  if (m_pData.size() == 22)
  {
  //  qDebug() << m_pData.toHex();
    handleData();
    m_pData.clear();
  }
}
