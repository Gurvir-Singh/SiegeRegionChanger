#ifndef DIALOG_H
#define DIALOG_H
#include <QFile>
#include <QDialog>
#include <QSettings>
#include <QUrl>
#include <QFileDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void openFileDialog();
private:
    Ui::Dialog *ui;
    QFileDialog fileDialog;

public slots:

signals:
    void closed();
};
#endif // DIALOG_H
