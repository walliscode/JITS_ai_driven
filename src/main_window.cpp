#include "main_window.h"

#include <QWidget>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
  setWindowTitle(QStringLiteral("JITS Scheduler"));
  setCentralWidget(new QWidget(this));
}
