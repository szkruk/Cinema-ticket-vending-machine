#include "ekranpodsumowania.h"
#include "ui_ekranpodsumowania.h"

EkranPodsumowania::EkranPodsumowania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EkranPodsumowania)
{
    ui->setupUi(this);
}

EkranPodsumowania::~EkranPodsumowania()
{
    delete ui;
}

void EkranPodsumowania::on_pbPodsuomowanieWroc_clicked()
{
    emit signalPrzerwijWyborMiejsc();
}


void EkranPodsumowania::on_pbPodsumowanieKarta_clicked()
{
    emit signalPlacKarta(tmp_pl);
}

void EkranPodsumowania::inicjujOkno(QList<Miejsce*> miejsca,Seans* seans)
{
    tmp_pl = NULL;
    // czyszczenie tabelki
    ui->twPodsumowanieKupno->clear();

    // JAK BĘDZIESZ WYPEŁNIAŁ TO USTAW TU KONKRETNYCH WARTOŚCI, NA RAZIE DAŁEM JAKIEŚ LOSOWE
    int row_count = 1, cols_count = 6;

    QStringList naglowki_tabeli = {"Seans", "Data", "Godzina", "Ilość", "Cena jednostkowa", "Miejsca"};
    ui->twPodsumowanieKupno->setRowCount(row_count);
    ui->twPodsumowanieKupno->setColumnCount(cols_count);
    ui->twPodsumowanieKupno->setHorizontalHeaderLabels(naglowki_tabeli);
    // ustalenie ceny łącznej - zmien wartosci int i double na cos konkretnego

    tmp_pl = new Platnosc(miejsca,seans);
    tmp_pl->ustalWartosc(seans->getCena(), miejsca.length());
    tmp_pl->setWartosc(tmp_pl->ustalWartosc(seans->getCena(), miejsca.length()));
    std::stringstream tmp;
    tmp << std::fixed << std::setprecision(2) << tmp_pl->getWartosc();
    // ustawienie wartosci łącznej do zapłaty
    ui->labPodsumowanieWartosc->setText(tmp.str().c_str());
    // dodawanie Item-ów do tabeli - na razie w if-ach są jakieś losowe wartości
    QTableWidgetItem *item = NULL;
    QString zawartosc_komorki;
    for(int i=0; i<row_count; i++){
        for(int j=0; j<cols_count; j++){
            item = new QTableWidgetItem;
            // ustawianie tekstu
            if(j==0){ // seans
                zawartosc_komorki = seans->getFilm()->getTytul();
            }else if(j==1){ // data - tego nie zmieniaj, zawsze pójdzie aktualna
                zawartosc_komorki = seans->data.toString();
            }else if(j==2){ // godzina
                zawartosc_komorki = seans->godzina.toString();
            }else if(j==3){ // ilość
                QString zmienna = QString::number(miejsca.length());
                zawartosc_komorki = zmienna;
            }else if(j==4){ // cena jednostkowa
                zawartosc_komorki =  QString::number(seans->getCena());
            }else if(j==5)
            {
                zawartosc_komorki ="";
                for(int x=0;x<miejsca.length();x++)
                {
                    QString rzad = QString::number(miejsca[x]->pobierzSzczegoly().first);
                    QString miejsce =  QString::number(miejsca[x]->pobierzSzczegoly().second);
                    zawartosc_komorki = zawartosc_komorki+"Rzad: "+ rzad +" Miejsce: "+miejsce+"\n ";
                }

            }
            item->setText(zawartosc_komorki);
            item->setFlags(Qt::ItemIsEnabled);
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            ui->twPodsumowanieKupno->setItem(i, j, item);
        }
    }
    ui->twPodsumowanieKupno->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);

    // dodatkowe ustawienia tabeli
    ui->twPodsumowanieKupno->setAlternatingRowColors(true);
    ui->twPodsumowanieKupno->resizeColumnsToContents();
}

