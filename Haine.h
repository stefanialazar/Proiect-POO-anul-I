#ifndef HAINE_H
#define HAINE_H
#include <iostream>
#include "Produse.h"
#include <string>
#include <string.h>


enum tip_de_haine { Tip_de_haine_necunoscut, Jacheta, Palton, Sacou, Pulover, Cardigan, Vesta, Tricou, Camasa, Bluza, Pantaloni, Blugi, Rochie, Fusta, Lenjerie, Costum_de_baie };
enum marimi { Marime_necunoscuta, XXS, XS, S, M, L, XL, XXL, XXXL };
enum culori { Culoare_necunoscuta, Negru, Alb, Rosu, Albastru, Galben, Verde, Gri, Violet, Roz, Maro };

class Haine: public Produse, public Welcome
{
    static int stoc; //stocul total de haine

    tip_de_haine tip;
    marimi marime;
    culori culoare;

public:
    void welcome();

    static int getStoc();

    void setTip(tip_de_haine  tip);
    std::string getTip();

    void setMarime(marimi marime);
    std::string getMarime();

    void setCuloare(culori culoare);
    std::string getCuloare();

    std::string conversieTipdehaine(tip_de_haine tip);
    std::string conversieMarimi(marimi marime);
    std::string conversieCulori(culori culoare);

    void afisareTipdehaine();
    void afisareMarimi();
    void afisareCulori();
    void alege_task();

    Haine(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, int nrVarste, int* varste, char gen, int nrtip, int nrmarime, int nrculoare);
    Haine(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, int nrVarste, int* varste, char gen, int nrtip, int nrmarime);
    Haine();
    ~Haine();
    Haine(const Haine& h);
    Haine operator=(Haine h);
    friend std::ostream& operator<<(std::ostream& out, Haine& h);
    friend std::istream& operator>>(std::istream& in, Haine& h);
}; 

#endif