#ifndef _CONTROLBASE_H
#define _CONTROLBASE_H

#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "Model/Pixel.h"
#include "Viewer/ViewBase.h"

typedef boost::signals2::signal<void()>::slot_type slotType;
typedef boost::signals2::signal<void()> boostSig;

class jyControllerBase
{
public:
  jyControllerBase();
  //返回信号的引用 在View中进行绑定
  boostSig& getSigStretching();
  boostSig& getSigTranslate();
  boostSig& getSigRotate();
  boostSig& getSigReset();
  //返回矩阵
  stretching getStretching();
  translate getTranslate();
  rotateAngle getRotate();
  //对矩阵的操作
  void setStretching(float _X, float _Y, float _Z);
  void setTranslate(float _X, float _Y, float _Z);
  void setRotate(float _Angle, float _X, float _Y, float _Z);
  void Reset();

private:
  //信号
  boostSig sig_Rotate;
  boostSig sig_Stretching;
  boostSig sig_Translate;
  boostSig sig_Reset;
  //矩阵
  stretching m_sStretching;
  translate m_tTranslate;
  rotateAngle m_rRotate;

};

#endif // !_CONTROLBASE_H
