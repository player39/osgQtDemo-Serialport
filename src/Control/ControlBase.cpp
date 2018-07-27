#include "control/ControlBase.h"

jyControllerBase::jyControllerBase()
{
  
}

boostSig & jyControllerBase::getSigStretching()
{
  return sig_Stretching;
}

boostSig & jyControllerBase::getSigTranslate()
{
  return sig_Translate;
}

boostSig& jyControllerBase::getSigRotate()
{
  return sig_Rotate;
}

boostSig & jyControllerBase::getSigReset()
{
  return sig_Reset;
}

stretching jyControllerBase::getStretching()
{
  return m_sStretching;
}

translate jyControllerBase::getTranslate()
{
  return m_tTranslate;
}

rotateAngle jyControllerBase::getRotate()
{
  return m_rRotate;
}

void jyControllerBase::setStretching(float _X, float _Y, float _Z)
{
  m_sStretching._x = _X;
  m_sStretching._y = _Y;
  m_sStretching._z = _Z;
  sig_Stretching();
}

void jyControllerBase::setTranslate(float _X, float _Y, float _Z)
{
  m_tTranslate._x = _X;
  m_tTranslate._y = _Y;
  m_tTranslate._z = _Z;
  sig_Translate();
}

void jyControllerBase::setRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rRotate._angle = _Angle;
  m_rRotate._x = _X;
  m_rRotate._y = _Y;
  m_rRotate._z = _Z;
  sig_Rotate();
}

void jyControllerBase::Reset()
{
  m_sStretching._x = 1;
  m_sStretching._y = 1;
  m_sStretching._z = 1;
  m_tTranslate._x = 0;
  m_tTranslate._y = 0;
  m_tTranslate._z = 0;
  m_rRotate._angle = 0;
  m_rRotate._x = 0;
  m_rRotate._y = 0;
  m_rRotate._z = 0;
  sig_Reset();
}