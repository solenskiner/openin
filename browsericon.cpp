#include "browsericon.hpp"
#include "iconsize.hpp"

#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QObject>

BrowserIcon::BrowserIcon(QFileInfo f, QString url, QWidget *parent) :
    QPushButton(QIcon::fromTheme(f.baseName()), "", parent) {
  setIconSize(QSize(ICONSIZE, ICONSIZE));
  setFixedSize(QSize(ICONSIZE,ICONSIZE));

  exec = findExec(f, url);
}

QString findExec(QFileInfo fi, QString path) {
  QFile f(fi.absoluteFilePath());
  QRegExp strip("exec=", Qt::CaseInsensitive);
  QRegExp search("exec=*", Qt::CaseInsensitive, QRegExp::Wildcard);
  QRegExp replace("%u", Qt::CaseInsensitive);

  if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
      return "";

  QTextStream in(&f);
  while (!in.atEnd()) {
      QString line = in.readLine();
      if (search.exactMatch(line)) {
        line.remove(strip);
        line.replace(replace, path);
        return line;
      }
  }
  return "";
}
