#include "book.h"

Book::Book()
{

}

Book::~Book()
{

}

Book::Book(const Book & book)
{
    m_name = book.m_name;
    m_number = book.m_number;
    m_writername = book.m_writername;
    m_innumber = book.m_innumber;
    m_outnumber = book.m_outnumber;
    m_loginnumber = book.m_loginnumber;
    m_readername = book.m_readername;
    m_readernumber = book.m_readernumber;
    m_date = book.m_date;
}

Book& Book::operator= (const Book& book)
{
    m_name = book.m_name;
    m_number = book.m_number;
    m_writername = book.m_writername;
    m_innumber = book.m_innumber;
    m_outnumber = book.m_outnumber;
    m_loginnumber = book.m_loginnumber;
    m_readername = book.m_readername;
    m_readernumber = book.m_readernumber;
    m_date = book.m_date;
    return *this;
}

void Book::SaveBook(QTextStream &aStream)
{
    aStream << m_name<<'\n';
    aStream << m_number<<'\n';
    aStream << m_writername<<'\n';
    aStream << m_innumber<<'\n';
    aStream << m_outnumber<<'\n';
    aStream << m_loginnumber<<'\n';
    aStream << m_readername<<'\n';
    aStream << m_readernumber<<'\n';
    aStream << m_date<<'\n';

}

void Book::ReadBook(QTextStream &aStream)
{
    aStream >> m_name;
    aStream >> m_number;
    aStream >> m_writername;
    aStream >> m_innumber;
    aStream >> m_outnumber;
    aStream >> m_loginnumber;
    aStream >> m_readername;
    aStream >> m_readernumber;
    aStream >> m_date;

}
