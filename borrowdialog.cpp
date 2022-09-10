#include "borrowdialog.h"
#include "ui_borrowdialog.h"
#include <QDialog>

BorrowDialog::BorrowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowDialog)
{
    ui->setupUi(this);
}

BorrowDialog::~BorrowDialog()
{
    delete ui;
}

int BorrowDialog::Number()
{
    QString sNumber = ui->textEditNumber->toPlainText();
    int number = sNumber.toInt();
    return number;
}

QString BorrowDialog::ReaderName()
{
    return ui->textEditReaderName->toPlainText();
}

QString BorrowDialog::LoginNumber()
{
    return ui->textEditLoginNumber->toPlainText();
}

QString BorrowDialog::ReaderNumber()
{
    return ui->textEditReaderNumber->toPlainText();
}

QString BorrowDialog::Date()
{
    return ui->textEditDate->toPlainText();
}
