#ifndef BOOKINFOTABLE_H
#define BOOKINFOTABLE_H
#include "book.h"
#include <vector>
#include <QVector>

class BookInfoTable
{
public:
    BookInfoTable();

    bool ReadBookFromFile(const QString &aReadFileName);
    bool SaveBookToFile(const QString &aSaveFileName);

    void AddBook(Book & book);
    void RemoveBook(int index);
    void BorrowBook(Book & book);
    void ReturnBook(int index);

    Book & GetBook(int index);
    Book & GetBorrowBook(int index);

    int GetBookNum();
    int GetBorrowBookNum();

    int number=0;
    int borrownumber=0;

    QVector <Book> m_book;
    QVector <Book> m_borrowbook;
};

#endif // BOOKINFOTABLE_H
