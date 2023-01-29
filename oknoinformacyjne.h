#ifndef OKNOINFORMACYJNE_H
#define OKNOINFORMACYJNE_H

#include <QWidget>
#include <windows.h>
#include <QTimer>
#include "platnosc.h"

namespace Ui {
class OknoInformacyjne;
}

class OknoInformacyjne : public QWidget
{
    Q_OBJECT

public:
    explicit OknoInformacyjne(QWidget *parent = nullptr);
    ~OknoInformacyjne();
    void inicjujOknoInformacyjnePlatnosc(Platnosc* platnosc);
private:
    Ui::OknoInformacyjne *ui;

signals:
    void anulujPlatnosc();
    void preniesEkranGlownyOknoInformacyjne();

private slots:
    void on_pbInformacyjne_clicked();

};

#endif // OKNOINFORMACYJNE_H
