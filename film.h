#ifndef FILM_H
#define FILM_H

#include <QObject>

class Film : public QObject
{
    Q_OBJECT
public:
    explicit Film(QString t,QString s,QObject *parent = nullptr );

    QString getTytul();
    //void setTytul(const QString &newTytul);

    QString getSciezka();
    //void setSciezka(const QString &newSciezka);
private:
    QString tytul;
    QString sciezka;

signals:

};

#endif // FILM_H
