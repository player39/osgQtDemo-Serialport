#ifndef _VIEWOSG_H
#define _VIEWOSG_H

#include "Viewer/ViewBase.h"
#include "Viewer/ViewDelta.h"
#include "viewer/ViewRec.h"
#include "Control/ControlOSGView.h"
#include <QtWidgets/QWidget>
#include <osgQt/GraphicsWindowQt>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>

class jyViewOSG :public jyViewBase<jyControlOSG>
{

public:
  jyViewOSG(jyControlOSG *mControl);
  void creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);
  QWidget * addWidget();
  void setGraphics(osgQt::GraphicsWindowQt* mGraphics);
  osgQt::GraphicsWindowQt* getGraphics();
  void ViewerFlush();

private:
  //将子节点保存到osgViewer中展示
  jyViewDelta *m_pDelta = NULL;
  jyViewRec *m_pRec = NULL;
  osgQt::GraphicsWindowQt *m_pGraphics = NULL;
  osg::ref_ptr<osg::Node> m_pNode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
  osg::ref_ptr<osgViewer::Viewer>m_pViewer = NULL;

};

#endif //_VIEWOSG_H
