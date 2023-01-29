#include "bilet.h"
#include "konektorbazydanych.h"
int Bilet::getCena() const
{
    return cena;
}

void Bilet::setCena(int newCena)
{
    cena = newCena;
}

int Bilet::getId() const
{
    return id;
}

void Bilet::setId(int newId)
{
    id = newId;
}

void Bilet::zapiszBiletDoBazy(int IDPlatnosci,Seans* seans, int IDSeansuMiejsce)
{
    qDebug()<<"tutaj3";
    KonektorBazyDanych konektor1;
    QSqlQuery* wynik1 = konektor1.wykonajZapytanie("INSERT INTO bilet(IDBiletu,Cena,IDPlatnosci,IDSeansu,IDSeans_Miejsce) Values (:IDBiletu,:Cena,:IDPlatnosci,:IDSeansu,:IDSeans_Miejsce)");
    wynik1->bindValue(":IDBiletu",NULL);
    wynik1->bindValue(":Cena", cena );
    wynik1->bindValue(":IDPlatnosci",IDPlatnosci);
    wynik1->bindValue(":IDSeansu",seans->IdSeansu);
    wynik1->bindValue(":IDSeans_Miejsce",IDSeansuMiejsce);
    wynik1->exec();

}

Bilet::Bilet()
{

}
