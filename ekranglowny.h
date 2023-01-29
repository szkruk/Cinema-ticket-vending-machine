#ifndef EKRANGLOWNY_H
#define EKRANGLOWNY_H

#include <QWidget>

namespace Ui {
class EkranGlowny;
}

class EkranGlowny : public QWidget
{
    Q_OBJECT

public:
    explicit EkranGlowny(QWidget *parent = nullptr);
    ~EkranGlowny();

signals:
    void zakup();
private slots:
    void on_pbZakup_clicked();

private:
    Ui::EkranGlowny *ui;
};

#endif // EKRANGLOWNY_H
