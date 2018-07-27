#include "Viewer/OSGQtWindow.h"
#include "Control/ControlWin.h"
#include "Viewer/QtSerialPort.h"

int main(int argc, char** argv)
{
  //³õÊ¼»¯
  QApplication app(argc, argv);
  jyControlWin *MainControl = new jyControlWin;
  jyOSGQtWindow *Qtwin = new jyOSGQtWindow(MainControl);
  Qtwin->show();
  //jyQtSerialPort *test = new jyQtSerialPort();
  return app.exec();
}

