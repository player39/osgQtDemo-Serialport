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
  //初始化
  void initWidget();

protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void closeEvent(QCloseEvent *event);

private:
  //设定定时器 每过一定时间刷新一次 显示控制效果
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //一个弹窗
  jyParamWidget *m_pTranslateWidget=NULL;
  //维护一个osg渲染视图
  jyViewOSG *m_pViewOSG;

public slots:
  //显示窗口
  void slotShowTranslateWidget(); 
};
#endif // !_OSGQtWindow_H
