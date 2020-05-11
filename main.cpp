#include "mainwindow.h"
#include <QSettings>
#include <QApplication>
#include <QDebug>
#include <QUrl>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
