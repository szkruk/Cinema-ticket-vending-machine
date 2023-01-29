#include "menadzerkin.h"

MenadzerKin::MenadzerKin(QObject *parent)
    : QObject{parent}
{
    kino = new Kino();
}

Repertuar* MenadzerKin::pobierzRepertuar()
{
    return kino->pobierzRepertuar();

}

Kino *MenadzerKin::getKino()
{
    return kino;
}
