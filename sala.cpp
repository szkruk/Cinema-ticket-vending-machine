#include "sala.h"
#include "konektorbazydanych.h"
#include "seans.h"
Sala::Sala(int Id,Seans* sean,QObject *parent)
    : QObject{parent},IdSali{Id},seans{sean}
{

}

QList<Miejsce*> Sala::pobierzMiejsca()
{
    return miejsca;
}


//Tworz miejsca - baza danych
void Sala::tworzMiejsca()
{
    KonektorBazyDanych konektor1;
    QSqlQuery* wynik1 = konektor1.wykonajZapytanie("SELECT * FROM sala Where IDSali ='"+QString::number(IdSali)+"'");
    wynik1->first();
    rzedy = wynik1->value(3).toInt();
    miejscaWRzedzie = wynik1->value(4).toInt();
    qDebug()<<"Siema";
    KonektorBazyDanych konektor2;
    QSqlQuery* wynik2 = konektor2.wykonajZapytanie("SElECT sm.IDSeans_Miejsce,m.Rzad,m.Numer,sm.CzyWolne, sm.IDSeansu From miejsce as m JOIN seans_miejsce as sm ON sm.IDMiejsca = m.IDMiejsca WHERE IDSeansu = '"+QString::number(seans->IdSeansu)+"' ORDER BY sm.IDSeans_Miejsce");

    while(wynik2->next())
     {
        miejsca.append(new Miejsce(wynik2->value(1).toInt(),wynik2->value(2).toInt(),wynik2->value(3).toString()));
    }
}

QPair<int, int> Sala::szczegoly()
{
    return qMakePair(rzedy,miejscaWRzedzie);
}
