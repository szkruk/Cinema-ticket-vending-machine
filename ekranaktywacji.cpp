#include "ekranaktywacji.h"
#include "ui_ekranaktywacji.h"
#include "QDebug"

EkranAktywacji::EkranAktywacji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EkranAktywacji)
{

    ui->setupUi(this);
    QPixmap zdjecie("../QT/images/ekranAktywacji.png");
    ui->zdjecie->setPixmap(zdjecie);
    ui->zdjecie->installEventFilter(this);

}

EkranAktywacji::~EkranAktywacji()
{
    delete ui;
}


bool EkranAktywacji::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        emit przejdz();
        return true;
    }
    return QObject::eventFilter(obj, event);
}
