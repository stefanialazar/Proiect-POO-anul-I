#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Produse.h"
#include <string>
#include <string.h>

using namespace std;

//
//Clasa Produse
//

const string Produse::nume_magazin = "Ivy Lakes";
int Produse::nrProd = 0;

float Produse::calc_pret_cu_TVA() {

    return (this->pret * 19 / 100) + this->pret;

}

//setter & getter
string Produse::getNume_magazin() { return this->nume_magazin; }
int Produse::getNr_prod() { return this->nrProd; }
int Produse::getId_produs() { return this->id_produs; }

void Produse::setEco(bool eco) { this->eco = eco; }
bool Produse::getEco() { return this->eco; }

void Produse::setAdaugate_cos(int adaugate_cos) { this->adaugate_cos = adaugate_cos; }
int Produse::getAdaugate_cos() { return this->adaugate_cos; }

void Produse::setNrmateriale(int nrMateriale) { this->nrMateriale = nrMateriale; }
int Produse::getNrmateriale() { return this->nrMateriale; }

void Produse::setMateriale(std::string* materiale, int nrMateriale)
{
    if (this->materiale != NULL)
        delete[] this->materiale;
    this->materiale = new string[this->nrMateriale];
    for (int i = 0; i < nrMateriale; i++)
        this->materiale[i] = materiale[i];
}
string* Produse::getMateriale() { return this->materiale; }

void Produse::setPret(float pret) { this->pret = pret; }
float Produse::getPret() { return this->pret; }

void Produse::setNrvarste(int nrVarste) { this->nrVarste = nrVarste; }
int Produse::getNrvarste() { return this->nrVarste; }

void Produse::setVarste(int* varste, int nrVarste)
{
    if (this->varste != NULL)
        delete[] this->varste;
    this->varste = new int[this->nrVarste];
    for (int i = 0; i < nrVarste; i++)
        this->varste[i] = varste[i];
}
int* Produse::getVarste() { return this->varste; }

void Produse::setGen(char gen) { this->gen = gen; }
char Produse::getGen() { return this->gen; }

//stergem un produs
void Produse::stergeProdus(Produse& prod)
{
    prod.pret = -1;
}

//constructor bun la toate
Produse::Produse(bool eco, int adaugate_cos, int nrMateriale, string* materiale, float pret, int nrVarste, int* varste, char gen) : id_produs(nrProd + 1)
{
    nrProd++;
    this->eco = eco;
    this->adaugate_cos = adaugate_cos;

    if (this->materiale != NULL)
        delete[] this->materiale;
    this->nrMateriale = nrMateriale;
    this->materiale = new string[this->nrMateriale];
    for (int i = 0; i < nrMateriale; i++)
        this->materiale[i] = materiale[i];

    this->pret = pret;

    if (this->varste != NULL)
        delete[] this->varste;
    this->nrVarste = nrVarste;
    this->varste = new int[this->nrVarste];
    for (int i = 0; i < nrVarste; i++)
        this->varste[i] = varste[i];

    this->gen = gen;

}

//constructor doar pentru materiale si varste
Produse::Produse(int nrMateriale, string* materiale, int nrVarste, int* varste) : id_produs(nrProd + 1)
{
    nrProd++;
    this->eco = false;
    this->adaugate_cos = 0;

    if (this->materiale != NULL)
        delete[] this->materiale;
    this->nrMateriale = nrMateriale;
    this->materiale = new string[this->nrMateriale];
    for (int i = 0; i < nrMateriale; i++)
        this->materiale[i] = materiale[i];

    if (this->varste != NULL)
        delete[] this->varste;
    this->nrVarste = nrVarste;
    this->varste = new int[this->nrVarste];
    for (int i = 0; i < nrVarste; i++)
        this->varste[i] = varste[i];

    this->pret = 0;
    this->gen = ' ';
}

//constructor fara parametrii
Produse::Produse() : id_produs(nrProd + 1)
{
    nrProd++;
    this->eco = false;
    this->adaugate_cos = 0;
    this->nrMateriale = 0;
    this->materiale = new string[1];
    this->nrVarste = 0;
    this->varste = new int[1];
    this->pret = 0;
    this->gen = ' ';
}

//destructor
Produse::~Produse()
{
    if (this->materiale != NULL)
        delete[] materiale;
    if (this->varste != NULL)
        delete[] varste;
}

//constructor  de copiere
Produse::Produse(const Produse& prod) : id_produs(nrProd + 1)
{
    nrProd++;
    this->eco = prod.eco;
    this->adaugate_cos = prod.adaugate_cos;

    this->nrMateriale = prod.nrMateriale;
    this->materiale = new string[prod.nrMateriale];
    for (int i = 0; i < prod.nrMateriale; i++)
        this->materiale[i] = prod.materiale[i];
    this->pret = prod.pret;

    this->nrVarste = prod.nrVarste;
    this->varste = new int[prod.nrVarste];
    for (int i = 0; i < prod.nrVarste; i++)
        this->varste[i] = prod.varste[i];

    this->gen = prod.gen;
}

//operator =
Produse Produse::operator=(Produse prod)
{
    nrProd++;
    this->eco = prod.eco;
    this->adaugate_cos = prod.adaugate_cos;

    if (this->materiale != NULL)
        delete[] this->materiale;
    this->nrMateriale = prod.nrMateriale;
    this->materiale = new string[prod.nrMateriale];
    for (int i = 0; i < prod.nrMateriale; i++)
        this->materiale[i] = prod.materiale[i];

    this->pret = prod.pret;

    if (this->varste != NULL)
        delete[] this->varste;
    this->nrVarste = prod.nrVarste;
    this->varste = new int[prod.nrVarste];
    for (int i = 0; i < prod.nrVarste; i++)
        this->varste[i] = prod.varste[i];

    this->gen = prod.gen;
    return *this;
}

//operator <<
ostream& operator<<(ostream& out, Produse& prod)
{
    if (prod.pret == -1)
    {
        out << "Produsul a fost sters" << endl;
        return out;
    }
    else
    {
        out << "Numele dupa eticheta produsului este " << prod.nume_magazin << endl;
        if (prod.eco == 1)
            out << "Produsul este eco friendly" << endl;
        else out << "Produsul nu este eco friendly" << endl;
        if (prod.adaugate_cos == 0)
            out << "Nu avem acest produs in cos" << endl;
        else
            out << "Acest produs este de un numar de " << prod.adaugate_cos << " ori in cos" << endl;
        if (prod.nrMateriale == 0)
            out << "Nu avem informatii despre materialele folosite" << endl;
        else
        {
            out << "Materialul/materialele din care este facut produsul sunt ";
            for (int i = 0; i < prod.nrMateriale; i++)
                out << prod.materiale[i] << "; ";
            out << endl;
        }

        out << "Pretul produsului fara TVA este " << prod.pret << endl;
        out << "Pretul produsului cu TVA este " << prod.calc_pret_cu_TVA() << endl;
        if (prod.nrVarste == 0)
            out << "Nu avem informatii despre varstele sugerate" << endl;
        else
        {
            out << "Varstele sugerate pentru acest produs sunt ";
            for (int i = 0; i < prod.nrVarste; i++)
                out << prod.varste[i] << " ";
            out << endl;
        }
        if (prod.gen == ' ')
            out << "Nu avem informatii despre genul sugerat" << endl;
        else
            out << "Genul sugerat pentru acest produs este " << prod.gen << endl;
        return out;
    }
}

//operator >>
istream& operator>>(istream& in, Produse& prod)
{
    prod.nrProd++;
    std::cout << "Numele magazinului este " << prod.nume_magazin << endl;
    std::cout << "Produsul este eco friendly [1-true/0-false] ";
    in >> prod.eco;
    std::cout << "Cate produse de acest tip se afla in cos ";
    in >> prod.adaugate_cos;
    std::cout << "Numarul de materiale este ";
    in >> prod.nrMateriale;
    std::cout << "Materialul/materialele din care este facut produsul sunt ";
    if (prod.materiale != NULL)
        delete[] prod.materiale;
    prod.materiale = new string[prod.nrMateriale];
    for (int i = 0; i < prod.nrMateriale; i++)
        in >> prod.materiale[i];
    std::cout << "Pretul produsului este ";
    in >> prod.pret;
    std::cout << "Numarul de varste sugerate este ";
    in >> prod.nrVarste;
    std::cout << "Varstele sugerate pentru acest produs sunt ";
    if (prod.varste != NULL)
        delete[] prod.varste;
    prod.varste = new int[prod.nrVarste];
    for (int i = 0; i < prod.nrVarste; i++)
        in >> prod.varste[i];
    std::cout << "Genul sugerat pentru acest produs este [M-male/F-female/U-unisex] ";
    in >> prod.gen;
    return in;
}

//operator citire DIN FISIER
ifstream& operator>>(ifstream& in, Produse& prod)
{
    prod.nrProd++;
    in >> prod.eco;
    in >> prod.adaugate_cos;
    in >> prod.nrMateriale;
    if (prod.materiale != NULL)
        delete[] prod.materiale;
    prod.materiale = new string[prod.nrMateriale];
    for (int i = 0; i < prod.nrMateriale; i++)
        in >> prod.materiale[i];
    in >> prod.pret;
    in >> prod.nrVarste;
    if (prod.varste != NULL)
        delete[] prod.varste;
    prod.varste = new int[prod.nrVarste];
    for (int i = 0; i < prod.nrVarste; i++)
        in >> prod.varste[i];
    in >> prod.gen;
    return in;
}

void Produse::citireFisier(ifstream& fisier)
{
    this->nrProd++;
    fisier >> this->eco;
    fisier >> this->adaugate_cos;
    fisier >> this->nrMateriale;
    if (this->materiale != NULL)
        delete[] this->materiale;
    this->materiale = new string[this->nrMateriale];
    for (int i = 0; i < this->nrMateriale; i++)
        fisier >> this->materiale[i];
    fisier >> this->pret;
    fisier >> this->nrVarste;
    if (this->varste != NULL)
        delete[] this->varste;
    this->varste = new int[this->nrVarste];
    for (int i = 0; i < this->nrVarste; i++)
        fisier >> this->varste[i];
    fisier >> this->gen;
}


//operator []
int Produse::operator[](int index)
{
    if (index >= 0 && index < this->nrMateriale)
    {
        if (this->materiale[index] == "piele")
            return 1;
        else
            return 0;
    }
}

//operator ++
//adaugam un produs in cos
//pre-incrementare
const Produse& Produse::operator++()
{
    this->adaugate_cos++;
    return *this;
}
//post-incrementare
const Produse Produse::operator++(int)
{
    Produse aux(*this);
    aux.adaugate_cos++;
    return aux;
}

//operator --
//scadem un produs din cos
//pre-incrementare
const Produse& Produse::operator--()
{
    this->adaugate_cos--;
    return *this;
}
//post-incrementare
const Produse Produse::operator--(int)
{
    Produse aux(*this);
    if (aux.adaugate_cos == 0)
        return aux;
    aux.adaugate_cos--;
    return aux;
}

//operator+
Produse Produse::operator+(Produse prod2)
{
    Produse prod1 = *this;
    prod1.nrVarste = this->nrVarste + prod2.nrVarste;
    if (prod1.varste != NULL)
        delete[] prod1.varste;
    prod1.varste = new int[prod1.nrVarste];
    for (int i = 0; i < this->nrVarste; i++)
        prod1.varste[i] = this->varste[i];
    for (int i = 0; i < prod2.nrVarste; i++)
        prod1.varste[i + this->nrVarste] = prod2.varste[i];
    return prod1;
}

//operator-
Produse Produse::operator-(Produse& prod2)
{
    if (this->pret > prod2.pret)
    {
        this->pret -= prod2.pret;
        return *this;
    }
    else if (prod2.pret > this->pret)
    {
        prod2.pret -= this->pret;
        this->pret = 0;
        return *this;
    }
    else
    {
        this->pret -= prod2.pret;
        return *this;
    }
}

//operatorul cast implicit
Produse::operator int() {
    return this->id_produs;
}

//operator >
// verificam daca pretul primului produs e mai mare decat al celui de-al doilea 
bool Produse::operator>(const Produse& prod)
{
    if (this->pret > prod.pret)
        return true;
    return false;
}

//operator (==)
// verificam daca ambele produse sunt ecologice
bool Produse::operator==(const Produse& prod)
{
    if (this->eco == prod.eco)
        return true;
    return false;
}