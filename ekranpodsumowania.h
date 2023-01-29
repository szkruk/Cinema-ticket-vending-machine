#ifndef EKRANPODSUMOWANIA_H
#define EKRANPODSUMOWANIA_H

#include <QWidget>
#include <QDebug>
#include <QDate>
#include <string>
#include <iomanip>
#include "platnosc.h"
#include "miejsce.h"
#include "seans.h"

namespace Ui {
class EkranPodsumowania;
}

class EkranPodsumowania : public QWidget
{
    Q_OBJECT

public:
    explicit EkranPodsumowania(QWidget *parent = nullptr);
    ~EkranPodsumowania();
    void inicjujOkno(QList<Miejsce*> miejsca,Seans* seans);
    Platnosc* tmp_pl;

private:
    Ui::EkranPodsumowania *ui;

signals:
    void signalPlacKarta(Platnosc* tmp_pl);
    void signalPlacBlik();
    void signalPrzerwijWyborMiejsc();

private slots:

    void on_pbPodsuomowanieWroc_clicked();
    void on_pbPodsumowanieKarta_clicked();
};

#endif // EKRANPODSUMOWANIA_H
