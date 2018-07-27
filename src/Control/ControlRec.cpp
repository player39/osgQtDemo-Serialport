#include "Control/ControlRec.h"

jyControlRec::jyControlRec()
{
  m_pRec[0]._x = 2;
  m_pRec[0]._y = -2;
  m_pRec[0]._z = 2;
  m_pRec[1]._x = -2;
  m_pRec[1]._y = -2;
  m_pRec[1]._z = 2;
}

void jyControlRec::setRecPoint(point rec[2])
{
  for (int i = 0; i < 2; ++i)
  {
    m_pRec[i] = rec[i];
  }
}

point* jyControlRec::getRecPoint()
{
  return m_pRec;
}