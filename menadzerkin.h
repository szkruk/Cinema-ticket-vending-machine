#ifndef MENADZERKIN_H
#define MENADZERKIN_H
#include "kino.h"
#include <QObject>
#include "repertuar.h"
class MenadzerKin : public QObject
{
    Q_OBJECT
public:
    explicit MenadzerKin(QObject *parent = nullptr);
    Repertuar* pobierzRepertuar();
    Kino* getKino();
private:
    Kino* kino;
signals:

};

#endif // MENADZERKIN_H
