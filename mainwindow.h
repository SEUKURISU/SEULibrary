#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "bookinfotable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ShowBookTable();
    void ShowBorrowBookTable();
    void ShowSearchTable(int i);
    void ShowSearchTable2(int i);
    void ShowSearchTable3();

protected:


private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionAdd_triggered();
    void on_actionDelete_triggered();
    void on_actionBorrow_triggered();
    void on_actionReturn_triggered();
    void on_actionIn_triggered();
    void on_actionOut_triggered();
    void on_actionSearch_triggered();
private:
    Ui::MainWindow *ui;
    QStandardItemModel * bookInforModel;
    BookInfoTable m_InfoTable;
};
#endif // MAINWINDOW_H

