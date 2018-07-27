#ifndef _PARAMWIDGET_H
#define _PARAMWIDGET_H

#include<QtWidgets/QWidget>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QLabel>
#include<QtWidgets/QPushButton>
#include"ui_ParamWidget.h"
#include "Control/ControlWidget.h"

class jyParamWidget :public QWidget,public jyViewBase<jyControlWidget>
{

  Q_OBJECT

public:
  jyParamWidget(jyControlWidget *mControl,QObject *parent = Q_NULLPTR);

public slots:
  //Èý½Ç
  void slotChangeDeltaStretching();
  void slotChangeDeltaRotate();
  void slotChangeDeltaTranslate();
  void slotDeltaReset();
  //Ïß¶Î
  void slotChangeLineStretching();
  void slotChangeLineRotate();
  void slotChangeLineTranslate();
  void slotLineReset(); 

private:
  Ui::ParamWidget ui;
};


#endif // !_PARAMWIDGET_H
