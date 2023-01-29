#include "platnosc.h"
#include <QDateTime>


int Platnosc::getId_platnosci() const
{
    return id_platnosci;
}

void Platnosc::setId_platnosci(int newId_platnosci)
{
    id_platnosci = newId_platnosci;
}

Platnosc::Platnosc(QList<Miejsce *> m, Seans *s)
    :miejsca{m},seans{s}
{
    wartosc = 0.00;
}

double Platnosc::getWartosc() const
{
    return wartosc;
}

void Platnosc::setWartosc(double newWartosc)
{
    wartosc = newWartosc;
}

double Platnosc::ustalWartosc(double cena_biletu, int ile)
{
    return cena_biletu * ile;
}

QList<Bilet*> Platnosc::getBilety()
{
    return bilety;
}

QList<Miejsce *> Platnosc::getMiejsca()
{
    return miejsca;
}

void Platnosc::generujBilety()
{
    Bilet* nowy = new Bilet();
    nowy->setCena(seans->getCena());
    bilety.append(nowy);

}

void Platnosc::zapiszPlatnoscDoBazy()
{
    KonektorBazyDanych konektor1;
    QSqlQuery* wynik1 = konektor1.wykonajZapytanie("INSERT INTO platnosc(IDPlatnosci,DataGodzina) Values (:IDPlatnosci,:DataGodzina)");
    wynik1->bindValue(":IDPlatnosci",NULL);
    wynik1->bindValue(":DataGodzina",QDateTime::currentDateTime());
    wynik1->exec();
    this->setId_platnosci(wynik1->lastInsertId().toInt());

}
