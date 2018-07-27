#ifndef _VIEWBASE_H
#define _VIEWBASE_H

#include "boost/signals2.hpp"
#include "boost/bind.hpp"
#include "Control/ControlBase.h"

typedef boost::signals2::signal<void()>::slot_type slotType;

template<class ControlType>

class jyViewBase
{
public:
  jyViewBase(ControlType *mControl);
  //get
  ControlType *getController();
  //set
  void setController(ControlType *controller);
  //更新视图
  virtual void updataViewStretching();
  virtual void updataViewTranslate();
  virtual void updataViewRotate();
  virtual void updataViewReset();
  //绑定函数
   boost::signals2::connection connectStretching(const slotType &type);
   boost::signals2::connection connectRotate(const slotType &type);
   boost::signals2::connection connectTranslate(const slotType &type);
   boost::signals2::connection connectReset(const slotType &type);
  //初始化视图
  virtual void initView();

private:
  ControlType *m_pController=NULL;
  boost::signals2::connection m_conStretching;
  boost::signals2::connection m_conTranslate;
  boost::signals2::connection m_conRotate;
  boost::signals2::connection m_conReset;
};

template<class ControlType>
inline jyViewBase<ControlType>::jyViewBase(ControlType *mControl)
{
  setController(mControl);
}

template<class ControlType>
inline ControlType * jyViewBase<ControlType>::getController()
{
  return m_pController;
}

template<class ControlType>
inline void jyViewBase<ControlType>::setController(ControlType * controller)
{
  m_pController = controller;
  m_conStretching.disconnect();
  m_conTranslate.disconnect();
  m_conRotate.disconnect();
  m_conReset.disconnect();
 // m_pController->getSigRotate().connect(boost::bind(&jyViewBase::updataViewRotate, this));
  m_conStretching = connectStretching(boost::bind(&jyViewBase::updataViewStretching,this));
  m_conTranslate = connectTranslate(boost::bind(&jyViewBase::updataViewTranslate, this));
  m_conRotate = connectRotate(boost::bind(&jyViewBase::updataViewRotate, this));
  m_conReset = connectReset(boost::bind(&jyViewBase::updataViewReset, this));
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewStretching()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewTranslate()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewRotate()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewReset()
{
}

template<class ControlType>
inline boost::signals2::connection jyViewBase<ControlType>::connectStretching(const slotType & type)
{
  return m_pController->getSigStretching().connect(type);
}

template<class ControlType>
inline boost::signals2::connection jyViewBase<ControlType>::connectRotate(const slotType & type)
{
  return m_pController->getSigRotate().connect(type);
}

template<class ControlType>
inline boost::signals2::connection jyViewBase<ControlType>::connectTranslate(const slotType & type)
{
  return m_pController->getSigTranslate().connect(type);
}

template<class ControlType>
inline boost::signals2::connection jyViewBase<ControlType>::connectReset(const slotType & type)
{
  return m_pController->getSigReset().connect(type);
}

template<class ControlType>
inline void jyViewBase<ControlType>::initView()
{
}

#endif // !_VIEWBASE_H
