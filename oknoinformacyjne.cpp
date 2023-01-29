#include "oknoinformacyjne.h"
#include "ui_oknoinformacyjne.h"

OknoInformacyjne::OknoInformacyjne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OknoInformacyjne)
{
    ui->setupUi(this);
}

OknoInformacyjne::~OknoInformacyjne()
{
    delete ui;
}

void OknoInformacyjne::inicjujOknoInformacyjnePlatnosc(Platnosc* platnosc)
{
    ui->pbInformacyjne->setVisible(true);
    ui->labInformacyjne->setText("Zbliż lub wsuń kartę.");
    QEventLoop loop;
    QTimer::singleShot(3000,&loop,SLOT(quit()));
    loop.exec();
    ui->labInformacyjne->setText("Autoryzacja transakcji...");
    ui->pbInformacyjne->setVisible(false);

    platnosc->zapiszPlatnoscDoBazy();
    platnosc->generujBilety();
    QList<Miejsce*> miejsca = platnosc->getMiejsca();
    QList<Bilet*> bilety = platnosc->getBilety();

    for(int i=0;i<miejsca.length();i++)
    {
        qDebug()<<"tutaj12";
        miejsca[i]->zmienStatus(platnosc->seans);
        qDebug()<<"tutaj1221";

        bilety[i]->zapiszBiletDoBazy(platnosc->getId_platnosci(),platnosc->seans,miejsca[i]->IdMiejsceSeans);
        qDebug()<<"tutaj4";
    }
    QTimer::singleShot(3500,&loop,SLOT(quit()));
    loop.exec();
    ui->labInformacyjne->setText("Transakcja zaakceptowana. Dziękujemy!");
    QTimer::singleShot(3000,&loop,SLOT(quit()));
    loop.exec();
    emit preniesEkranGlownyOknoInformacyjne();
}

void OknoInformacyjne::on_pbInformacyjne_clicked()
{
    emit anulujPlatnosc();
}
