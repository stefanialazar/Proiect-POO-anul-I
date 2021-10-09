#ifndef COS_H
#define COS_H
#include <iostream>
#include <string>
#include <vector>
#include "Haine.h"
#include "Incaltaminte.h"


//la clasa Cos am modificat unele lucruri deoarece am adaugat toate_hainele si toate_incal, pentru a exemplifica
//conceptul de HAS A
class Cos
{
    std::vector <Haine> toate_hainele; //HAS A
    std::vector <Incaltaminte> toate_incal; //HAS A

    int prod_total_cos; //cate produse sunt in cos
    double pret_total_cos; //pretul total din cos
    std::vector <std::string> nume_produse; //contine numele produselor din cos
    char* nume_client; //numele clientului

public:
    Cos& adauga_haina(Haine h);
    Cos& elimina_haina(Haine h);
    Cos& adauga_incal(Incaltaminte incal);
    Cos& elimina_incal(Incaltaminte incal);

    std::vector <Haine> getToate_hainele();
    std::vector <Incaltaminte> getToate_incal();

    void setNume_produse(std::vector <std::string> nume_produse, int prod_total_cos);
    std::vector <std::string> getNume_produse();

    void setProd_cos(int prod_total_cos);
    int getProd_cos();

    void setTotal_cos(double pret_total_cos);
    double getTotal_cos();

    void setNumeclient(char* nume_client);
    char* getNumeclient();

    Cos(int prod_total_cos, double pret_total_cos, std::vector <std::string> nume_produse, char* nume_client);
    Cos(int prod_total_cos, double pret_total_cos);
    Cos();
    ~Cos();
    Cos(const Cos& cos);
    Cos operator=(Cos cos);
    friend std::ostream& operator<<(std::ostream& out, Cos& cos);
    friend std::istream& operator>>(std::istream& in, Cos& cos);
    int operator[](int index);
    const Cos& operator++();  //pre-incrementare
    const Cos operator++(int); //post-incrementare
    Cos operator+(Cos cos2);
    Cos operator/(Cos cos2);
    operator double();
    bool operator<=(const Cos& cos);
    bool operator==(const Cos& cos);
}; 

#endif