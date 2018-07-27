#include "..\..\include\Control\ControlWin.h"

jyControlWin::jyControlWin()
{
  m_pControlOSG = new jyControlOSG;
}

jyControlOSG *jyControlWin::getControlOSG()
{
  return m_pControlOSG;
}