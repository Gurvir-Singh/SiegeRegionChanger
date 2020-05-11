#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, this, &Dialog::setText);
    connect(ui->pushButton, &QPushButton::clicked, this, &Dialog::setPath);

}

Dialog::~Dialog()
{
    emit closed();
    delete ui;
}

void Dialog::setText(QString text)
{
    this->textInEdit = text;
}

void Dialog::setPath()
{
    QString path = this->textInEdit;
    if (!QUrl::fromLocalFile(path).isLocalFile() || !path.contains("GameSettings.ini" , Qt::CaseInsensitive)){
        ui->label->setText("Please enter a\nvalid path");
    }
    else {
        QFile settingsFile(path);
        settingsFile.copy("GameSetings-backup.ini");
        QSettings settings("Gurv", "SiegeRegionChanger");
        settings.setValue("pathToSettings", path);
        settings.setValue("firstTime", false);
        this->~Dialog();

    }
}
