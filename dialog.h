#ifndef DIALOG_H
#define DIALOG_H
#include <QFile>
#include <QDialog>
#include <QLineEdit>
#include <QSettings>
#include <QUrl>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QString textInEdit;
public slots:
    void setText(QString text);
    void setPath();

signals:
    void closed();
};
#endif // DIALOG_H
