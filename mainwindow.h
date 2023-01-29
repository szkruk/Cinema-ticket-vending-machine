#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ekranaktywacji.h>
#include <ekranglowny.h>
#include <ekranpodsumowania.h>
#include <ekranreperutar.h>
#include <ekranwyborumiejsc.h>
#include <oknoinformacyjne.h>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
    void przeniesDoEkranuGlownego();
    void przeniesDoRepertuaru();
    void przeniesDoMiejsc(QObject* obiekt);
    void przeniesDoPodsumowania(QList<Miejsce*> miejsca,Seans* seans);
    void przeniesDoOknaInformacyjnego(Platnosc* platnosc);

private:
    Ui::MainWindow *ui;
    EkranAktywacji ekranAktywacji;
    EkranGlowny ekranGlowny;
    EkranPodsumowania ekranPodsumowania;
    EkranReperutar ekranRepertuar;
    EkranWyboruMiejsc ekranWyboruMiejsc;
    OknoInformacyjne oknoInformacyjne;

};
#endif // MAINWINDOW_H
