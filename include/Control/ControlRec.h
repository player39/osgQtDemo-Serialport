#ifndef _CONTROLRECGROUP_H
#define _CONTROLRECGROUP_H
#include "Control/ControlBase.h"

class jyControlRec :public jyControllerBase
{
public:
  jyControlRec();
  void setRecPoint(point rec[2]);
  point* getRecPoint();

private:
  point m_pRec[2];
};

#endif // !_CONTROLRECGROUP_H
