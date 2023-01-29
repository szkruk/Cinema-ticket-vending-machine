#include "seans.h"
#include "menadzeraplikacji.h"
Seans::Seans(QDate dat,QTime godz,int cena, Film* fil,int IdSal,int Sean,QObject *parent)
    : QObject{parent},data{dat},godzina{godz},cenaBazowa{cena},film{fil},IdSali{IdSal},IdSeansu{Sean}
{
    sala = NULL;

}

QList<Miejsce *> Seans::pobierzSale()
{


    MenadzerAplikacji * myApp = App;
    sala = myApp->menKin->getKino()->dodajSale(this);
    sala->tworzMiejsca();
    return this->sala->pobierzMiejsca();
}

Sala *Seans::getSala()
{
    return sala;

}

Film *Seans::getFilm()
{
    return film;

}

int Seans::getCena()
{
    return cenaBazowa;
}


