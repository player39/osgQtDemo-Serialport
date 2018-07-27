#ifndef _CONTROLWIN_H
#define _CONTROLWIN_H

#include "Control/ControlBase.h"
#include "Control/ControlDelta.h"
#include "Control/ControlRec.h"
#include "control/ControlOSGView.h"
//Qt主窗口的control 存放一个ControlOSG对象
class jyControlWin :public jyControllerBase
{
public:
  jyControlWin();
  //get
  jyControlOSG* getControlOSG();
  //set

private:
  jyControlOSG *m_pControlOSG;
};

#endif
