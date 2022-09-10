#include "bookinfotable.h"
#include <qfile.h>
#include <QTextStream>
#include <QTextCodec>
#include <QMessageBox>
#include <QErrorMessage>
#include <QObject>

BookInfoTable::BookInfoTable()
{

}

bool BookInfoTable::ReadBookFromFile(const QString &aReadFileName)
{
    QFile aFile(aReadFileName);
    if(!aFile.exists())
        return false;
    if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream aStream(&aFile);
    aStream.setCodec(QTextCodec::codecForName("system"));

    m_book.clear();

    aStream>>number;
    Book tempBook;
    if(number>0)
    {
        for(int i=0; i<number; i++)
        {
            tempBook.ReadBook(aStream);
            m_book.push_back(tempBook);
        }
    }
    borrownumber=m_borrowbook.size();
    aStream>>borrownumber;
    if(borrownumber>0)
    {
        for(int i=0; i<borrownumber; i++)
        {
            tempBook.ReadBook(aStream);
            m_borrowbook.push_back(tempBook);
        }
    }
    aFile.close();
    return true;
}

bool BookInfoTable::SaveBookToFile(const QString &aSaveFileName)
{
    QFile aFile(aSaveFileName);
    if(!aFile.open(QIODevice::WriteOnly| QIODevice::Text))
        return false;
    QTextStream aStream(&aFile);
    aStream.setCodec(QTextCodec::codecForName("system"));

    aStream<<number<<'\n';
    if(number>0)
    {
        for(int i=0; i<number; i++)
            m_book[i].SaveBook(aStream);
    }
    borrownumber=m_borrowbook.size();
    aStream<<borrownumber<<'\n';
    if(borrownumber>0)
    {
        for(int i=0; i<borrownumber; i++)
            m_borrowbook[i].SaveBook(aStream);
    }
    aFile.close();
    return true;
}

void BookInfoTable::AddBook(Book &book)
{
    book.m_innumber = 1;
    for(int i = 0;i<GetBookNum();i++)
    {
        if(book.m_number==m_book[i].m_number)
        {
            book.m_innumber++;
        }
    }
    for(int i = 0;i<GetBookNum();i++)
    {
        if(book.m_number==m_book[i].m_number)
        {
            m_book[i].m_innumber=book.m_innumber;
        }
    }
    for(int i = 0;i<GetBorrowBookNum();i++)
    {
        if(book.m_number==m_borrowbook[i].m_number)
        {
            m_borrowbook[i].m_innumber++;
        }
    }
    for(int i = 0;i<GetBorrowBookNum();i++)
    {
        if(book.m_number==m_borrowbook[i].m_number)
        {
            book.m_outnumber++;
        }
    }
    m_book.push_back(book);
    number++;
}

void BookInfoTable::RemoveBook(int index)
{
    for(int a=0;a<GetBorrowBookNum();a++)
    {
        if(m_borrowbook[a].m_number==m_book[index].m_number)
        {
            m_borrowbook[a].m_innumber--;
        }
    }
    for(int i=0;i<GetBookNum();i++)
    {
        if(m_book[i].m_number==m_book[index].m_number)
        {
            m_book[i].m_innumber--;
        }
    }
    if(number>0)
    {
        m_book.remove(index);
        number--;
    }
}

void BookInfoTable::BorrowBook(Book &book)
{
    int counter=0;
    for(int i = 0;i<GetBorrowBookNum();i++)
    {
        if(book.m_name==m_borrowbook[i].m_name)
        {
            counter++;
        }
    }
        for(int i = 0;i<GetBookNum();i++)
        {
          if(book.m_number==m_book[i].m_number)
           {
              m_book[i].m_outnumber++;
           }

        }
        for(int i = 0;i<GetBookNum();i++)
        {
            if(book.m_loginnumber==m_book[i].m_loginnumber)
            {
              m_book[i].m_readername=book.m_readername;
              m_book[i].m_readernumber=book.m_readernumber;
              m_book[i].m_date=book.m_date;
              book=m_book[i];
              book.m_innumber--;
              RemoveBook(i);
              m_borrowbook.push_back(book);
            }

        }
        for(int i=0;i<GetBorrowBookNum();i++)
        {
            if(book.m_number==m_borrowbook[i].m_number)
            {
                m_borrowbook[i].m_innumber=book.m_innumber;
                m_borrowbook[i].m_outnumber=book.m_outnumber;
            }
        }

}

void BookInfoTable::ReturnBook(int index)
{
    m_borrowbook[index].m_outnumber--;
    m_borrowbook[index].m_innumber++;
    m_borrowbook[index].m_readername="None";
    m_borrowbook[index].m_readernumber="None";
    m_borrowbook[index].m_date="None";
    for(int i=0;i<GetBookNum();i++)
    {
        if(m_book[i].m_number==m_borrowbook[index].m_number)
        {

            m_book[i].m_outnumber--;
            m_book[i].m_innumber++;
        }

    }
    if(number>=0)
    {
        m_book.push_back(m_borrowbook[index]);
        m_borrowbook.remove(index);
        borrownumber--;
    }
}

int BookInfoTable::GetBookNum()
{
    number = m_book.size();
    return number;
}

int BookInfoTable::GetBorrowBookNum()
{
    number = m_borrowbook.size();
    return number;
}

Book & BookInfoTable::GetBook(int index)
{
    return m_book[index];
}

Book & BookInfoTable::GetBorrowBook(int index)
{
    return m_borrowbook[index];
}


