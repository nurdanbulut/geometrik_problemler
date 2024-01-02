#pragma once
#ifndef UCGEN_H
#define UCGEN_H

#include "Nokta.h"
#include "DogruParcasi.h"

class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;
public:
    Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

    Nokta getNokta1() const;
    Nokta getNokta2() const;
    Nokta getNokta3() const;
    void setNokta1(const Nokta& nokta1);
    void setNokta2(const Nokta& nokta2);
    void setNokta3(const Nokta& nokta3);
    void setNokta1(double x, double y);
    void setNokta2(double x, double y);
    void setNokta3(double x, double y);

    std::string toString() const;
    double alan() const;
    double cevre() const;
    double* acilar() const;
};

#endif // UCGEN_H
