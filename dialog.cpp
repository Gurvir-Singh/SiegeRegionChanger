#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    connect(ui->selectFileButton, &QPushButton::clicked, this, &Dialog::openFileDialog);
    connect(ui->okButton, &QPushButton::clicked, this, &Dialog::okButtonClicked);
    QSettings settings("Gurv", "SiegeRegionChanger");
    if (settings.value("firstTime") == true || settings.value("firstTime").isNull()){
        ui->okButton->hide();
    }
}

Dialog::~Dialog()
{
    emit closed();
    delete ui;
}

void Dialog::openFileDialog()
{
    QString pathEntered = QFileDialog::getOpenFileName(this, QString(), QString(), "INI files (*.ini)");
    if (!(QUrl::fromLocalFile(pathEntered).isLocalFile()) || !(pathEntered.contains("GameSettings.ini"))){
       ui->label->setText("Please select a valid file!");
    }
    else{
       qDebug() << pathEntered;
       QSettings settings("Gurv", "SiegeRegionChanger");
       settings.setValue("firstTime", "false");
       settings.setValue("pathToSettings", pathEntered);
       this->~Dialog();
    }
}

void Dialog::okButtonClicked()
{
    this->~Dialog();
}


