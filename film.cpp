#include "film.h"

Film::Film(QString t,QString s,QObject *parent)
    : QObject{parent},tytul{t},sciezka{s}
{

}

QString Film::getSciezka()
{
    return sciezka;
}

//void Film::setSciezka(const QString &newSciezka)
//{
//    sciezka = newSciezka;
//}

QString Film::getTytul()
{
    return tytul;
}

//void Film::setTytul(const QString &newTytul)
//{
//    tytul = newTytul;
//}
