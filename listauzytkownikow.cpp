#include "listauzytkownikow.h"



ListaUzytkownikow::ListaUzytkownikow()
{

}

const std::list<Klient> &ListaUzytkownikow::getUzytkownicy() const
{
    return uzytkownicy;
}

void ListaUzytkownikow::setUzytkownicy(const std::list<Klient> &newUzytkownicy)
{
    uzytkownicy = newUzytkownicy;
}
