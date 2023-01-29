#include "menadzeraplikacji.h"

int main(int argc, char *argv[])
{
    MenadzerAplikacji mA(argc, argv);

    mA.inicjujEkran();
    return mA.exec();
}
