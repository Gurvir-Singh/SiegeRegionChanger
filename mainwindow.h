#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSettings>
#include <QMainWindow>
#include <QRadioButton>
#include <QDebug>
#include <QUrl>
#include <QDialogButtonBox>
#include <dialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPathToFile();

private:
    Ui::MainWindow *ui;
    QRadioButton* setInitialSetting();
    bool checkForFirstTime();
    void firstTimeSetup();
    QString pathToFile;
    Dialog *popUp;


public slots:
    void regionChangeButtonPressed();

};
#endif // MAINWINDOW_H
