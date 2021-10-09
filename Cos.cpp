#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Cos.h"
#include "Haine.h"
#include "Incaltaminte.h"
#include <string>
#include <string.h>

using namespace std;

//
//CLASA Cos
//

Cos& Cos::adauga_haina(Haine h)
{
    this->toate_hainele.push_back(h);
    this->prod_total_cos += h.getAdaugate_cos();
    for(int i=0 ; i< h.getAdaugate_cos(); i++)
        this->nume_produse.push_back(h.getTip());
    for (int i = 0; i < h.getAdaugate_cos(); i++)
        this->pret_total_cos += h.calc_pret_cu_TVA();
    return *this;
}
Cos& Cos::adauga_incal(Incaltaminte incal)
{
    this->toate_incal.push_back(incal);
    this->prod_total_cos += incal.getAdaugate_cos();
    for (int i = 0; i < incal.getAdaugate_cos(); i++)
        this->nume_produse.push_back(incal.getTip());
    for (int i = 0; i < incal.getAdaugate_cos(); i++)
        this->pret_total_cos += incal.calc_pret_cu_TVA();
    return *this;
}

Cos& Cos::elimina_haina(Haine h)
{
    for (int i = 0; i < this->toate_hainele.size(); i++)
        if (toate_hainele[i].getTip() == h.getTip() && toate_hainele[i].getCuloare() == h.getCuloare() && toate_hainele[i].getMarime() == h.getMarime())
            this->toate_hainele.erase(this->toate_hainele.begin() + i);
            
    for (int i = 0; i < h.getAdaugate_cos(); i++)
        this->pret_total_cos -= h.calc_pret_cu_TVA();

    for (int i = 0; i < prod_total_cos; i++)
        if (this->nume_produse[i] == h.getTip())
        {
            this->nume_produse.erase(this->nume_produse.begin() + i);
            i--;
            this->prod_total_cos -= 1;
        }
    return *this;
}

Cos& Cos::elimina_incal(Incaltaminte incal)
{
    for (int i = 0; i < this->toate_incal.size(); i++)
        if (toate_incal[i].getTip() == incal.getTip() && toate_incal[i].getCuloare() == incal.getCuloare() && toate_incal[i].getMarime() == incal.getMarime())
            this->toate_incal.erase(this->toate_incal.begin() + i);

    for (int i = 0; i < incal.getAdaugate_cos(); i++)
        this->pret_total_cos -= incal.calc_pret_cu_TVA();

    for (int i = 0; i < prod_total_cos; i++)
        if (this->nume_produse[i] == incal.getTip())
        {
            this->nume_produse.erase(this->nume_produse.begin() + i);
            i--;
            this->prod_total_cos -= 1;
        }
    return *this;
}

//setter & getter

vector <Haine> Cos::getToate_hainele() { return this->toate_hainele; }
vector <Incaltaminte> Cos::getToate_incal() { return this->toate_incal; }

void Cos::setNume_produse(vector <string> nume_produse, int prod_total_cos)
{
    for (int i = 0; i < prod_total_cos; i++)
        this->nume_produse[i] = nume_produse[i];
}
vector <string> Cos::getNume_produse() { return this->nume_produse; }

void Cos::setProd_cos(int prod_total_cos) { this->prod_total_cos = prod_total_cos; }
int Cos::getProd_cos() { return this->prod_total_cos; }

void Cos::setTotal_cos(double pret_total_cos) { this->pret_total_cos = pret_total_cos; }
double Cos::getTotal_cos() { return this->pret_total_cos; }

void Cos::setNumeclient(char* nume_client)
{
    if (this->nume_client != NULL)
        delete[] this->nume_client;
    this->nume_client = new char[strlen(nume_client) + 1];
    strcpy(this->nume_client, nume_client);
}
char* Cos::getNumeclient() { return this->nume_client; }

//constructor bun la toate
Cos::Cos(int prod_total_cos, double pret_total_cos, vector <string> nume_produse, char* nume_client)
{
    this->prod_total_cos = prod_total_cos;
    this->pret_total_cos = pret_total_cos;

    for (int i = 0; i < prod_total_cos; i++)
        this->nume_produse[i] = nume_produse[i];

    if (this->nume_client != NULL)
        delete[] this->nume_client;
    this->nume_client = new char[strlen(nume_client) + 1];
    strcpy(this->nume_client, nume_client);

}

//constructor cu 2 param
Cos::Cos(int prod_total_cos, double pret_total_cos)
{
    this->prod_total_cos = prod_total_cos;
    this->pret_total_cos = pret_total_cos;
}

//constructor fara param
Cos::Cos()
{
    this->prod_total_cos = 0;
    this->pret_total_cos = 0;

    if (this->nume_client != NULL)
        delete[] this->nume_client;
    this->nume_client = new char[10];
    strcpy(this->nume_client, "Anonim");

}

//destructor
Cos::~Cos()
{
    if (this->nume_client != NULL)
        delete[] this->nume_client;
}

//constructor de copiere
Cos::Cos(const Cos& cos)
{
    int nr_haine = cos.toate_hainele.size();
    int nr_incal = cos.toate_incal.size();
    for (int i = 0; i < nr_haine ; i++)
        this->toate_hainele.push_back(cos.toate_hainele[i]);

    for (int i = 0; i < nr_incal; i++)
        this->toate_incal.push_back(cos.toate_incal[i]);

    this->prod_total_cos = cos.prod_total_cos;
    this->pret_total_cos = cos.pret_total_cos;

    for (int i = 0; i < prod_total_cos; i++)
        this->nume_produse.push_back(cos.nume_produse[i]);

    this->nume_client = new char[strlen(cos.nume_client) + 1];
    strcpy(this->nume_client, cos.nume_client);

}

// operator =
Cos Cos::operator=(Cos cos)
{
    int nr_haine = cos.toate_hainele.size();
    int nr_incal = cos.toate_incal.size();
    for (int i = 0; i < nr_haine; i++)
        this->toate_hainele.push_back(cos.toate_hainele[i]);

    for (int i = 0; i < nr_incal; i++)
        this->toate_incal.push_back(cos.toate_incal[i]);

    this->prod_total_cos = cos.prod_total_cos;
    this->pret_total_cos = cos.pret_total_cos;

    for (int i = 0; i < prod_total_cos; i++)
        this->nume_produse.push_back(cos.nume_produse[i]);

    if (this->nume_client != NULL)
        delete[] this->nume_client;
    this->nume_client = new char[strlen(cos.nume_client) + 1];
    strcpy(this->nume_client, cos.nume_client);
    return *this;

}

// operator << 
ostream& operator<<(ostream& out, Cos& cos)
{
    if (strcmp(cos.nume_client, "Anonim") == 0)
        out << "Nu avem informatii despre client" << endl;
    else
        out << "Numele clientului este " << cos.nume_client << endl;
    if (cos.prod_total_cos == 0)
        out << "Nu avem produse in cos" << endl;
    else
    {
        out << "Avem " << cos.prod_total_cos << " produse in cos" << endl;
        out << "Produsele din cos sunt ";
        for (int i = 0; i < cos.prod_total_cos; i++)
            out << cos.nume_produse[i] << " ";
        out << endl;
    }
    out << "Pretul tuturor produselor din cos este " << cos.pret_total_cos << endl;
    return out;
}

// operator >>  
istream& operator>>(std::istream& in, Cos& cos)
{
    std::cout << "Numele clientului este ";
    in >> cos.nume_client;
    std::cout << "Numarul de produse din cos este ";
    in >> cos.prod_total_cos;
    std::cout << "Produsele din cos sunt ";
    string nume;
    for (int i = 0; i < cos.prod_total_cos; i++)
    {
        in >> nume;
        cos.nume_produse.push_back(nume);
    }
    std::cout << "Pretul total din cos este ";
    in >> cos.pret_total_cos;
    return in;
}


////operator []
//int Cos::operator[](int index)
//{
//    if (index >= 0 && index < this->prod_total_cos)
//    {
//        if (this->nume_produse[index] == "Tricou")
//        {
//            return 1;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//}

//operator ++
//adaugam un produs in cos
//pre-incrementare
const Cos& Cos::operator++()
{
    this->prod_total_cos++;
    return *this;
}
//post-incrementare
const Cos Cos::operator++(int)
{
    Cos aux(*this);
    aux.prod_total_cos++;
    return aux;
}

//operator+
//calculeaza pretul total din ambele cosuri
Cos Cos::operator+(Cos cos2)
{
    Cos cos1 = *this;
    cos1.prod_total_cos = this->prod_total_cos + cos2.prod_total_cos;
    cos1.pret_total_cos = this->pret_total_cos + cos2.pret_total_cos;

    for (int i = 0; i < this->prod_total_cos; i++)
        cos1.nume_produse.push_back(this->nume_produse[i]);
    for (int i = 0; i < cos2.prod_total_cos; i++)
        cos1.nume_produse.push_back(cos2.nume_produse[i]);
    return cos1;
}
//operator /
//calculeaza in medie pretul unui produs din cele 2 cosuri
Cos Cos::operator/(Cos cos2)
{
    Cos cos1 = *this;
    cos1.prod_total_cos = this->prod_total_cos + cos2.prod_total_cos;
    cos1.pret_total_cos = (this->pret_total_cos + cos2.pret_total_cos) / cos1.prod_total_cos;
    for (int i = 0; i < this->prod_total_cos; i++)
        cos1.nume_produse.push_back(this->nume_produse[i]);
    for (int i = 0; i < cos2.prod_total_cos; i++)
        cos1.nume_produse.push_back(cos2.nume_produse[i]);
    return cos1;
}

//operatorul cast explicit sau implicit
Cos::operator double() {
    return this->pret_total_cos;
}

//operator <=
// verificam daca pretul total al primului cos e mai mic/egal decat al celui de-al doilea 
bool Cos::operator<=(const Cos& cos)
{
    if (this->pret_total_cos <= cos.pret_total_cos)
        return true;
    return false;
}

//operator ==
// verificam daca cosurile au acelasi nr de produse
bool Cos::operator==(const Cos& cos)
{
    if (this->prod_total_cos == cos.prod_total_cos)
        return true;
    return false;
}
