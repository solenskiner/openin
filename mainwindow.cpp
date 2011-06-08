/***************************************************************************
 *   Copyright (C) 2010 by Henrik Asp                                      *
 *   solenskiner@gmail.com                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QApplication>
#include "mainwindow.hpp"
#include "findbrowser.hpp"
#include "browsericon.hpp"
#include "iconsize.hpp"
#include <QPushButton>
#include <QList>
#include <QProcess>
#include <QProcess>

MainWindow::MainWindow(QString url) : QDialog(0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
  layout = new QHBoxLayout;
  setLayout(layout);

  QFileInfo Browser;
  QFileInfoList BrowserList = FindBrowser();

  foreach(Browser, BrowserList) {
    buttons.append(new BrowserIcon(Browser, url, this));
    layout->addWidget(buttons.last());
    connect(buttons.last(), SIGNAL(clicked()), this, SLOT(exec()));
  }

  QPushButton *close = new QPushButton(QIcon::fromTheme("exit"), "", this);
  close->setIconSize(QSize(ICONSIZE,ICONSIZE));
  close->setFixedSize(QSize(ICONSIZE,ICONSIZE));
  layout->addWidget(close);
  connect(close, SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::exec() {
    QStringList *arguments = new QStringList(static_cast<BrowserIcon*>(QObject::sender())->exec.split(" "));
    QProcess * process = new QProcess(this);
    process->startDetached(arguments->first(), arguments->mid(1));
    delete arguments;
    delete process;
    close();
}

void MainWindow::close() {
  exit(0);
}
