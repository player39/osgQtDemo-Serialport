#include "Viewer/ViewRec.h"

void jyViewRec::initView()
{
  m_pRecRoot = new osg::MatrixTransform();
  m_pGeode = new osg::Geode();
  m_pRecRoot->addChild(m_pGeode);
  osg::ref_ptr<osg::Geometry> _LineGeome = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _Line = new osg::Vec3Array();
  _Line->push_back(osg::Vec3(getController()->getRecPoint()->_x, getController()->getRecPoint()->_y, getController()->getRecPoint()->_z));
  _Line->push_back(osg::Vec3(((getController()->getRecPoint())+1)->_x, ((getController()->getRecPoint()) + 1)->_y, ((getController()->getRecPoint()) + 1)->_z));
  _LineGeome->setVertexArray(_Line.get());

  osg::ref_ptr<osg::Vec3Array> _LineN = new osg::Vec3Array();
  _LineN->push_back(osg::Vec3(0.0, -1.0, 0));
  _LineGeome->setNormalArray(_LineN.get());
  _LineGeome->setNormalBinding(osg::Geometry::BIND_OVERALL);
  _LineGeome->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2));

  osg::ref_ptr<osg::Vec4Array> _color = new osg::Vec4Array();
  _color->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _LineGeome->setColorArray(_color.get());
  _LineGeome->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  m_pGeode->addDrawable(_LineGeome.get());
}

void jyViewRec::updataViewRotate()
{
  m_pRecRoot->setMatrix(m_pRecRoot->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(getController()->getRotate()._angle), getController()->getRotate()._x, getController()->getRotate()._y, getController()->getRotate()._z));
}

void jyViewRec::updataViewStretching()
{
  m_pRecRoot->setMatrix(m_pRecRoot->getMatrix()*osg::Matrix::scale(getController()->getStretching()._x, getController()->getStretching()._y, getController()->getStretching()._z));
}

void jyViewRec::updataViewTranslate()
{
  m_pRecRoot->setMatrix(m_pRecRoot->getMatrix()*osg::Matrix::translate(getController()->getTranslate()._x, getController()->getTranslate()._y, getController()->getTranslate()._z));
}

void jyViewRec::updataViewReset()
{
  m_pRecRoot->setMatrix(osg::Matrix());
}

osg::ref_ptr<osg::MatrixTransform> jyViewRec::getRoot()
{
  return m_pRecRoot;
}
