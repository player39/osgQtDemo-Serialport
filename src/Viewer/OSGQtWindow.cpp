#include "..\..\include\Viewer\OSGQtWindow.h"

jyOSGQtWindow::jyOSGQtWindow(jyControlWin* mControl, QWidget *parent):jyViewBase<jyControlWin>(mControl)
{
  //初始化将graphics设置到widget
  ui.setupUi(this);
  //
  m_pViewOSG = new jyViewOSG(this->getController()->getControlOSG());
  initWidget();
  //刷新画面
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
  connect(ui.QAction_Translate, &QAction::triggered, this, &jyOSGQtWindow::slotShowTranslateWidget);
}

jyOSGQtWindow::~jyOSGQtWindow()
{

}
//初始化窗口
void jyOSGQtWindow::initWidget()
{
  QVBoxLayout *_centralLayout = new QVBoxLayout();
  m_pViewOSG->creatGraphicsWinQt(0, 0, 800, 600, "mainViewer", false);
  _centralLayout->addWidget(m_pViewOSG->addWidget());
  ui.QWidget_LockWidget->setLayout(_centralLayout);
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
}

void jyOSGQtWindow::paintEvent(QPaintEvent * event)
{
  m_pViewOSG->ViewerFlush();
}

void jyOSGQtWindow::closeEvent(QCloseEvent *event)
{
  if (m_pTranslateWidget)
  {
    m_pTranslateWidget->close();
  }
}

void jyOSGQtWindow::slotShowTranslateWidget()
{
  //传入一个osgcontrol引用
  jyControlWidget *_pControlWidget = new jyControlWidget(m_pViewOSG->getController());
  m_pTranslateWidget = new jyParamWidget(_pControlWidget);
  m_pTranslateWidget->show();
}

