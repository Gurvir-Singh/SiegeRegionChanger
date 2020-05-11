#include "mainwindow.h"
#include <QSettings>
#include <QApplication>
#include <QDebug>
#include <QUrl>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("Gurv", "SiegeRegionChanger");
    settings.setValue("firstTime", true);
    //MainWindow w;
    return a.exec();
}
