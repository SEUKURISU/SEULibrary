#ifndef BORROWDIALOG_H
#define BORROWDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class BorrowDialog;
}

class BorrowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowDialog(QWidget *parent = nullptr);
    ~BorrowDialog();

    QString ReaderNumber();
    int Number();
    QString ReaderName();
    QString LoginNumber();
    QString Date();

private:
    Ui::BorrowDialog *ui;
};

#endif // BORROWDIALOG_H
