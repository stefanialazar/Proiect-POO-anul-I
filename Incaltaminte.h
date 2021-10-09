#ifndef INCALTAMINTE_H
#define INCALTAMINTE_H
#include <iostream>
#include "Produse.h"
#include <string>
#include <string.h>


enum tip_de_incalt { Tip_necunoscut, Adidasi, Sandale, Pantofi, Pantofi_cu_toc, Ghete, Bocanci, Papuci };//toate tipurile de incaltaminte
enum culori_incalt { Culoare_necunoscuta1, Negru1, Alb1, Rosu1, Albastru1, Galben1, Verde1, Gri1, Violet1, Roz1, Maro1 };

class Incaltaminte: public Produse, public Welcome
{
    static int stoc; //stocul total de incaltaminte

    tip_de_incalt tip;
    culori_incalt culoare;
    float marime;

public:
    void welcome();

    static int getStoc();

    void setTip(tip_de_incalt  tip);
    std::string getTip();

    void setCuloare(culori_incalt culoare);
    std::string getCuloare();

    std::string conversieTipdeincalt(tip_de_incalt tip);
    std::string conversieCuloriincalt(culori_incalt culoare);

    float getMarime();

    void alege_task();

    void afisareTipdeincalt();
    void afisareCuloriincalt();
    Incaltaminte(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret,
        int nrVarste, int* varste, char gen, int nrtip, float marime, int nrculoare);
    Incaltaminte(bool eco, int adaugate_cos, int nrMateriale, std::string* materiale, float pret, int nrVarste, int* varste, char gen, int nrtip, float marime);
    Incaltaminte();
    ~Incaltaminte();
    Incaltaminte(const Incaltaminte& incal);
    Incaltaminte operator=(Incaltaminte incal);
    friend std::ostream& operator<<(std::ostream& out, Incaltaminte& h);
    friend std::istream& operator>>(std::istream& in, Incaltaminte& h);

};


#endif
