#include "startup.h"

#include <QtTest/QtTest>

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class TestStartup : public QObject {
  Q_OBJECT

private slots:
  void baseMapPathIsInsideDataFolder()
  {
    const fs::path data = "some/data";
    QCOMPARE(QString::fromStdString(jits::baseMapPath(data).string()),
             QString::fromStdString((data / "base_map.json").string()));
  }

  void baseMapMissingWhenFolderEmpty()
  {
    const fs::path dir = fs::temp_directory_path() / "jits_startup_empty";
    fs::remove_all(dir);
    fs::create_directories(dir);
    QVERIFY(!jits::baseMapExists(dir));
    fs::remove_all(dir);
  }

  void baseMapPresentWhenFileExists()
  {
    const fs::path dir = fs::temp_directory_path() / "jits_startup_present";
    fs::remove_all(dir);
    fs::create_directories(dir);
    std::ofstream(jits::baseMapPath(dir)) << "{}";
    QVERIFY(jits::baseMapExists(dir));
    fs::remove_all(dir);
  }
};

QTEST_MAIN(TestStartup)
#include "test_startup.moc"
