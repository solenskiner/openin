#include "findbrowser.hpp"

QFileInfoList FindBrowser(){

  QDir dir("/usr/share/applications/");
  dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

  QFileInfoList filelist = dir.entryInfoList();

  QStringList   applist;

  applist << "firefox" << "chrome" << "chromium" << "opera"; // etc

  QFileInfoList filteredlist;

  QFileInfo file;
  QString app;
  foreach(file, filelist) {
    foreach(app, applist) {
      if (file.baseName() == app) filteredlist << file;
    }
  }

  return filteredlist;
}
