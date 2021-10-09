#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Haine.h"
#include <string>
#include <string.h>

using namespace std;

//
//Clasa Haine
//
//Clasa Haine a fost derivata din clasa Produse prin relatia IS A
int Haine::stoc = 0;

string Haine::conversieTipdehaine(tip_de_haine tip)
{
    switch (tip) {
    case Tip_de_haine_necunoscut:
        return "Tip de haine necunoscut";
        break;
    case Jacheta:
        return "Jacheta";
        break;
    case Palton:
        return "Palton";
        break;
    case Sacou:
        return "Sacou";
        break;
    case Pulover:
        return "Pulover";
        break;
    case Cardigan:
        return "Cardigan";
        break;
    case Vesta:
        return "Vesta";
        break;
    case Tricou:
        return "Tricou";
        break;
    case Camasa:
        return "Camasa";
        break;
    case Bluza:
        return "Bluza";
        break;
    case Pantaloni:
        return "Pantaloni";
        break;
    case Blugi:
        return "Blugi";
        break;
    case Rochie:
        return "Rochie";
        break;
    case Fusta:
        return "Fusta";
        break;
    case Lenjerie:
        return "Lenjerie intima";
        break;
    case Costum_de_baie:
        return "Costum de baie";
        break;
    default:
        return "Codul introdus nu este corect";
        break;
    }
}
tip_de_haine conversieTipdehaine1(int nrtip)
{
    switch (nrtip)
    {
    case 0:
        return Tip_de_haine_necunoscut;
        break;
    case 1:
        return Jacheta;
        break;
    case 2:
        return Palton;
        break;
    case 3:
        return Sacou;
        break;
    case 4:
        return Pulover;
        break;
    case 5:
        return Cardigan;
        break;
    case 6:
        return Vesta;
        break;
    case 7:
        return Tricou;
        break;
    case 8:
        return Camasa;
        break;
    case 9:
        return Bluza;
        break;
    case 10:
        return Pantaloni;
        break;
    case 11:
        return Blugi;
        break;
    case 12:
        return Rochie;
        break;
    case 13:
        return Fusta;
        break;
    case 14:
        return Lenjerie;
        break;
    case 15:
        return Costum_de_baie;
        break;
    default:
        cout << "Codul introdus nu este corect";
        break;
    }
}

string Haine::conversieMarimi(marimi marime)
{
    switch (marime) {
    case Marime_necunoscuta:
        return "Marime necunoscuta";
        break;
    case XXS:
        return "XXS";
        break;
    case XS:
        return "XS";
        break;
    case S:
        return "S";
        break;
    case M:
        return "M";
        break;
    case L:
        return "L";
        break;
    case XL:
        return "XL";
        break;
    case XXL:
        return "XXL";
    case XXXL:
        return "XXXL";
    default:
        return "Codul introdus nu este corect";
        break;
    }
}
marimi conversieMarimi1(int nrmarime)
{
    switch (nrmarime)
    {
    case 0:
        return Marime_necunoscuta;
        break;
    case 1:
        return XXS;
        break;
    case 2:
        return XS;
        break;
    case 3:
        return S;
        break;
    case 4:
        return M;
        break;
    case 5:
        return L;
        break;
    case 6:
        return XL;
        break;
    case 7:
        return XXL;
        break;
    case 8:
        return XXXL;
        break;
    }
}

string Haine::conversieCulori(culori culoare)
{
    switch (culoare) {
    case Culoare_necunoscuta:
        return "Culoare necunoscuta";
        break;
    case Negru:
        return "Negru";
        break;
    case Alb:
        return "Alb";
        break;
    case Rosu:
        return "Rosu";
        break;
    case Albastru:
        return "Albastru";
        break;
    case Galben:
        return "Galben";
        break;
    case Verde:
        return "Verde";
        break;
    case Gri:
        return "Gri";
        break;
    case Violet:
        return "Violet";
        break;
    case Roz:
        return "Roz";
        break;
    case Maro:
        return "Maro";
        break;
    default:
        return "Codul introdus nu este corect";
        break;
    }
}
culori conversieCulori1(int nrculoare)
{
    switch (nrculoare)
    {
    case 0:
        return Culoare_necunoscuta;
        break;
    case 1:
        return Negru;
        break;
    case 2:
        return Alb;
        break;
    case 3:
        return Rosu;
        break;
    case 4:
        return Albastru;
        break;
    case 5:
        return Galben;
        break;
    case 6:
        return Verde;
        break;
    case 7:
        return Gri;
        break;
    case 8:
        return Violet;
        break;
    case 9:
        return Roz;
        break;
    case 10:
        return Maro;
        break;
    }
}


void Haine::afisareTipdehaine()
{
    cout << "Avem urmatoarele tipuri de haine:" << endl;
    cout << "1. Jacheta" << endl;
    cout << "2. Palton" << endl;
    cout << "3. Sacou" << endl;
    cout << "4. Pulover" << endl;
    cout << "5. Cardigan" << endl;
    cout << "6. Vesta" << endl;
    cout << "7. Tricou" << endl;
    cout << "8. Camasa" << endl;
    cout << "9. Bluza" << endl;
    cout << "10. Pantaloni" << endl;
    cout << "11. Blugi" << endl;
    cout << "12. Rochie" << endl;
    cout << "13. Fusta" << endl;
    cout << "14. Lenjerie intima" << endl;
    cout << "15. Costum de baie" << endl;
}

void Haine::afisareMarimi()
{
    cout << "Avem urmatoarele marimi de haine: " << endl;
    cout << "1. XXS" << endl;
    cout << "2. XS" << endl;
    cout << "3. S" << endl;
    cout << "4. M" << endl;
    cout << "5. L" << endl;
    cout << "6. XL" << endl;
    cout << "7. XXL" << endl;
    cout << "8. XXL" << endl;
}

void Haine::afisareCulori()
{
    cout << "Avem urmatoarele culori pentru haine: " << endl;
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

void Haine::welcome() {
    cout << endl << "Sunteti la Sectia Haine!" << endl;
}

void Haine::alege_task() {
    cout << endl << "Va rugam alegeti urmatorul pas:" << endl;
    cout << "1. Vreau sa imi aleg un articol pentru a adauga in cos" << endl;
    cout << "2. Vreau sa ma intorc la meniul principal" << endl;
}

//setter & getter
void Haine::setTip(tip_de_haine tip) { this->tip = tip; }
string Haine::getTip() { return conversieTipdehaine(tip); }

void Haine::setMarime(marimi marime) { this->marime = marime; }
string Haine::getMarime() { return conversieMarimi(marime); }

void Haine::setCuloare(culori culoare) { this->culoare = culoare; }
string Haine::getCuloare() { return conversieCulori(culoare); }

int Haine::getStoc() { return stoc; }

//constructor
Haine::Haine(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, 
    int nrVarste, int* varste, char gen, int nrtip, int nrmarime, int nrculoare)
    :Produse(eco, adaugate_cos, nrMateriale, materiale, pret, nrVarste, varste, gen)
{
    this->stoc++;
    this->tip = conversieTipdehaine1(nrtip);
    this->marime = conversieMarimi1(nrmarime);
    this->culoare = conversieCulori1(nrculoare);

}
//constructor cu 2 parametrii
Haine::Haine(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, 
    int nrVarste, int* varste, char gen, int nrtip, int nrmarime)
    :Produse(eco, adaugate_cos, nrMateriale, materiale, pret, nrVarste, varste, gen)
{
    this->stoc++;
    this->tip = conversieTipdehaine1(nrtip);
    this->marime = conversieMarimi1(nrmarime);
}
//constructor fara param
Haine::Haine():Produse()
{
    this->stoc++;
    this->tip = Tip_de_haine_necunoscut;
    this->marime = Marime_necunoscuta;
    this->culoare = Culoare_necunoscuta;
}
//desctructor
Haine::~Haine()
{
}
//constructor de copiere
Haine::Haine(const Haine& h):Produse(h)
{
    this->tip = h.tip;
    this->marime = h.marime;
    this->culoare = h.culoare;
}

// operator =
Haine Haine::operator=(Haine h)
{
    Produse::operator=(h);
    this->tip = h.tip;
    this->marime = h.marime;
    this->culoare = h.culoare;
    return *this;
}

//afisare
ostream& operator<<(std::ostream& out, Haine& h)
{
    out << (Produse&)h;

    out << "Tipul de haina este: " << h.conversieTipdehaine(h.tip) << endl;
    out << "Marimea este: " << h.conversieMarimi(h.marime) << endl;
    out << "Culoarea este: " << h.conversieCulori(h.culoare) << endl;
    return out;
}

//citire 
istream& operator>>(std::istream& in, Haine& h)
{
    //in >> (Produse&)h;

    int nrtip, nrmarime, nrculoare;
    cout << "Alegeti ce tip de haina doriti (introduceti numarul):" << endl;
    h.afisareTipdehaine();
    in >> nrtip;
    h.tip = conversieTipdehaine1(nrtip);

    cout << "Alegeti ce marime doriti (introduceti numarul):" << endl;
    h.afisareMarimi();
    in >> nrmarime;
    h.marime = conversieMarimi1(nrmarime);

    cout << "Alegeti ce culoare doriti (introduceti numarul):" << endl;
    h.afisareCulori();
    in >> nrculoare;
    h.culoare = conversieCulori1(nrculoare);

    return in;
}
