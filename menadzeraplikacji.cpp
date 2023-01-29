#include "menadzeraplikacji.h"

MenadzerAplikacji *App = nullptr;
MenadzerAplikacji::MenadzerAplikacji(int &argc, char **argv):
    QApplication(argc, argv)
{
    App = this;
    this->polaczZBazaDanych();
    menKin = new MenadzerKin();
    oknoGlowne = new MainWindow();
    listaUz = new ListaUzytkownikow();


}

void MenadzerAplikacji::inicjujEkran()
{
    this->oknoGlowne->show();
}


void MenadzerAplikacji::polaczZBazaDanych()
{
    mydb = QSqlDatabase::addDatabase("QMYSQL","MyConnect");
        mydb.setHostName("127.0.0.1");
        mydb.setPort(3306);
        mydb.setUserName("root");
        mydb.setPassword("G2ho86Mlz@1");
        mydb.setDatabaseName("mydb");
        if(!mydb.open())
              { qDebug()<<"Nie otwarto";
                qDebug()<<mydb.isValid();
               qDebug() << "Blad odczytu bazy danych" << mydb   ;}
        else
            qDebug()<<"Otwarto";
}
