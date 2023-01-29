#include "kino.h"
#include "seans.h"
#include "konektorbazydanych.h"
Kino::Kino(QObject *parent,QString adress )
    : QObject{parent},adres{adress}
{

    repertuar = new Repertuar();
}

QList<Sala *> Kino::pobierzSale()
{
    return sale;
}

//do bazy danych
Sala* Kino::dodajSale(Seans* cos)
{
    Sala* nowa = new Sala(cos->IdSali,cos);
    sale.append(nowa);
    return nowa;
}
// film WHERE IDFilmu = '"+filmID+"'
Repertuar* Kino::pobierzRepertuar()
{
    return repertuar;
}

QString Kino::pobierzAdres()
{
    return adres;
}
