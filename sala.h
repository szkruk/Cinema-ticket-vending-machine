#ifndef SALA_H
#define SALA_H
#include <QObject>
#include "miejsce.h"

class Seans;

class Sala : public QObject
{
    Q_OBJECT
public:
    explicit Sala(int Id, Seans* sean,QObject *parent = nullptr);

    QList<Miejsce*> pobierzMiejsca();
    void tworzMiejsca();

    QPair<int,int> szczegoly();
    int IdSali;
private:
    Seans* seans;
    QList <Miejsce*> miejsca;
    int rzedy;
    int miejscaWRzedzie;
signals:

};

#endif // SALA_H
