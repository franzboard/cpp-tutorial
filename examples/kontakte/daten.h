#ifndef DATEN_H
#define DATEN_H

typedef struct {
    QString name;
    QString telefon;
} telefonbuch;

vector<telefonbuch> daten = {
    {"BULME", "+43 316 6081"},
    {"Postgarage", "+43 316 722937"},
    {"Stadtbibliothek", "+43 316 8724980"}
};

#endif // DATEN_H
