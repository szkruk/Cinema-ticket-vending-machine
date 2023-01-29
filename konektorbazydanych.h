#ifndef KONEKTORBAZYDANYCH_H
#define KONEKTORBAZYDANYCH_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

class KonektorBazyDanych
{
public:
    KonektorBazyDanych();
    QSqlQuery* wykonajZapytanie(QString queryString);
private:

};

#endif // KONEKTORBAZYDANYCH_H
