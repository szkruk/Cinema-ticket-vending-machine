#include "ekranwyborumiejsc.h"
#include "ui_ekranwyborumiejsc.h"
#include <QDebug>
EkranWyboruMiejsc::EkranWyboruMiejsc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EkranWyboruMiejsc)
{
    ui->setupUi(this);
    this->initMapper();
    connect(mapper, QOverload<QObject *>::of(&QSignalMapper::mapped),
            [=](QObject *object){
        Miejsce* miejsce = qobject_cast<Miejsce*>(object);

        if(QPushButton* senderButton = qobject_cast<QPushButton*>(mapper->mapping(object)))
             {
            if(senderButton->styleSheet()=="background-color: green;"){
                 senderButton->setStyleSheet("background-color: yellow;");
                miejsca.append(miejsce);
            }
            else{
                senderButton->setStyleSheet("background-color: green;");
                miejsca.removeOne(miejsce);
            }
        }
        qDebug()<<miejsca.length();
    });
}

EkranWyboruMiejsc::~EkranWyboruMiejsc()
{
    delete ui;
}


//To bedzie aktualizowalo okno po wybraniu seansu
// Tu mozesz robic grafike itd. bo ta funkcja automatycznie wywola
// sie po wcisneciu przycisku
void EkranWyboruMiejsc::inicjujOkno(Seans* wybrany)
{
    miejsca.clear();
    seans = wybrany;
    QList<Miejsce*> miejsca = seans->pobierzSale();
    QFont font("Arial",18);

    QPair<int,int> szczegoly(seans->getSala()->szczegoly().first,seans->getSala()->szczegoly().second);

    QVBoxLayout* area = new QVBoxLayout ;
    for(int i=0;i<seans->getSala()->szczegoly().first;i++)
    {

        area->setAlignment(Qt::AlignCenter);
        QHBoxLayout* buttons = new QHBoxLayout;
        buttons->setAlignment(Qt::AlignLeft);

        for(int j=0;j<seans->getSala()->szczegoly().second;j++)
        {

            QPushButton* button = new QPushButton ;
            button->setFont(font);
            button->setMaximumSize(50,50);
            button->setText(QString::number(miejsca[szczegoly.second*(i)+(j)]->pobierzSzczegoly().second ));
            if(miejsca[szczegoly.second*(i)+(j)]->pobierzStatus()=="TAK")
            {
                button->setStyleSheet("background-color: green;");
                mapper->setMapping(button,miejsca[szczegoly.second*(i)+(j)]);
                connect(button, &QPushButton::clicked, mapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
            }
            else
            {
                 button->setStyleSheet("background-color: red;");
            }
             buttons->addWidget(button);
        }
        area->addLayout(buttons);

    }
     ui->middle->addLayout(area);

}


void EkranWyboruMiejsc::initMapper()
{
    mapper = new QSignalMapper(this);

}

void EkranWyboruMiejsc::on_pbZatwierdz_clicked()
{
    // czyszczenie pola wyświetlania miejsc

    if(this->miejsca.length()!=0)
    {
        usunPrzyciskWyboruMiejsc(ui->middle);
        emit przejdzDoPlatnosci(this->miejsca,this->seans);
    }
}

// czyszczenie pola wyswietlania miejsc
void EkranWyboruMiejsc::usunPrzyciskWyboruMiejsc(QLayout* lay)
{
    QLayoutItem* child;
    while(lay->count()!=0)
    {
        child = lay->takeAt(0);
        if(child->layout() != 0)
        {
            usunPrzyciskWyboruMiejsc(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }
        delete child;
    }
}

// powrot do ekranu glownego (wybor sprzedazy i realizacji rezerwacji)
void EkranWyboruMiejsc::on_pbWroc_clicked()
{
    // czyszczenie pola wyświetlania miejsc
    usunPrzyciskWyboruMiejsc(ui->middle);
    // powrot do ekrannu glownego
    emit wroc();
}

