#ifndef _VIEWERRECTANGLEGROUP_H
#define _VIEWERRECTANGLEGROUP_H

#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include "Control/ControlDelta.h"
#include "Viewer/ViewBase.h"

class jyViewDelta :public jyViewBase<jyControlDelta>
{
public:
  jyViewDelta(jyControlDelta *mControl) :jyViewBase<jyControlDelta>(mControl) { initView(); };
  //��ʼ���麯��ʵ��
  virtual void initView();
  //ʵ��һ����ת����
  virtual void updataViewRotate();
  virtual void updataViewStretching();
  virtual void updataViewTranslate();
  virtual void updataViewReset();
  void updataViewMove();
  osg::ref_ptr<osg::MatrixTransform> getRoot();
  osg::Quat HPRToQuat(double heading, double pitch, double roll);

private:
  osg::ref_ptr<osg::Node> m_pDeltaNode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pDeltaRoot = NULL;
  osg::ref_ptr<osg::Geode> m_pGeode = NULL;
  osg::ref_ptr<osg::Geometry> m_pGeometry = NULL;
  float m_lastAngle[3] = {0,0,0};
};

#endif //_VIEWERRECTANGLEGROUP_H
