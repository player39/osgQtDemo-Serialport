#ifndef _PIXEL_H
#define _PIXEL_H

//存顶点
struct point
{
  float _x;
  float _y;
  float _z;
};
//存旋转角和旋转轴
struct rotateAngle
{
  float _angle;
  float _x;
  float _y;
  float _z;
  rotateAngle() :_angle(0.0), _x(0.0), _y(0.0), _z(0.0) {};
};
//存缩放比例
struct stretching
{
  float _x;
  float _y;
  float _z;
  stretching() : _x(0.0), _y(0.0), _z(0.0) {};
};
//存平移坐标
struct translate
{
  float _x;
  float _y;
  float _z;
  translate() : _x(0.0), _y(0.0), _z(0.0) {};
};


#endif //_PIXEL_H
