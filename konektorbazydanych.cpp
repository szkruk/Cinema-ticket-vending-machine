#include "konektorbazydanych.h"

KonektorBazyDanych::KonektorBazyDanych()
{

}

QSqlQuery* KonektorBazyDanych::wykonajZapytanie(QString queryString)
{
    QSqlQuery* query= new QSqlQuery(QSqlDatabase::database("MyConnect"));
    query->prepare(queryString);
    query->exec();

    return query;
}

