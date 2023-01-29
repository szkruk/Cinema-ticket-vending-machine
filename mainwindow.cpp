#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Widoki
    ui->kontroler->addWidget(&ekranAktywacji);
    ui->kontroler->addWidget(&ekranGlowny);
    ui->kontroler->addWidget(&ekranPodsumowania);
    ui->kontroler->addWidget(&ekranRepertuar);
    ui->kontroler->addWidget(&ekranWyboruMiejsc);
    ui->kontroler->addWidget(&oknoInformacyjne);

    //Konektory
    connect(&ekranAktywacji, SIGNAL(przejdz()),this,SLOT(przeniesDoEkranuGlownego()));
    connect(&ekranGlowny, SIGNAL(zakup()),this,SLOT(przeniesDoRepertuaru()));
    connect(&ekranRepertuar,SIGNAL(buttonClicked(QObject*)),this,SLOT(przeniesDoMiejsc(QObject*)));
    connect(&ekranRepertuar, SIGNAL(repertuarWrocClicked()),this,SLOT(przeniesDoEkranuGlownego()));
    connect(&ekranWyboruMiejsc,SIGNAL(przejdzDoPlatnosci(QList<Miejsce*>,Seans*)),this,SLOT(przeniesDoPodsumowania(QList<Miejsce*>,Seans*)));
    connect(&ekranWyboruMiejsc, SIGNAL(wroc()),this,SLOT(przeniesDoRepertuaru()));
    connect(&ekranPodsumowania,SIGNAL(signalPrzerwijWyborMiejsc()),this,SLOT(przeniesDoEkranuGlownego()));
    connect(&ekranPodsumowania,SIGNAL(signalPlacKarta(Platnosc*)),this,SLOT(przeniesDoOknaInformacyjnego(Platnosc*)));
    connect(&oknoInformacyjne,SIGNAL(anulujPlatnosc()),this,SLOT(przeniesDoEkranuGlownego()));
    connect(&oknoInformacyjne,SIGNAL(preniesEkranGlownyOknoInformacyjne()),this,SLOT(przeniesDoEkranuGlownego()));
    ui->kontroler->setCurrentWidget(&ekranAktywacji);

    // ustawienie tytułu okna
    setWindowTitle("Aplikacja biletomatu sieci kin");
}

void MainWindow::przeniesDoEkranuGlownego(){

    ui->kontroler->setCurrentWidget(&ekranGlowny);
}

void MainWindow::przeniesDoRepertuaru(){
    ui->kontroler->setCurrentWidget(&ekranRepertuar);
}

void MainWindow::przeniesDoMiejsc(QObject* obiekt)
{
    Seans* seans = qobject_cast<Seans*>(obiekt);
    ui->kontroler->setCurrentWidget(&ekranWyboruMiejsc);
    ekranWyboruMiejsc.inicjujOkno(seans);
}

void MainWindow::przeniesDoPodsumowania(QList<Miejsce*> miejsca,Seans* seans)
{
    ui->kontroler->setCurrentWidget(&ekranPodsumowania);
    ekranPodsumowania.inicjujOkno(miejsca,seans);
}

void MainWindow::przeniesDoOknaInformacyjnego(Platnosc* platnosc)
{
    ui->kontroler->setCurrentWidget(&oknoInformacyjne);
    oknoInformacyjne.inicjujOknoInformacyjnePlatnosc(platnosc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

