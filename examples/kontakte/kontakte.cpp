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
    for (size_t i = 0; i < sizeof(daten)/sizeof(daten[0]); i++)
            if (eingabe->text() == daten[i].name) {
                tel = daten[i].telefon;
                break;
            }
    ausgabe->setText(tel);
}
