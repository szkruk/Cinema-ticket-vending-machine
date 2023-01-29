#include "ekranglowny.h"
#include "ui_ekranglowny.h"
#include <QCoreApplication>
EkranGlowny::EkranGlowny(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EkranGlowny)
{
    ui->setupUi(this);
}

EkranGlowny::~EkranGlowny()
{
    delete ui;
}

void EkranGlowny::on_pbZakup_clicked()
{
    emit zakup();
}

