#ifndef BOOK_H
#define BOOK_H
#include <qdatetime.h>
#include <qstring.h>

#include <QTextStream>


class Book
{
public:
    Book();

    Book(const Book & book);
    Book& operator= (const Book& book);
    virtual ~Book();

    void SaveBook(QTextStream &aStream);
    void ReadBook(QTextStream &aStream);

    int			 m_number;
    QString		 m_name;
    QString      m_writername;
    int          m_innumber;
    int          m_outnumber;
    QString      m_loginnumber;

    QString      m_readername="None";
    QString      m_readernumber="None";
    QString      m_date="None";
};

#endif //BOOK_H
