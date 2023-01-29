#ifndef KINO_H
#define KINO_H

#include <QObject>
#include "sala.h"
#include "repertuar.h"
class Kino : public QObject
{
    Q_OBJECT
public:
    explicit Kino(QObject *parent = nullptr, QString adress="Piekna 3/4");

    QList<Sala*> pobierzSale();
    Sala* dodajSale(Seans* cos);
    Repertuar* pobierzRepertuar();
    QString pobierzAdres();
private:
    QList<Sala*> sale;
    QString adres;
    Repertuar* repertuar;

signals:

};

#endif // KINO_H
