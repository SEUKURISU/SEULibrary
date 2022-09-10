#include "adddialog.h"
#include "ui_adddialog.h"
#include <QDialog>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

QString AddDialog::Name()
{
    return ui->textEditName->toPlainText();
}

int AddDialog::Number()
{
    QString sNumber = ui->textEditNumber->toPlainText();
    int number = sNumber.toInt();
    return number;
}

QString AddDialog::Writername()
{
    return ui->textEditWritername->toPlainText();
}

QString AddDialog::Loginnumber()
{
    return ui->textEditLoginNumber->toPlainText();
}
