#include "main_window.h"
#include "startup.h"

#include <directory_paths.h>

#include <QApplication>
#include <QMessageBox>

#include <QString>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  const auto dataFolder = directory_paths::getDataFolder();
  if (!jits::baseMapExists(dataFolder)) {
    const auto missing = jits::baseMapPath(dataFolder);
    const auto text = QStringLiteral("Base map file not found:\n%1\n\nAdd the file to the data folder and restart.");
    QMessageBox::critical(
        nullptr,
        QStringLiteral("JITS Scheduler"),
        text.arg(QString::fromStdString(missing.string())));
    return 1;
  }

  MainWindow window;
  window.show();
  return app.exec();
}
