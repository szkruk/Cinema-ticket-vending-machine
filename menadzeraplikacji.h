#ifndef MENADZERAPLIKACJI_H
#define MENADZERAPLIKACJI_H
#include <QApplication>
#include "mainwindow.h"
#include "listauzytkownikow.h"
#include "menadzerkin.h"
#include "konektorbazydanych.h"

class MenadzerAplikacji;
extern MenadzerAplikacji *App;

class MenadzerAplikacji: public QApplication
{
public:
    MenadzerAplikacji(int &argc, char **argv);
    void inicjujEkran();
    void polaczZBazaDanych();
    MainWindow* oknoGlowne;
    ListaUzytkownikow* listaUz;
    MenadzerKin* menKin;

private:
    QSqlDatabase mydb;


};

#endif // MENADZERAPLIKACJI_H
