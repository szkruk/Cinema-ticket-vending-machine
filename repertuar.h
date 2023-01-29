#ifndef REPERTUAR_H
#define REPERTUAR_H

#include <QObject>
#include "seans.h"
#include "film.h"
class Repertuar : public QObject
{
    Q_OBJECT
public:
    explicit Repertuar(QObject *parent = nullptr);

    void dodajSeans();
    QList<Seans*> pobierzSeanse();
    void dodajFilm();
    QList<Film*> pobierzFilmy();
private:
    QList<Seans*> seanse;
    QList<Film*> filmy;
signals:

};

#endif // REPERTUAR_H
