#include "zahlenraten.h"
#include <cstdlib>
#include <ctime>

Zahlenraten::Zahlenraten(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    srand(time(nullptr));
    value = rand() % 100;
    output->setText("Rate eine Zahl von 0...99!");
}

void Zahlenraten::on_zehner_currentIndexChanged(int index)
{
    CheckValue();
}

void Zahlenraten::on_einer_currentIndexChanged(int index)
{
    CheckValue();
}

void Zahlenraten::CheckValue(void)
{
    int guess = zehner->currentIndex()*10 + einer->currentIndex();
    if (guess < value)
        output->setText("Höher!");
    else if (guess > value)
        output->setText("Niedriger!");
    else {
        output->setText("Gratulation! Neue Zahl eingeben:");
        value = rand() % 100;
    }

}



