#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Incaltaminte.h"
#include <string>
#include <string.h>

using namespace std;

//
//CLASA Incaltaminte
//
////Clasa Incaltaminte a fost derivata din clasa Produse prin relatia IS A

int Incaltaminte::stoc = 0;

string Incaltaminte::conversieTipdeincalt(tip_de_incalt tip)
{
    switch (tip) {
    case Tip_necunoscut:
        return "Tip de incaltaminte necunoscut";
        break;
    case Adidasi:
        return "Adidasi";
        break;
    case Sandale:
        return "Sandale";
        break;
    case Pantofi:
        return "Pantofi";
        break;
    case Pantofi_cu_toc:
        return "Pantofi cu toc";
        break;
    case Ghete:
        return "Ghete";
        break;
    case Bocanci:
        return "Bocanci";
        break;
    case Papuci:
        return "Papuci";
        break;
    default:
        return "Codul introdus nu este corect";
        break;
    }
}
tip_de_incalt conversieTipdeincalt1(int nrtip)
{
    switch (nrtip)
    {
    case 0:
        return Tip_necunoscut;
        break;
    case 1:
        return Adidasi;
        break;
    case 2:
        return Sandale;
        break;
    case 3:
        return Pantofi;
        break;
    case 4:
        return Pantofi_cu_toc;
        break;
    case 5:
        return Ghete;
        break;
    case 6:
        return Bocanci;
        break;
    case 7:
        return Papuci;
        break;
    default:
        cout << "Codul introdus nu este corect";
        break;
    }
}

string Incaltaminte::conversieCuloriincalt(culori_incalt culoare)
{
    switch (culoare) {
    case Culoare_necunoscuta1:
        return "Culoare necunoscuta";
        break;
    case Negru1:
        return "Negru";
        break;
    case Alb1:
        return "Alb";
        break;
    case Rosu1:
        return "Rosu";
        break;
    case Albastru1:
        return "Albastru";
        break;
    case Galben1:
        return "Galben";
        break;
    case Verde1:
        return "Verde";
        break;
    case Gri1:
        return "Gri";
        break;
    case Violet1:
        return "Violet";
        break;
    case Roz1:
        return "Roz";
        break;
    case Maro1:
        return "Maro";
        break;
    default:
        return "Codul introdus nu este corect";
        break;
    }
}
culori_incalt conversieCuloriincalt1(int nrculoare)
{
    switch (nrculoare)
    {
    case 0:
        return Culoare_necunoscuta1;
        break;
    case 1:
        return Negru1;
        break;
    case 2:
        return Alb1;
        break;
    case 3:
        return Rosu1;
        break;
    case 4:
        return Albastru1;
        break;
    case 5:
        return Galben1;
        break;
    case 6:
        return Verde1;
        break;
    case 7:
        return Gri1;
        break;
    case 8:
        return Violet1;
        break;
    case 9:
        return Roz1;
        break;
    case 10:
        return Maro1;
        break;
    }
}

void Incaltaminte::afisareTipdeincalt()
{
    cout << "Avem urmatoarele tipuri de incaltaminte:" << endl;
    cout << "1. Adidasi" << endl;
    cout << "2. Sandale" << endl;
    cout << "3. Pantofi" << endl;
    cout << "4. Pantofi cu toc" << endl;
    cout << "5. Ghete" << endl;
    cout << "6. Bocanci" << endl;
    cout << "7. Papuci" << endl;
}
void Incaltaminte::afisareCuloriincalt()
{
    cout << "Avem urmatoarele culori pentru incaltaminte: " << endl;
    cout << "1. Negru" << endl;
    cout << "2. Alb" << endl;
    cout << "3. Rosu" << endl;
    cout << "4. Albastru" << endl;
    cout << "5. Galben" << endl;
    cout << "6. Verde" << endl;
    cout << "7. Gri" << endl;
    cout << "8. Violet" << endl;
    cout << "9. Roz" << endl;
    cout << "10. Maro" << endl;
}

void Incaltaminte::welcome() {
    cout << endl << "Sunteti la Sectia Incaltaminte!" << endl;
}

void Incaltaminte::alege_task() {
    cout << endl << "Va rugam alegeti urmatorul pas:" << endl;
    cout << "1.Vreau sa aleg tipul de incaltaminte, marimea si culoarea pentru a adauga articolul in cos" << endl;
    cout << "2.Vreau sa ma intorc la meniul principal" << endl;
}

//setter & getter
int Incaltaminte::getStoc() { return stoc; }

void Incaltaminte::setTip(tip_de_incalt  tip) { this->tip = tip; }
string Incaltaminte::getTip() { return conversieTipdeincalt(tip); }

void Incaltaminte::setCuloare(culori_incalt culoare) { this->culoare = culoare; }
string Incaltaminte::getCuloare() { return conversieCuloriincalt(culoare); }

float Incaltaminte::getMarime() { return this->marime; }

//constructor
Incaltaminte::Incaltaminte(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret,
    int nrVarste, int* varste, char gen, int nrtip, float marime, int nrculoare)
    :Produse(eco, adaugate_cos, nrMateriale, materiale, pret, nrVarste, varste, gen)
{
    this->stoc++;
    this->tip = conversieTipdeincalt1(nrtip);
    this->marime = marime;
    this->culoare = conversieCuloriincalt1(nrculoare);
}

//constructor cu 2 param
Incaltaminte::Incaltaminte(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret,
    int nrVarste, int* varste, char gen, int nrtip, float marime)
    :Produse(eco, adaugate_cos, nrMateriale, materiale, pret, nrVarste, varste, gen)
{
    this->stoc++;
    this->tip = conversieTipdeincalt1(nrtip);
    this->marime = marime;
}

//constructor fara param
Incaltaminte::Incaltaminte():Produse()
{
    this->stoc++;
    this->tip = Tip_necunoscut;
    this->marime = 0;
    this->culoare = Culoare_necunoscuta1;
}

//desctructor
Incaltaminte::~Incaltaminte()
{
}

//constructor de copiere
Incaltaminte::Incaltaminte(const Incaltaminte& incal):Produse(incal)
{
    this->tip = incal.tip;
    this->marime = incal.marime;
    this->culoare = incal.culoare;
}

// operator =
Incaltaminte Incaltaminte::operator=(Incaltaminte incal)
{
    Produse::operator=(incal);
    this->tip = incal.tip;
    this->marime = incal.marime;
    this->culoare = incal.culoare;
    return *this;
}

//afisare
ostream& operator<<(std::ostream& out, Incaltaminte& incal)
{
    out << (Produse&)incal;

    out << "Tipul de incaltaminte este: " << incal.conversieTipdeincalt(incal.tip) << endl;
    out << "Marimea este: " << incal.marime << endl;
    out << "Culoarea este: " << incal.conversieCuloriincalt(incal.culoare) << endl;
    return out;
}

//citire 
istream& operator>>(std::istream& in, Incaltaminte& incal)
{
    //in >> (Produse&)incal;

    int nrtip, nrculoare;
    cout << "Alegeti ce tip de incaltaminte doriti (introduceti numarul): " << endl;
    incal.afisareTipdeincalt();
    in >> nrtip;
    incal.tip = conversieTipdeincalt1(nrtip);

    cout << "Alegeti ce marime doriti (introduceti numarul):" << endl;
    in >> incal.marime;

    cout << "Alegeti ce culoare doriti (introduceti numarul):" << endl;
    incal.afisareCuloriincalt();
    in >> nrculoare;
    incal.culoare = conversieCuloriincalt1(nrculoare);

    return in;
}
