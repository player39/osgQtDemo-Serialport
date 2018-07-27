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
  //�����źŵ����� ��View�н��а�
  boostSig& getSigStretching();
  boostSig& getSigTranslate();
  boostSig& getSigRotate();
  boostSig& getSigReset();
  //���ؾ���
  stretching getStretching();
  translate getTranslate();
  rotateAngle getRotate();
  //�Ծ���Ĳ���
  void setStretching(float _X, float _Y, float _Z);
  void setTranslate(float _X, float _Y, float _Z);
  void setRotate(float _Angle, float _X, float _Y, float _Z);
  void Reset();

private:
  //�ź�
  boostSig sig_Rotate;
  boostSig sig_Stretching;
  boostSig sig_Translate;
  boostSig sig_Reset;
  //����
  stretching m_sStretching;
  translate m_tTranslate;
  rotateAngle m_rRotate;

};

#endif // !_CONTROLBASE_H
