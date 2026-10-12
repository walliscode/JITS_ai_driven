#include "main_window.h"

#include <QtTest/QtTest>

class TestMainWindow : public QObject {
  Q_OBJECT

private slots:
  void opensEmptyWindow()
  {
    MainWindow window;
    QVERIFY(window.centralWidget() != nullptr);
    QCOMPARE(window.windowTitle(), QStringLiteral("JITS Scheduler"));
  }
};

QTEST_MAIN(TestMainWindow)
#include "test_main_window.moc"
