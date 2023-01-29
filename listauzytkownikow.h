#ifndef LISTAUZYTKOWNIKOW_H
#define LISTAUZYTKOWNIKOW_H
#include "klient.h"
#include <list>

class ListaUzytkownikow
{
private:
    std::list<Klient> uzytkownicy;

public:
    ListaUzytkownikow();
    const std::list<Klient> &getUzytkownicy() const;
    void setUzytkownicy(const std::list<Klient> &newUzytkownicy);
};

#endif // LISTAUZYTKOWNIKOW_H
