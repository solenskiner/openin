#ifndef BROWSERICON_HPP
#define BROWSERICON_HPP

#include <QPushButton>
#include <QString>
#include <QFileInfo>

QString findExec(QFileInfo f, QString path);

class BrowserIcon : public QPushButton {
  Q_OBJECT
  public:
    BrowserIcon(QFileInfo f, QString url, QWidget *parent);
    QString exec;
};

#endif // BROWSERICON_HPP
