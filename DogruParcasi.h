#pragma once
#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H

#include "Nokta.h"

class DogruParcasi {
private:
    Nokta nokta1;
    Nokta nokta2;
public:
    DogruParcasi(const Nokta& nokta1, const Nokta& nokta2);
    DogruParcasi(const DogruParcasi& dogruParcasi);
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

    Nokta getP1() const;
    Nokta getP2() const;
    void setP1(const Nokta& nokta1);
    void setP2(const Nokta& nokta2);
    void setP1(double x, double y);
    void setP2(double x, double y);

    double uzunluk() const;
    Nokta kesisimNoktasi(const Nokta& nokta) const;
    Nokta ortaNokta() const;

    std::string toString() const;
    void yazdir() const;
};

#endif // DOGRUPARCASI_H
