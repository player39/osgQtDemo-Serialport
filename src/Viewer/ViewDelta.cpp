#include "Viewer/ViewDelta.h"
#include <iostream>

void jyViewDelta::initView()
{
  m_pDeltaRoot = new osg::MatrixTransform();
  m_pGeode = new osg::Geode();
  osg::ref_ptr<osg::Geometry> _geom = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _point = new osg::Vec3Array();
  m_pDeltaRoot->addChild(m_pGeode);
  for (int i = 0; i < 3; i++)
  {
    _point->push_back(osg::Vec3(((getController()->getDeltaPoint())+i)->_x, ((getController()->getDeltaPoint()) + i)->_y, ((getController()->getDeltaPoint()) + i)->_z));
  }
  _geom->setVertexArray(_point.get());
  osg::ref_ptr<osg::Vec3Array> _line = new osg::Vec3Array();
  _line->push_back(osg::Vec3(0, -1, 0));
  _geom->setNormalArray(_line.get());
  _geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
  _geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES, 0, 3));
  osg::ref_ptr<osg::Vec4Array> _color = new osg::Vec4Array();
  _color->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _color->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _color->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _geom->setColorArray(_color);
  _geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  m_pGeode->addDrawable(_geom.get());
  this->getController()->getMoveSig().connect(boost::bind(&jyViewDelta::updataViewMove, this));
}

void jyViewDelta::updataViewRotate()
{
  m_pDeltaRoot->setMatrix(m_pDeltaRoot->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(getController()->getRotate()._angle), getController()->getRotate()._x, getController()->getRotate()._y, getController()->getRotate()._z));
}

void jyViewDelta::updataViewStretching()
{
  m_pDeltaRoot->setMatrix(m_pDeltaRoot->getMatrix()*osg::Matrix::scale(getController()->getStretching()._x, getController()->getStretching()._y, getController()->getStretching()._z));
}

void jyViewDelta::updataViewTranslate()
{
  m_pDeltaRoot->setMatrix(m_pDeltaRoot->getMatrix()*osg::Matrix::translate(getController()->getTranslate()._x, getController()->getTranslate()._y, getController()->getTranslate()._z));
}

void jyViewDelta::updataViewReset()
{
  m_pDeltaRoot->setMatrix(osg::Matrix());
}

void jyViewDelta::updataViewMove()
{
 // m_lastMatrix = m_pDeltaRoot->getMatrix();
  m_pDeltaRoot->setMatrix(m_pDeltaRoot->getMatrix()*osg::Matrix::rotate(HPRToQuat(this->getController()->getMoveXYZ()[2]-m_lastAngle[2], this->getController()->getMoveXYZ()[1]- m_lastAngle[1], this->getController()->getMoveXYZ()[0]- m_lastAngle[0]))*osg::Matrix::translate(getController()->getTranslate()._x, getController()->getTranslate()._y, getController()->getTranslate()._z));
 // m_pDeltaRoot->setMatrix(m_pDeltaRoot->getMatrix()*osg::Matrix::translate(getController()->getTranslate()._x, getController()->getTranslate()._y, getController()->getTranslate()._z));
 // osg::Matrix t1(m_pDeltaRoot->getMatrix().getTrans());
  m_lastAngle[0] = this->getController()->getMoveXYZ()[0];
  m_lastAngle[1] = this->getController()->getMoveXYZ()[1];
  m_lastAngle[2] = this->getController()->getMoveXYZ()[2];
 // osg::Matrix _tem= m_pDeltaRoot->getMatrix();
}

osg::ref_ptr<osg::MatrixTransform> jyViewDelta::getRoot()
{
  return m_pDeltaRoot.get();
}

osg::Quat jyViewDelta::HPRToQuat(double heading, double pitch, double roll)
{
  osg::Quat q(
    roll, osg::Vec3d(0.0, 1.0, 0.0),
  pitch, osg::Vec3d(1.0, 0.0, 0.0),
  heading, osg::Vec3d(0.0, 0.0, 1.0));
  
  return q;
}
