#include "kontakte.h"
#include "daten.h"

Kontakte::Kontakte(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Kontakte::on_eingabe_returnPressed()
{
    QString tel = "nicht gefunden!";
    for (size_t i = 0; i < daten.size(); i++)
            if (eingabe->text() == daten.at(i).name) {
                tel = daten.at(i).telefon;
                break;
            }
    ausgabe->setText(tel);
}
