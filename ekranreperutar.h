#ifndef EKRANREPERUTAR_H
#define EKRANREPERUTAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDate>
#include <QString>
#include <QScrollArea>
#include <QSignalMapper>
#include <seans.h>
#include "repertuar.h"
namespace Ui {
class EkranReperutar;
}

class EkranReperutar : public QWidget
{
    Q_OBJECT    

public:
    explicit EkranReperutar(QWidget *parent = nullptr);
    ~EkranReperutar();

    QSignalMapper * mapper;
    int liczbaPrzyciskow=0;
private:
    Ui::EkranReperutar *ui;
    QString tekst;
    QHBoxLayout* jedenSeans(Film* fil, Repertuar* rep);
    QVBoxLayout* listaSeansow( Repertuar* rep);
    QString data();
    void initMapper();

signals:
    void buttonClicked(QObject* a);
    void repertuarWrocClicked();

private slots:
    void on_pbRepertuarWroc_clicked();
};

#endif // EKRANREPERUTAR_H
