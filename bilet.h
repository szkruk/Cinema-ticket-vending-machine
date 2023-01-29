#ifndef BILET_H
#define BILET_H
#include "seans.h"

class Bilet
{
private:
    int cena;
    int id;

public:
    Bilet();
    int getCena() const;
    void setCena(int newCena);
    int getId() const;
    void setId(int newId);
    void zapiszBiletDoBazy(int IDPlatnosci,Seans* seans,int IDSeansuMiejsce);
};

#endif // BILET_H
