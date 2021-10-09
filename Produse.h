#ifndef PRODUSE_H
#define PRODUSE_H
#include <iostream>
#include <string>
#include <string.h>

// clasa ProduseTVA este o clasa abstracta ce calculeaza pretul final cu TVA
class ProduseTVA
{
protected:
    float pret;

public:
    virtual float calc_pret_cu_TVA() = 0;
    
};

//clasa Welcome este o interfata 
class Welcome
{
public:
    virtual void welcome() {
        std::cout << "Welcome to Ivy Lakes!" << std::endl;
    }
    virtual void alege() {
        std::cout << "Alegeti daca sunteti user sau administrator: " << std::endl;
        std::cout << "1. administrator" << std::endl;
        std::cout << "2. user" << std::endl;
        std::cout << "3. exit" << std::endl;
    }
    virtual void task_admin() {
        std::cout << std::endl << "Selectati un task:" << std::endl;
        std::cout << "1. Sa vizionez toate tipurile de haine" << std::endl;
        std::cout << "2. Sa vizionez toate tipurile de incaltaminte" << std::endl;
        std::cout << "3. Adaug produse" << std::endl;
        std::cout << "4. Elimin produse" << std::endl;
        std::cout << "5. Schimb pretul unui produs" << std::endl;
        std::cout << "6. Adaug perioada de reduceri" << std::endl;
        std::cout << "7. Sa vizionez perioadele de reduceri" << std::endl;
        std::cout << "8. Adaug perioada in care magazinul este inchis" << std::endl;
        std::cout << "9. Sa vizionez perioadele cand este inchis magazinul" << std::endl;
        std::cout << "10. Adaug anunturi pentru angajare" << std::endl;
        std::cout << "11. Sa vizionez anunturile de angajare" << std::endl;
        std::cout << "12. Sa vizionez toate cosurile de cumparaturi de pana acum" << std::endl;
        std::cout << "13. Mi-am indeplinit task-urile, doresc sa ies din magazin" << std::endl;
    }
    virtual void task_user() {
        std::cout << std::endl << "Selectati un task:" << std::endl;
        std::cout << "1. Sa vizionez toate tipurile de haine" << std::endl;
        std::cout << "2. Sa vizionez toate tipurile de incaltaminte" << std::endl;
        std::cout << "3. Sa vad toate articolele din cos si pretul total al articolelor" << std::endl;
        std::cout << "4. Sa vizionez perioadele de reduceri" << std::endl;
        std::cout << "5. Sa vizionez perioadele cand este inchis magazinul" << std::endl;
        std::cout << "6. Sa elimin articole din cos" << std::endl;
        std::cout << "7. Sa vizionez anunturile de angajare" << std::endl;
        std::cout << "8. Sa cumpar articolele selectate, sa primesc bonul fiscal si sa parasesc magazinul" << std::endl;
        std::cout << "9. Sa renunt la cosul de cumparaturi si sa parasesc magazinul" << std::endl;
    }
};


class Produse: public ProduseTVA
{
    static const std::string nume_magazin;
    static int nrProd;
    const int id_produs; //id-ul propriu al unui produs
    bool eco; //1 daca produsul este eco-friendly/sustainable, 0 daca nu
    int adaugate_cos; //numarul de articole dintr-un anumit produs adaugat in cos
    int nrMateriale;
    std::string* materiale; //materialele din care este facut un produs
    int nrVarste;
    int* varste; //varsetele care se potrivesc produsului
    char gen; // F - female, M - male, U - unisex

public:
    float calc_pret_cu_TVA();

    std::string getNume_magazin();
    int getNr_prod();
    int getId_produs();

    void setEco(bool eco);
    bool getEco();

    void setAdaugate_cos(int adaugate_cos);
    int getAdaugate_cos();

    void setNrmateriale(int nrMateriale);
    int getNrmateriale();

    void setMateriale(std::string* materiale, int nrMateriale);
    std::string* getMateriale();

    void setPret(float pret);
    float getPret();

    void setNrvarste(int nrVarste);
    int getNrvarste();

    void setVarste(int* varste, int nrVarste);
    int* getVarste();

    void setGen(char gen);
    char getGen();

    void stergeProdus(Produse& prod);

    Produse(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, int nrVarste, int* varste, char gen);
    Produse(int nrMateriale, std::string* materiale, int nrVarste, int* varste);
    Produse();
    ~Produse();
    Produse(const Produse& prod);
    Produse operator=(Produse prod);
    friend std::ostream& operator<<(std::ostream& out, Produse& prod);  // operator afisare
    friend std::istream& operator>>(std::istream& in, Produse& prod);  //operator citire
    friend std::ifstream& operator>>(std::ifstream& in, Produse& prod); // operator citire DIN FISIER !!

    void citireFisier(std::ifstream& fisier);

    int operator[](int index);
    const Produse& operator++();  //pre-incrementare
    const Produse operator++(int); //post-incrementare
    const Produse& operator--(); //pre-incrementare
    const Produse operator--(int); //post-incrementare
    Produse operator+(Produse prod);
    Produse operator-(Produse& prod2);
    operator int();
    /*   explicit operator std::string();*/
    bool operator>(const Produse& prod);
    bool operator==(const Produse& prod);

}; 

#endif