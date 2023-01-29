#ifndef SEANS_H
#define SEANS_H
#include <QObject>
#include <QDateTime>
#include "film.h"
#include "sala.h"

class Seans : public QObject
{
    Q_OBJECT
public:
    explicit Seans(QDate dat,QTime godz,int cena, Film* fil,int IdSal,int Sean,QObject *parent = nullptr);

    int IdSali;
    int IdSeansu;
    QList<Miejsce*> pobierzSale( );
    Sala *getSala();
    Film* getFilm();
    QDate data;
    QTime godzina;
    int getCena();

private:

    int cenaBazowa;
    Film* film;
    Sala* sala;
signals:

};

#endif // SEANS_H
