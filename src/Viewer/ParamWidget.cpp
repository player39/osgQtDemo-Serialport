#include "..\..\include\Viewer\ParamWidget.h"

void jyParamWidget::slotChangeDeltaRotate()
{
 getController()->getControlOSG()->getControlDelta()->setRotate(ui.lineEdit_angle->text().toFloat(), ui.lineEdit_rx->text().toFloat(), ui.lineEdit_ry->text().toFloat(), ui.lineEdit_rz->text().toFloat());
}

void jyParamWidget::slotChangeDeltaTranslate()
{
  getController()->getControlOSG()->getControlDelta()->setTranslate(ui.lineEdit_tx->text().toFloat(), ui.lineEdit_ty->text().toFloat(), ui.lineEdit_tz->text().toFloat());
}

void jyParamWidget::slotChangeDeltaStretching()
{
  getController()->getControlOSG()->getControlDelta()->setStretching(ui.lineEdit_sx->text().toFloat(), ui.lineEdit_sy->text().toFloat(), ui.lineEdit_sz->text().toFloat());
}

void jyParamWidget::slotDeltaReset()
{
  getController()->getControlOSG()->getControlDelta()->Reset();
}

void jyParamWidget::slotChangeLineStretching()
{
  getController()->getControlOSG()->getControlRec()->setStretching(ui.lineEdit_rootsx->text().toFloat(), ui.lineEdit_rootsx->text().toFloat(), ui.lineEdit_rootsx->text().toFloat());
}

void jyParamWidget::slotChangeLineRotate()
{
  getController()->getControlOSG()->getControlRec()->setRotate(ui.lineEdit_rootra->text().toFloat(), ui.lineEdit_rootrx->text().toFloat(), ui.lineEdit_rootry->text().toFloat(), ui.lineEdit_rootrz->text().toFloat());
}

void jyParamWidget::slotChangeLineTranslate()
{
 
  getController()->getControlOSG()->getControlRec()->setTranslate(ui.lineEdit_roottx->text().toFloat(), ui.lineEdit_roottx->text().toFloat(), ui.lineEdit_roottx->text().toFloat());
}

void jyParamWidget::slotLineReset()
{
  getController()->getControlOSG()->getControlRec()->Reset();
}

jyParamWidget::jyParamWidget(jyControlWidget *controller, QObject *parent):jyViewBase<jyControlWidget>(controller)
{
  ui.setupUi(this);
  //delta
  connect(ui.QPushButton_Translate, &QPushButton::clicked, this, &jyParamWidget::slotChangeDeltaTranslate);
  connect(ui.pushButton_Stretchin, &QPushButton::clicked, this, &jyParamWidget::slotChangeDeltaStretching);
  connect(ui.pushButton_Rotate, &QPushButton::clicked, this, &jyParamWidget::slotChangeDeltaRotate);
  connect(ui.pushButton_reset, &QPushButton::clicked, this, &jyParamWidget::slotDeltaReset);
  //line
  connect(ui.pushButton_dataRotate, &QPushButton::clicked, this, &jyParamWidget::slotChangeLineRotate);
  connect(ui.pushButton_dataStretching, &QPushButton::clicked, this, &jyParamWidget::slotChangeLineStretching);
  connect(ui.pushButton_dataTranslate, &QPushButton::clicked, this, &jyParamWidget::slotChangeLineTranslate);
  connect(ui.pushButton_datareset, &QPushButton::clicked, this, &jyParamWidget::slotLineReset);


}
