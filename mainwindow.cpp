#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    if (checkForFirstTime()){
        setPathToFile();
    }
    else{
        this->show();
    }

    QSettings settings("Gurv", "SiegeRegionChanger");
    this->pathToFile = settings.value("pathToSettings").toString();
    ui->pathLabel->setText("Settings Path:\n" + settings.value("pathToSettings").toString());
    setInitialSetting()->setChecked(true);
    connect(ui->changeRegionButton, &QPushButton::clicked, this, &MainWindow::regionChangeButtonPressed);
    connect(ui->changePathButton, &QPushButton::clicked, this, &MainWindow::setPathToFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPathToFile()
{
    this->setVisible(false);
    popUp = new Dialog;
    popUp->show();
    connect(popUp, &Dialog::closed, this, &MainWindow::show);

}

QRadioButton *MainWindow::setInitialSetting()
{
    QSettings settings(this->pathToFile, QSettings::IniFormat);
    settings.beginGroup("ONLINE");
    QString startingSetting = settings.value("DataCenterHint").toString();
    settings.endGroup();
    if (startingSetting == "default"){
        return(this->ui->defaultButton);
    }
    else if (startingSetting == "eastus"){
        return(this->ui->eastusButton);
    }
    else if (startingSetting == "centralus"){
        return(this->ui->centralusButton);
    }
    else if (startingSetting == "southcentralus"){
        return(this->ui->southcentralusButton);
    }
    else if (startingSetting == "westus"){
        return(this->ui->westusButton);
    }
    else if (startingSetting == "brazilsouth"){
        return(this->ui->brazilsouthButton);
    }
    else if (startingSetting == "northeurope"){
        return(this->ui->northeuropeButton);
    }
    else if (startingSetting == "westeurope"){
        return(this->ui->westeuropeButton);
    }
    else if (startingSetting == "southafricanorth"){
        return(this->ui->southafricanorthButton);
    }
    else if (startingSetting == "eastasia"){
        return(this->ui->eastasiaButton);
    }
    else if (startingSetting == "southeastasia"){
        return(this->ui->southeastasiaButton);
    }
    else if (startingSetting == "australiaeast"){
        return(this->ui->australiaeastButton);
    }
    else if (startingSetting == "australiasoutheast"){
        return(this->ui->australiasoutheastButton);
    }
    else if (startingSetting == "japanwest"){
        return(this->ui->japanwestButton);
    }
    else {

    }
    return(this->ui->defaultButton);
}

bool MainWindow::checkForFirstTime()
{
    QSettings settings("Gurv", "SiegeRegionChanger");
    if (settings.value("firstTime").isNull() || settings.value("firstTime") == true){
        return true;
    }
    else {
        return false;
    }

}


void MainWindow::regionChangeButtonPressed()
{
    QString currentButton;
    if (ui->defaultButton->isChecked()){
        currentButton = "default";
    }
    else if (ui->eastusButton->isChecked()){
        currentButton = "eastus";
    }
    else if (ui->centralusButton->isChecked()){
        currentButton = "centralus";
    }
    else if (ui->southcentralusButton->isChecked()){
        currentButton = "southcentralus";
    }
    else if (ui->westusButton->isChecked()){
        currentButton = "westus";
    }
    else if (ui->brazilsouthButton->isChecked()){
        currentButton = "brazilsouth";
    }
    else if (ui->northeuropeButton->isChecked()){
        currentButton = "northeurope";
    }
    else if (ui->westeuropeButton->isChecked()){
        currentButton = "westeurope";
    }
    else if (ui->southafricanorthButton->isChecked()){
        currentButton = "southafricanorth";
    }
    else if (ui->eastasiaButton->isChecked()){
        currentButton = "eastasia";
    }
    else if (ui->southeastasiaButton->isChecked()){
        currentButton = "southeastasia";
    }
    else if (ui->australiaeastButton->isChecked()){
        currentButton = "australiaeast";
    }
    else if (ui->australiasoutheastButton->isChecked()){
        currentButton = "australiasoutheast";
    }
    else if (ui->japanwestButton->isChecked()){
        currentButton = "japanwest";
    }
    else {
        currentButton = "default";
    }
    QSettings settings(this->pathToFile, QSettings::IniFormat);
    settings.beginGroup("ONLINE");
    settings.setValue("DataCenterHint", currentButton);
    settings.endGroup();
}

