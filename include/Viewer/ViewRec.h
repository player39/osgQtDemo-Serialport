#ifndef _VIEWREC_H 
#define _VIEWREC_H

#include "Viewer/ViewBase.h"
#include "Control/ControlRec.h"
#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>

class jyViewRec :public jyViewBase<jyControlRec>
{

public:
  jyViewRec(jyControlRec *mControl) :jyViewBase<jyControlRec>(mControl) { initView(); };
  //��ʼ���麯��ʵ��
  virtual void initView();
  //ʵ��һ����ת����
  virtual void updataViewRotate();
  virtual void updataViewStretching();
  virtual void updataViewTranslate();
  virtual void updataViewReset();
  osg::ref_ptr<osg::MatrixTransform> getRoot();

private:
  osg::ref_ptr<osg::Node> m_pRecNode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRecRoot = NULL;
  osg::ref_ptr<osg::Geode> m_pGeode = NULL;
  osg::ref_ptr<osg::Geometry> m_pGeometry = NULL;
};
#endif //_VIEWREC_H