#include "miejsce.h"
#include "konektorbazydanych.h"
#include "seans.h"
Miejsce::Miejsce(int r,int m,QString s,QObject *parent)
    : QObject{parent},rzad{r},miejsce{m},status{s}
{
    IdMiejsceSeans = 0;
    IDMiejsca = 0;
}

QString Miejsce::pobierzStatus()
{
    return status;
}

//Zmiana statusu do bazy danych
void Miejsce::zmienStatus(Seans* seans)
{
    KonektorBazyDanych konektor2;

    QSqlQuery* wynik2 = konektor2.wykonajZapytanie("SELECT IDMiejsca FROM miejsce WHERE Rzad ='"+QString::number(pobierzSzczegoly().first)+"' AND Numer = '"+QString::number(pobierzSzczegoly().second)+"' AND IDSali = '"+QString::number(seans->IdSali)+"' ");
    wynik2->first();
    IDMiejsca= wynik2->value(0).toInt();
    KonektorBazyDanych konektor3;
    QSqlQuery* wynik3 = konektor3.wykonajZapytanie("SELECT IDSeans_Miejsce FROM seans_miejsce WHERE IDSeansu='"+QString::number(seans->IdSeansu)+"' AND IDMiejsca = '"+QString::number(IDMiejsca)+"'  ");
    wynik3->first();
    IdMiejsceSeans =wynik3->value(0).toInt();

    KonektorBazyDanych konektor1;
    QSqlQuery* wynik1 = konektor1.wykonajZapytanie("UPDATE seans_miejsce SET CzyWolne= :czywolne WHERE IDSeans_Miejsce= :IdSeansMiejsce");
    wynik1->bindValue(":czywolne", "NIE");
    wynik1->bindValue(":IdSeansMiejsce", wynik3->value(0).toString());
    wynik1->exec();
}

QPair<int, int> Miejsce::pobierzSzczegoly()
{
    return qMakePair(rzad, miejsce);
}
