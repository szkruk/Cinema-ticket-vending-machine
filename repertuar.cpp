#include "repertuar.h"
#include "konektorbazydanych.h"
#include <qdatetime.h>
Repertuar::Repertuar(QObject *parent)
    : QObject{parent}
{
    this->dodajFilm();
    this->dodajSeans();
}

void Repertuar::dodajSeans()
{
    QList<Film*> tempFilm = pobierzFilmy();


    for(int i=0;i<tempFilm.length();i++)
    {
        KonektorBazyDanych konektor2;
        QSqlQuery* wynik2 = konektor2.wykonajZapytanie("SElECT Data,Godzina,CenaBazowa,IDSali,IDSeansu FROM Seans JOIN Film as f ON  Seans.IDFilmu =f.IDFilmu WHERE f.Tytul = '"+tempFilm[i]->getTytul()+"'");

        while(wynik2->next())
        {
            seanse.append(new Seans(QDate(2023,01,30),QTime::fromString(wynik2->value(1).toString(),"hh:mm:ss"),wynik2->value(2).toInt(),tempFilm[i],wynik2->value(3).toInt(),wynik2->value(4).toInt()));
        }
    }


}

QList<Seans*> Repertuar::pobierzSeanse()
{
    return seanse;
}

void Repertuar::dodajFilm()
{
    KonektorBazyDanych konektor1;
    QSqlQuery* wynik1 = konektor1.wykonajZapytanie("SELECT f.IDFilmu, f.Tytul, f.SciezkaZdjecia FROM film as f JOIN seans as s on f.IDFilmu = s.IDFilmu GROUP BY IDFilmu");
    wynik1->first();
    while(wynik1->next())
     {
        filmy.append(new Film(wynik1->value(1).toString(),wynik1->value(2).toString()));
     }

}

QList<Film*> Repertuar::pobierzFilmy()
{
    return filmy;
}
