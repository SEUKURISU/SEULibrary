#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdir.h"
#include "qfiledialog.h"
#include "book.h"
#include "adddialog.h"
#include "borrowdialog.h"
#include "searchdialog.h"
#include "bookinfotable.h"
#include <QStandardItem>
#include <qvariant.h>
#include <QMessageBox>
#include <QAbstractItemDelegate>
#include <QModelIndex>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bookInforModel = new QStandardItemModel();
    ui->ShowInfotableView->setSelectionMode(QAbstractItemView::SingleSelection); //单次选择
    ui->ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectItems); //选中一个item
    ui->ShowInfotableView->setModel(bookInforModel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bookInforModel;
}

void MainWindow::ShowSearchTable(int i)
{
    bookInforModel->clear();
    bookInforModel->setColumnCount(6);
    QStringList templist;
    templist.append("书目编号");
    templist.append("书名");
    templist.append("登录号");
    templist.append("借书证号");
    templist.append("读者姓名");
    templist.append("借书日期");
    bookInforModel->setHorizontalHeaderLabels(templist);
    QStandardItem *aTempItem;
    QString tempStr;
    Book tempbook=m_InfoTable.GetBorrowBook(i);
    tempStr = QString::number(tempbook.m_number);
    aTempItem = new QStandardItem(tempStr);
    bookInforModel->setItem(0, 0, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_name);
    bookInforModel->setItem(0, 1, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_loginnumber);
    bookInforModel->setItem(0, 2, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_readernumber);
    bookInforModel->setItem(0, 3, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_readername);
    bookInforModel->setItem(0, 4, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_date);
    bookInforModel->setItem(0, 5, aTempItem);
}

void MainWindow::ShowSearchTable2(int i)
{
    bookInforModel->clear();
    bookInforModel->setColumnCount(6);
    QStringList templist;
    templist.append("书目编号");
    templist.append("书名");
    templist.append("登录号");
    templist.append("借书证号");
    templist.append("读者姓名");
    templist.append("借书日期");
    bookInforModel->setHorizontalHeaderLabels(templist);
    QStandardItem *aTempItem;
    QString tempStr;
    Book tempbook=m_InfoTable.GetBook(i);
    tempStr = QString::number(tempbook.m_number);
    aTempItem = new QStandardItem(tempStr);
    bookInforModel->setItem(0, 0, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_name);
    bookInforModel->setItem(0, 1, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_loginnumber);
    bookInforModel->setItem(0, 2, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_readernumber);
    bookInforModel->setItem(0, 3, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_readername);
    bookInforModel->setItem(0, 4, aTempItem);
    aTempItem = new QStandardItem(tempbook.m_date);
    bookInforModel->setItem(0, 5, aTempItem);
}

void MainWindow::ShowSearchTable3()
{
    bookInforModel->clear();
    bookInforModel->setColumnCount(6);
    QStringList templist;
    templist.append("书目编号");
    templist.append("书名");
    templist.append("登录号");
    templist.append("借书证号");
    templist.append("读者姓名");
    templist.append("借书日期");
    bookInforModel->setHorizontalHeaderLabels(templist);
}

void MainWindow::ShowBookTable()
{
    bookInforModel->clear();
    bookInforModel->setColumnCount(6); //6列

    //表头
    QStringList templist;
    templist.append("书目编号");
    templist.append("书名");
    templist.append("作者名");
    templist.append("登录号");
    templist.append("同书目在馆册数");
    templist.append("同书目借出册数");
    bookInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.GetBookNum(); //行数（不含标题）
    bookInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    for(int i=0; i<RowCnt; ++i)
    {
       Book tempbook=m_InfoTable.GetBook(i);
       tempStr = QString::number(tempbook.m_number);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 0, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_name);
       bookInforModel->setItem(i, 1, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_writername);
       bookInforModel->setItem(i, 2, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_loginnumber);
       bookInforModel->setItem(i, 3, aTempItem);
       tempStr = QString::number(tempbook.m_innumber);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 4, aTempItem);
       tempStr = QString::number(tempbook.m_outnumber);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 5, aTempItem);
    }

}

void MainWindow::ShowBorrowBookTable()
{
    bookInforModel->clear();
    bookInforModel->setColumnCount(6); //6列

    //表头
    QStringList templist;
    templist.append("书目编号");
    templist.append("书名");
    templist.append("作者名");
    templist.append("登录号");
    templist.append("同书目在馆册数");
    templist.append("同书目借出册数");
    bookInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.GetBorrowBookNum(); //行数（不含标题）
    bookInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    for(int i=0; i<RowCnt; ++i)
    {
       Book tempbook=m_InfoTable.GetBorrowBook(i);
       tempStr = QString::number(tempbook.m_number);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 0, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_name);
       bookInforModel->setItem(i, 1, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_writername);
       bookInforModel->setItem(i, 2, aTempItem);
       aTempItem = new QStandardItem(tempbook.m_loginnumber);
       bookInforModel->setItem(i, 3, aTempItem);
       tempStr = QString::number(tempbook.m_innumber);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 4, aTempItem);
       tempStr = QString::number(tempbook.m_outnumber);
       aTempItem = new QStandardItem(tempStr);
       bookInforModel->setItem(i, 5, aTempItem);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    if(aFileName.isEmpty())
        return;

    //创建成功，打开文件
    m_InfoTable.ReadBookFromFile(aFileName);
    ShowBookTable();
}

void MainWindow::on_actionSave_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "另存为一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if(aFileName.isEmpty())
        return;

    m_InfoTable.SaveBookToFile(aFileName);

}

void MainWindow::on_actionAdd_triggered()
{
    AddDialog dlgSignup(this);
    int ret = dlgSignup.exec();
    if(ret==QDialog::Accepted)
    {
        Book tempbook;
        tempbook.m_name = dlgSignup.Name();
        tempbook.m_number = dlgSignup.Number();
        tempbook.m_writername = dlgSignup.Writername();
        tempbook.m_loginnumber = dlgSignup.Loginnumber();
        m_InfoTable.AddBook(tempbook);
        ShowBookTable();
    }

}

void MainWindow::on_actionDelete_triggered()
{
        QModelIndex index = ui->ShowInfotableView->currentIndex();
        int ibook = index.row();
        m_InfoTable.RemoveBook(ibook);
        ShowBookTable();
}

void MainWindow::on_actionBorrow_triggered()
{
    int counter = 0;
    BorrowDialog dlgBorrow(this);
    int mark = dlgBorrow.exec();
    for(int i = 0;i<m_InfoTable.GetBorrowBookNum();i++)
    {
        if(dlgBorrow.ReaderName()==m_InfoTable.m_borrowbook[i].m_readername)
            counter++;
    }
    switch(counter<2)
    {
    case 1:
        if(mark == QDialog::Accepted)
        {
            Book tempbook;
            tempbook.m_date = dlgBorrow.Date();
            tempbook.m_number = dlgBorrow.Number();
            tempbook.m_readername = dlgBorrow.ReaderName();
            tempbook.m_readernumber = dlgBorrow.ReaderNumber();
            tempbook.m_loginnumber = dlgBorrow.LoginNumber();
            m_InfoTable.BorrowBook(tempbook);
            ShowBookTable();
        }
        break;
    case 0:
        counter=0;
        QMessageBox::critical(this,"错误","最多只能借两本书");
        break;

    }
}

void MainWindow::on_actionReturn_triggered()
{
        QModelIndex index = ui->ShowInfotableView->currentIndex();
        int ibook = index.row();
        m_InfoTable.ReturnBook(ibook);
        ShowBookTable();
}

void MainWindow::on_actionIn_triggered()
{
    ShowBookTable();
}

void MainWindow::on_actionOut_triggered()
{
    ShowBorrowBookTable();
}

void MainWindow::on_actionSearch_triggered()
{
    SearchDialog dlgSearch(this);
    int ret = dlgSearch.exec();
    int mark;
    int counter = 0;
    for(int i=0;i<m_InfoTable.GetBorrowBookNum();i++)
    {
        if(m_InfoTable.m_borrowbook[i].m_loginnumber==dlgSearch.LoginNumber())
        {
            counter++;
        }
    }
    switch(counter==0)
    {
    case 0:
        if(ret==QDialog::Accepted)
        {
            for(int i=0;i<m_InfoTable.GetBorrowBookNum();i++)
            {
                if(m_InfoTable.m_borrowbook[i].m_loginnumber==dlgSearch.LoginNumber())
                {
                    mark=i;
                }
            }
            ShowSearchTable(mark);
        }
        counter = 0;
        break;
    case 1:
            int counter2=0;
            for(int i=0;i<m_InfoTable.GetBookNum();i++)
            {
                if(m_InfoTable.m_book[i].m_loginnumber==dlgSearch.LoginNumber())
                {
                    mark=i;
                    counter2++;
                }
            }
            switch(counter2==0)
            {
            case 0:
            ShowSearchTable2(mark);
            break;
            case 1:
                ShowSearchTable3();
                break;
            }

    }
}


