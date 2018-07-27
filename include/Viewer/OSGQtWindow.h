#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_OSGQt.h"
#include "Viewer/ParamWidget.h"
#include "Viewer/ViewBase.h"
#include "Control/ControlWin.h"
#include "viewer/ViewOSG.h"
#include "Control/ControlWidget.h"

class jyOSGQtWindow :public QMainWindow,public jyViewBase<jyControlWin>
{
  Q_OBJECT
public:
  jyOSGQtWindow(jyControlWin *mControl, QWidget *parent = Q_NULLPTR);
  ~jyOSGQtWindow();
  //��ʼ��
  void initWidget();

protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void closeEvent(QCloseEvent *event);

private:
  //�趨��ʱ�� ÿ��һ��ʱ��ˢ��һ�� ��ʾ����Ч��
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //һ������
  jyParamWidget *m_pTranslateWidget=NULL;
  //ά��һ��osg��Ⱦ��ͼ
  jyViewOSG *m_pViewOSG;

public slots:
  //��ʾ����
  void slotShowTranslateWidget(); 
};
#endif // !_OSGQtWindow_H
