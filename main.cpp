#include "dialog.cpp"
#include<QtGui/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Dialog window;
  window.show();

  return a.exec();
}
