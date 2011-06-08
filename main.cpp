#include <QtGui/QApplication>
#include "mainwindow.hpp"

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QUrl>
#include <QFileInfoList>
#include "findbrowser.hpp"

void error() {
    QTextStream out(stdout);
    out << "Usage: openin %u" << '\n' << flush;
    exit(1);
}

int main(int argc, char *argv[]) {
  QStringList arguments;
  for (int i = 0; i < argc; i++) {
    arguments << QString(argv[i]);
  }

  QUrl url;

  if (arguments.length() == 2) {
    url.setUrl(arguments.at(1));

    if (url.isValid()) {
      QApplication a(argc, argv);
      MainWindow w(arguments.at(1));
      w.show();
      return a.exec();
    }

    else error();
  }
  else error();
}
