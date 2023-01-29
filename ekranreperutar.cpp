#include "ekranreperutar.h"
#include "ui_ekranreperutar.h"
#include "konektorbazydanych.h"
#include "menadzeraplikacji.h"
#include "repertuar.h"

EkranReperutar::EkranReperutar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EkranReperutar)
{

    ui->setupUi(this);

    MenadzerAplikacji * myApp = App;
    Repertuar* repertuar = myApp->menKin->pobierzRepertuar();
    //Tutaj do zrobienia

    this->initMapper();
    ui->label->setText(data());
    QScrollArea* scrollArea = new QScrollArea;
    QWidget* layoutWidget = new QWidget;
    layoutWidget->setLayout(listaSeansow(repertuar));
    scrollArea->setWidget(layoutWidget);
    ui->mainL->addWidget(scrollArea);
    ui->mainL->setSizeConstraint(QLayout::SetMaximumSize);

    connect(mapper, QOverload<QObject *>::of(&QSignalMapper::mapped),
            [=](QObject *object){
        emit buttonClicked(object);
    });
}

EkranReperutar::~EkranReperutar()
{
    delete ui;
}



QHBoxLayout* EkranReperutar::jedenSeans(Film* fil, Repertuar* rep)
{
    KonektorBazyDanych konektor1;

    QHBoxLayout* Hlay = new QHBoxLayout;
    QFont font("Arial",18);

    QLabel* filmLabel = new QLabel(fil->getTytul());

    filmLabel->setFont(font);
    filmLabel->setAlignment(Qt::AlignLeft);
    QLabel* image = new QLabel ;
    QPixmap pixmap(fil->getSciezka());
    pixmap = pixmap.scaled(160,280, Qt::KeepAspectRatio);
    image->setPixmap(pixmap);

    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->setAlignment(Qt::AlignLeft);

    QList<Seans*> tempSeans = rep->pobierzSeanse();
    for(int i =0;i<tempSeans.length();i++)
    {
        if(fil == tempSeans[i]->getFilm())
        {
            QPushButton* button = new QPushButton ;
            button->setText(tempSeans[i]->godzina.toString());
            button->setFont(font);
            button->setMaximumSize(160,50);
            buttons->addWidget(button);
            mapper->setMapping(button,tempSeans[i]);
            connect(button, &QPushButton::clicked, mapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
            liczbaPrzyciskow+=1;
        }
        else{
            continue;
        }
    }


    QVBoxLayout* area = new QVBoxLayout ;
    area->setAlignment(Qt::AlignLeft);
    area->addWidget(filmLabel);

    area->addLayout(buttons);
    area->addSpacing(30);
    Hlay->addWidget(image);
    Hlay->addSpacing(30);
    Hlay->addLayout(area);
    Hlay->setAlignment(Qt::AlignLeft);
    return Hlay;
}

QVBoxLayout* EkranReperutar::listaSeansow( Repertuar* rep)
{

    QVBoxLayout* Vlay = new QVBoxLayout;

    QList<Film*> filmy = rep->pobierzFilmy();
    for (int i = 0; i < filmy.length(); i++) {
        Vlay->addLayout(jedenSeans(filmy[i],rep));
        Vlay->addSpacing(30);

    }
    return Vlay;
}

QString EkranReperutar::data()
{
    QDate date =QDate::currentDate();
    tekst = "Wybrana Data : ";
    tekst = tekst + date.toString("dd.MM.yyyy");
    return tekst;
}

void EkranReperutar::initMapper()
{
    mapper = new QSignalMapper(this);

}



void EkranReperutar::on_pbRepertuarWroc_clicked()
{
    emit repertuarWrocClicked();
}

