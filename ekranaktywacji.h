#ifndef EKRANAKTYWACJI_H
#define EKRANAKTYWACJI_H

#include <QWidget>
#include <QEvent>
namespace Ui {
class EkranAktywacji;
}

class EkranAktywacji : public QWidget
{
    Q_OBJECT

public:
    explicit EkranAktywacji(QWidget *parent = nullptr);
    ~EkranAktywacji();
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::EkranAktywacji *ui;

signals:
    void przejdz();
};

#endif // EKRANAKTYWACJI_H
