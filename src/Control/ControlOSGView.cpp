#include "..\..\include\Control\ControlOSGView.h"

jyControlOSG::jyControlOSG()
{
  //���������ʵ����
  m_pControlDelta = new jyControlDelta;
  m_pControlRec = new jyControlRec;
}

jyControlDelta * jyControlOSG::getControlDelta()
{
  return m_pControlDelta;
}

jyControlRec * jyControlOSG::getControlRec()
{
  return m_pControlRec;
}
