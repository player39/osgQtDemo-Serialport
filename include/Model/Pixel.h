#ifndef _PIXEL_H
#define _PIXEL_H

//�涥��
struct point
{
  float _x;
  float _y;
  float _z;
};
//����ת�Ǻ���ת��
struct rotateAngle
{
  float _angle;
  float _x;
  float _y;
  float _z;
  rotateAngle() :_angle(0.0), _x(0.0), _y(0.0), _z(0.0) {};
};
//�����ű���
struct stretching
{
  float _x;
  float _y;
  float _z;
  stretching() : _x(0.0), _y(0.0), _z(0.0) {};
};
//��ƽ������
struct translate
{
  float _x;
  float _y;
  float _z;
  translate() : _x(0.0), _y(0.0), _z(0.0) {};
};


#endif //_PIXEL_H
