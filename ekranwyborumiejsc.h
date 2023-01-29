#ifndef EKRANWYBORUMIEJSC_H
#define EKRANWYBORUMIEJSC_H
#include "seans.h"
#include <QWidget>
#include <QSignalMapper>

namespace Ui {
class EkranWyboruMiejsc;
}

class EkranWyboruMiejsc : public QWidget
{
    Q_OBJECT

public:
    QSignalMapper * mapper;
    explicit EkranWyboruMiejsc(QWidget *parent = nullptr);
    ~EkranWyboruMiejsc();
    void inicjujOkno(Seans* wybrany); // Tutaj inicjowanie okna
    void usunPrzyciskWyboruMiejsc(QLayout *lay); // czyszczenie layoutu z miejscami

private:
    Ui::EkranWyboruMiejsc *ui;
    Seans* seans;
    void initMapper();
    QList <Miejsce*> miejsca;


signals:
    void buttonClicked(QObject* a);
    void przejdzDoPlatnosci(QList<Miejsce*> miejscaa,Seans* seanss);
    void wroc();
private slots:
    void on_pbZatwierdz_clicked();
    void on_pbWroc_clicked();
};

#endif // EKRANWYBORUMIEJSC_H
