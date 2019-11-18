#include "view/mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QFile>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;

    QFile stile(":/style.css");
    stile.open(QFile::ReadOnly);
    a.setStyleSheet(stile.readAll());

    w.show();

    return a.exec();
}
