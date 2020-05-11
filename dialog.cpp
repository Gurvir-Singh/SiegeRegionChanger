#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->selectFileButton, &QPushButton::clicked, this, &Dialog::openFileDialog);
}

Dialog::~Dialog()
{
    emit closed();
    delete ui;
}

void Dialog::openFileDialog()
{
    QFileDialog fileDialog;
    fileDialog.show();


}


void Dialog::setPath(QString pathSelected)
{
    if (!(QUrl::fromLocalFile(pathSelected).isLocalFile()) || !(pathSelected.contains("GameSettings.ini"))){
       ui->label->setText("Please select a valid file!");
    }
    else{
       QSettings settings("Gurv", "SiegeRegionChanger");
       settings.setValue("firstTime", "false");
       settings.setValue("pathToSettings", pathSelected);
       this->~Dialog();
    }


}
