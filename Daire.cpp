#include "Daire.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

Daire::Daire(const Daire& daire) : merkez(daire.merkez), yaricap(daire.yaricap) {}

Daire::Daire(const Daire& daire, double x) {
    if (x < 0) {
        x = (-1.0) * x;
    }
    setMerkez(daire.merkez);
    setYaricap(daire.yaricap * x);
}

Nokta Daire::getMerkez() const {
    return merkez;
}

double Daire::getYaricap() const {
    return yaricap;
}

void Daire::setMerkez(const Nokta& merkez) {
    this->merkez = merkez;
}

void Daire::setYaricap(double yaricap) {
    this->yaricap = yaricap;
}

void Daire::setMerkez(double x, double y) {
    merkez.set(x, y);
}

double Daire::alan() const {
    return M_PI * pow(getYaricap(), 2);
}

double Daire::cevre() const {
    return 2 * M_PI * getYaricap();
}

int Daire::kesisim(const Daire& daire) const {
    double merkezlerArasiMesafe = sqrt(pow(getMerkez().getX() - daire.getMerkez().getX(), 2) + pow(getMerkez().getY() - daire.getMerkez().getY(), 2));

    if (merkezlerArasiMesafe + daire.getYaricap() < getYaricap()) {
        return 0;
    }
    else if (merkezlerArasiMesafe < getYaricap() + daire.getYaricap()) {
        return 1;
    }
    else {
        return 2;
    }
}

std::string Daire::toString() const {
    return getMerkez().toString() + " - " + std::to_string(getYaricap());
}

void Daire::yazdir() const {
    std::cout << toString() << std::endl;
}
