#ifndef _CONTROLWIDGET_H
#define _CONTROLWIDGET_H

#include "Control/ControlWin.h"

class jyControlWidget :public jyControllerBase
{
public:
  jyControlWidget(jyControlOSG *control);
  jyControlOSG *getControlOSG();
private:
  jyControlOSG *m_pControlOSG=NULL;
};

#endif
