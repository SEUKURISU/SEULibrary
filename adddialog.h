#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    QString Name();
    int Number();
    QString Writername();
    QString Loginnumber();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H

