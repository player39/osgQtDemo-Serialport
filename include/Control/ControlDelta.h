#ifndef _CONTROLDELTA_H
#define _CONTROLDELTA_H

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCore/QByteArray>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <iostream>
#include "Control/ControlBase.h"

//typedef boost::signals2::signal<void()> sigBoost;
class jyControlDelta :public QObject, public jyControllerBase
{
  
  Q_OBJECT

public:
  jyControlDelta();
  point *getDeltaPoint();
  void setDeltaPoint(point deltapoint[3]);
  void initPort();
  QSerialPort *getSP();
  bool ComOpen();
  bool closeCom();
  float ByteToFloat(unsigned char *data);
  bool handleData();
  bool sumCheck();
  boostSig &getMoveSig();
  void moveDelta();
  float* getMoveXYZ();
//  osg::Quat HPRToQuat(double heading, double pitch, double roll);

private:
  point m_pDelta[3];
  QSerialPort *m_pCom = NULL;
  QByteArray m_pData = NULL;
  QString m_sComInfo = "";
  boostSig sig_Move;
  float m_fmoveXYZ[3];
  float m_fRotateXYZ[3];

public slots:
  void slotReadData();

};
#endif // !_CONTROLDELTA_H
