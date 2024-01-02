#pragma once
#ifndef DAIRE_H
#define DAIRE_H

#include "Nokta.h"

class Daire {
private:
    Nokta merkez;
    double yaricap;
public:
    Daire(const Nokta& merkez, double yaricap);
    Daire(const Daire& daire);
    Daire(const Daire& daire, double x);

    Nokta getMerkez() const;
    double getYaricap() const;
    void setMerkez(const Nokta& merkez);
    void setYaricap(double yaricap);
    void setMerkez(double x, double y);

    double alan() const;
    double cevre() const;
    int kesisim(const Daire& daire) const;

    std::string toString() const;
    void yazdir() const;
};

#endif // DAIRE_H

