#include "..\..\include\Control\ControlWidget.h"

jyControlWidget::jyControlWidget(jyControlOSG *control)
{
  m_pControlOSG = control;
}

jyControlOSG * jyControlWidget::getControlOSG()
{
  return m_pControlOSG;
}
