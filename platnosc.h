#ifndef PLATNOSC_H
#define PLATNOSC_H

#include "bilet.h"
#include "miejsce.h"
#include "seans.h"
#include "konektorbazydanych.h"

class Platnosc
{
private:
    double wartosc;
    int id_platnosci;
    QList<Miejsce*> miejsca;
    QList<Bilet*> bilety;

public:
    Seans* seans;
    Platnosc(QList<Miejsce*> m,Seans* s );
    double getWartosc() const;
    void setWartosc(double newWartosc);
    double ustalWartosc(double cena_biletu, int ile);
    int getId_platnosci() const;
    void setId_platnosci(int newId_platnosci);
    QList<Bilet*> getBilety();
    QList<Miejsce*> getMiejsca();
    void generujBilety();
    void zapiszPlatnoscDoBazy();
};

#endif // PLATNOSC_H
