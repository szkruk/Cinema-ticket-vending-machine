#ifndef MIEJSCE_H
#define MIEJSCE_H

#include <QObject>
class Seans;
class Miejsce : public QObject
{
    Q_OBJECT
public:
    explicit Miejsce(int r,int m,QString s,QObject *parent = nullptr);
    QString pobierzStatus();
    void zmienStatus(Seans* seans);
    QPair<int,int> pobierzSzczegoly();
    int IdMiejsceSeans;
    int IDMiejsca;
private:
    int rzad;
    int miejsce;
    QString status;
signals:

};

#endif // MIEJSCE_H
