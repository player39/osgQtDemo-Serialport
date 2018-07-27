#ifndef _CONTROLOSGVIEW_H
#define _CONTROLOSGVIEW_H

#include "Control/ControlBase.h"
#include "Control/ControlRec.h"
#include "Control/ControlDelta.h"

class jyControlOSG :public jyControllerBase
{
public:
  jyControlOSG();
  jyControlDelta *getControlDelta();
  jyControlRec *getControlRec();

private:
  //´æ·ÅÁ½¸öcontrol
  jyControlDelta *m_pControlDelta;
  jyControlRec *m_pControlRec;
};

#endif //_CONTROLOSGVIEW_H
