#include "control/ControlDelta.h"

jyControlDelta::jyControlDelta()
{
  m_pDelta[0]._x = -1;
  m_pDelta[0]._y = 0;
  m_pDelta[0]._z = 0;

  m_pDelta[1]._x = 1;
  m_pDelta[1]._y = 0;
  m_pDelta[1]._z = 0;

  m_pDelta[2]._x = 0;
  m_pDelta[2]._y = 0;
  m_pDelta[2]._z = 1.7f;
  m_pCom = new QSerialPort();

  initPort();
  ComOpen();
  connect(m_pCom, &QSerialPort::readyRead, this, &jyControlDelta::slotReadData);
}

point * jyControlDelta::getDeltaPoint()
{
  return m_pDelta;
}

void jyControlDelta::setDeltaPoint(point deltapoint[3])
{
  for (int i = 0; i < 3; ++i)
  {
    m_pDelta[i] = deltapoint[i];
  }
}

void jyControlDelta::initPort()
{
  foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
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

QSerialPort * jyControlDelta::getSP()
{
  return m_pCom;
}

bool jyControlDelta::ComOpen()
{
  if (m_pCom->open(QIODevice::ReadOnly))
  {
    return false;
  }
  return m_pCom->isOpen();
}

bool jyControlDelta::closeCom()
{
  m_pCom->close();
  return m_pCom->isOpen();
}

float jyControlDelta::ByteToFloat(unsigned char * data)
{
  float result;
  unsigned char *p;
  p = (unsigned char *)& result;
  *p = *data; *(p + 1) = *(data + 1); *(p + 2) = *(data + 2); *(p + 3) = *(data + 3);
  qDebug() << result << "  result";
  return result;
}

bool jyControlDelta::handleData()
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
      m_fmoveXYZ[n] = _tem / 32768.0 * 16 * 9.8;
      ++n;
    }
    m_pData.remove(0, 9);
  //qDebug() << m_fmoveXYZ[0] << m_fmoveXYZ[1] << m_fmoveXYZ[2];
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
      m_fRotateXYZ[n] = _tem / 32768.0 * 180;
      ++n;
    }
    qDebug() << m_fRotateXYZ[0] << m_fRotateXYZ[1] << m_fRotateXYZ[2];
  }
  else
  {
    return false;
  }
  moveDelta();
  return true;
}

bool jyControlDelta::sumCheck()
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

boostSig & jyControlDelta::getMoveSig()
{
  return sig_Move;
}

void jyControlDelta::moveDelta()
{
  setTranslate(m_fmoveXYZ[0] / 50.0, m_fmoveXYZ[1] / 50.0, 0);
  sig_Move();
}

float * jyControlDelta::getMoveXYZ()
{
 return m_fRotateXYZ;
}

void jyControlDelta::slotReadData()
{
  // qDebug() << m_pCom->readAll().toHex();
  QByteArray _temData = m_pCom->readAll();
  // qDebug() << _temData.toHex();
  // qDebug() << _temData.size();
  if (_temData.size() > 22)
  {
    _temData.clear();
  }
  m_pData.append(_temData);
  // qDebug() << m_pData.size();
 // qDebug() << m_pData.toHex();
  if (m_pData.size() == 22)
  {
      qDebug() << m_pData.toHex();
    handleData();
    m_pData.clear();
  }
}

