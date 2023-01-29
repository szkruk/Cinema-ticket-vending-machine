#ifndef KLIENT_H
#define KLIENT_H

#include "platnosc.h"

class Klient
{    
private:
    //Platnosc konkr_platnosc;
public:
    Klient();

    const Platnosc &getKonkr_platnosc() const;
    void setKonkr_platnosc(const Platnosc &newKonkr_platnosc);
};

#endif // KLIENT_H
